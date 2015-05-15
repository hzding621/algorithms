import java.util.*;

public class PreorderInorderTree {

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

	public static TreeNode buildTree(int[] preorder, int[] inorder) {
        
        // Assume distinct elements
		if (inorder.length != preorder.length)
			return null;
		
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
				return null; // invalid input
		}

		return buildTreeHelper(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1, mapping1, mapping2);
    }

	public static void main(String[] args) {
		int[] pre = {1,2,3,4,5,6,7};
		int[] in = {3,2,4,1,6,5,7};
		TreeNode n = buildTree(pre, in);
		n.print();
	}
}