import java.util.*;

public class TreeNode {
	int val = 0;
	TreeNode left = null;
	TreeNode right = null;
	TreeNode(int x) { val = x ;}
	TreeNode(String tree) {

		if (!tree.matches("\\d+(\\s(\\d+|\\*))*"))
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