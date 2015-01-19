/* https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ */

public class Test4_3 {
	public static TreeNode sortedArrayToBST(int[] num) {
        return sortedArrayToBST(num, 0, num.length-1);
    }
    
    static TreeNode sortedArrayToBST(int[] num, int start, int end) {
        if (start > end)
            return null;
        int mid = (start + end) / 2;
        TreeNode node = new TreeNode(num[mid]);
        node.left = sortedArrayToBST(num, start, mid-1);
        node.right = sortedArrayToBST(num, mid+1, end);
        return node;
    }
}