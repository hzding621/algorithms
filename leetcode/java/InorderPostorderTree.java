import java.util.*;

public class InorderPostorderTree {

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

	public static TreeNode buildTree(int[] inorder, int[] postorder) {

		// Assume distinct elements
		if (inorder.length != postorder.length)
			return null;
		
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
				return null; // invalid input
		}

		// System.out.println("Begin building tree...");
		return buildTreeHelper(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1, mapping1, mapping2);
	}


	public static void main(String[] args) {
		int[] in = {1,2,3,4,5};
		int[] post = {2,1,5,4,3};
		TreeNode n = buildTree(in, post);
		n.print();
	}
}