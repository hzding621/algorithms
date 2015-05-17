import java.util.*;

public class TreeNode {
	int val = 0;
	TreeNode left = null;
	TreeNode right = null;
	TreeNode(int x) { val = x ;}

	TreeNode(String tree) {

		if (!tree.matches("(-{0,1}\\d+)(\\s((-{0,1}\\d+)|\\*))*"))
			throw new IllegalTreeEncoding();

		String[] nodes = tree.split(" ");
		Stack<TreeNode> stack = new Stack<TreeNode>();
		Stack<Integer> ordStack = new Stack<Integer>();
		
		this.val = Integer.parseInt(nodes[0]);
		stack.push(this);
		ordStack.push(0);
		for (int i=1; i<nodes.length; i++) {

			String token = nodes[i];
			if (token.equals("*")) {

				if (ordStack.empty())
					throw new IllegalTreeEncoding();

				if (ordStack.peek() == 0)
					ordStack.push(ordStack.pop()+1);
				else {
					while (!ordStack.empty() && ordStack.peek() == 1) {
						ordStack.pop();
						stack.pop();
					}
					if (!ordStack.empty()) {
						ordStack.push(ordStack.pop()+1);
					}
				}
			} 
			else {
				int v = Integer.parseInt(token);
				TreeNode n = new TreeNode(v);
				if (ordStack.peek() == 0)
					stack.peek().left = n;
				else
					stack.peek().right = n;
				stack.push(n);
				ordStack.push(0);
			}
		}
		if (stack.size() != ordStack.size()) 
			throw new IllegalTreeEncoding();
		else if (stack.size() > 0)
			throw new IllegalTreeEncoding();
	}

	void print() {
		TreeNodePrinter.printNode(this);
	}

	public static TreeNode buildTreeInPost(int[] inorder, int[] postorder) {
		return InorderPostorderTree.build(inorder, postorder);
	}
	public static TreeNode buildTreePreIn(int[] preorder, int[] inorder) {
		return PreorderInorderTree.build(preorder, inorder);
	}
}

class TreeNodePrinter{

	public static void printNode(TreeNode root) {
		int maxLevel = maxLevel(root);

		printNodeInternal(Collections.singletonList(root), 1, maxLevel);
	}

	private static void printNodeInternal(List<TreeNode> nodes, int level, int maxLevel) {
		if (nodes.isEmpty() || isAllElementsNull(nodes))
			return;

		int floor = maxLevel - level;
		int endgeLines = (int) Math.pow(2, (Math.max(floor - 1, 0)));
		int firstSpaces = (int) Math.pow(2, (floor)) - 1;
		int betweenSpaces = (int) Math.pow(2, (floor + 1)) - 1;

		printWhitespaces(firstSpaces);

		List<TreeNode> newNodes = new ArrayList<TreeNode>();
		for (TreeNode node : nodes) {
			if (node != null) {
				System.out.print(node.val);
				newNodes.add(node.left);
				newNodes.add(node.right);
			} else {
				newNodes.add(null);
				newNodes.add(null);
				System.out.print(" ");
			}

			printWhitespaces(betweenSpaces);
		}
		System.out.println("");

		for (int i = 1; i <= endgeLines; i++) {
			for (int j = 0; j < nodes.size(); j++) {
				printWhitespaces(firstSpaces - i);
				if (nodes.get(j) == null) {
					printWhitespaces(endgeLines + endgeLines + i + 1);
					continue;
				}

				if (nodes.get(j).left != null)
					System.out.print("/");
				else
					printWhitespaces(1);

				printWhitespaces(i + i - 1);

				if (nodes.get(j).right != null)
					System.out.print("\\");
				else
					printWhitespaces(1);

				printWhitespaces(endgeLines + endgeLines - i);
			}

			System.out.println("");
		}

		printNodeInternal(newNodes, level + 1, maxLevel);
	}

	private static void printWhitespaces(int count) {
		for (int i = 0; i < count; i++)
			System.out.print(" ");
	}

	private static int maxLevel(TreeNode node) {
		if (node == null)
			return 0;

		return Math.max(maxLevel(node.left), maxLevel(node.right)) + 1;
	}

	private static boolean isAllElementsNull(List<TreeNode> list) {
		for (Object object : list) {
			if (object != null)
				return false;
		}

		return true;
	}

}

class IllegalTreeEncoding extends IllegalArgumentException {
	IllegalTreeEncoding() {
		super();
	}
}

class InorderPostorderTree {

	public static TreeNode build(int[] inorder, int[] postorder) {
		HashSet<Integer> nums = new HashSet<Integer>();
		for (int i: inorder) {
			if (nums.contains(i))
				throw new IllegalTreeEncoding();
			else
				nums.add(i);
		}
		return buildTree(inorder, postorder);
	}

