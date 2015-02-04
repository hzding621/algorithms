/* https://oj.leetcode.com/problems/validate-binary-search-tree/ */

public class Test4_5 {
	public static boolean isValidBST(TreeNode root) {
        ArrayList<Integer> array = new ArrayList<Integer>();
        checkValidBST(root, array);
        for (int i=0; i<array.size()-1; i++) {
            if (array.get(i)>=array.get(i+1))
                return false;
        }
        return true;
    }
    
    static void checkValidBST(TreeNode node, ArrayList<Integer> array) {
        if (node != null) {
            checkValidBST(node.left, array);
            array.add(node.val);
            checkValidBST(node.right, array);
        }
    }
}