	static TreeNode buildTreeHelper(int[] inorder, int i1, int i2, int[] postorder, int p1, int p2, HashMap<Integer, Integer> mapping1, HashMap<Integer, Integer> mapping2) {

		// System.out.println("i: "+i1+","+i2+" p: "+p1+","+p2);

		if (i1 == i2)
			return new TreeNode(inorder[i1]);
		else if (i1 > i2)
			return null;

		TreeNode root = new TreeNode(postorder[p2]);
		int ir = mapping2.get(p2);
		if (ir != i1 && ir == i2) {
			// has left subtree but no right subtree
			root.left = buildTreeHelper(inorder, i1, ir-1, postorder, p1, p2-1, mapping1, mapping2);
		}
		else if (ir != i2 && ir == i1) {
			// has right subtree but no left subtree
			root.right = buildTreeHelper(inorder, ir+1, i2, postorder, p1, p2-1, mapping1, mapping2);
		} else {
			// must be the case having both subtrees
			
			int rp1 = p2-1;
			for (int i=ir+1; i<=i2; i++) {
				int p = mapping1.get(i);
				rp1 = Math.min(rp1, p);
			}
			int lp2 = rp1 - 1;

			root.left = buildTreeHelper(inorder, i1, ir-1, postorder, p1, lp2, mapping1, mapping2);
			root.right = buildTreeHelper(inorder, ir+1, i2, postorder, rp1, p2-1, mapping1, mapping2);
		}

		return root;
	}

	static TreeNode buildTree(int[] inorder, int[] postorder) {

		// Assume distinct elements
		if (inorder.length != postorder.length)
			throw new IllegalTreeEncoding();
		
		HashMap<Integer, Integer> mapping1 = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> mapping2 = new HashMap<Integer, Integer>();
		for (int i=0; i<inorder.length; i++) {
			int n = inorder[i];
			for (int j=0; j<postorder.length; j++) {
				if (postorder[j] == n) {
					mapping1.put(i, j);
					mapping2.put(j, i);
					break;
				}
			}
			if (!mapping1.containsKey(i))
				throw new IllegalTreeEncoding(); // invalid input
		}

		// System.out.println("Begin building tree...");
		return buildTreeHelper(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1, mapping1, mapping2);
	}


}

class PreorderInorderTree {

	public static TreeNode build(int[] preorder, int[] inorder) {
		HashSet<Integer> nums = new HashSet<Integer>();
		for (int i: preorder) {
			if (nums.contains(i))
				throw new IllegalTreeEncoding();
			else
				nums.add(i);
		}
		return buildTree(preorder, inorder);
	}

	static TreeNode buildTreeHelper(int[] preorder, int p1, int p2, int[] inorder, int i1, int i2, HashMap<Integer, Integer> mapping1, HashMap<Integer, Integer> mapping2) {
		if (i1 == i2) {
			return new TreeNode(inorder[i2]);
		} else if (i1 > i2)
			return null;

		TreeNode root = new TreeNode(preorder[p1]);
		int ir = mapping1.get(p1);
		if (ir != i1 && ir == i2) {
			// has left subtree but no right subtree
			root.left = buildTreeHelper(preorder, p1+1, p2, inorder, i1, ir-1, mapping1, mapping2);
		} else if (ir != i2 && ir == i1) {
			// has right subtree but no left subtree
			root.right = buildTreeHelper(preorder, p1+1, p2, inorder, ir+1, i2, mapping1, mapping2);
		} else {
			// must be the case having both subtrees

			int rp1 = p2;
			for (int i=ir+1; i<=i2; i++) {
				int p = mapping2.get(i);
				rp1 = Math.min(rp1, p);
			}
			int lp2 = rp1 - 1;

			root.left = buildTreeHelper(preorder, p1+1, lp2, inorder, i1, ir-1, mapping1, mapping2);
			root.right = buildTreeHelper(preorder, rp1, p2, inorder, ir+1, i2, mapping1, mapping2);

		}

		return root;
	}

	static TreeNode buildTree(int[] preorder, int[] inorder) {
        
        // Assume distinct elements
		if (inorder.length != preorder.length)
			throw new IllegalTreeEncoding();
		
		HashMap<Integer, Integer> mapping1 = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> mapping2 = new HashMap<Integer, Integer>();
		for (int i=0; i<preorder.length; i++) {
			for (int j=0; j<inorder.length; j++) {
				if (inorder[j] == preorder[i]) {
					mapping1.put(i,j);
					mapping2.put(j,i);
					break;
				}
			}
			if (!mapping1.containsKey(i))
				throw new IllegalTreeEncoding(); // invalid input
		}

		return buildTreeHelper(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1, mapping1, mapping2);
    }

}