import java.util.*;

public class LowestCommonAncestor {
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int ret;
        while ((ret = isSameSide(root, p, q)) != 0) {
            if (ret > 0)
                root = root.right;
            else
                root = root.left;
        }
        return root;
    }

    public static int isSameSide(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val < p.val && root.val < q.val)
            return 1;
        else if (root.val > p.val && root.val > q.val)
            return -1;
        else
            return 0;
    }

    public static void main(String[] args) {
        TreeNode n = TreeNode.buildTreePreIn(new int[]{6,2,0,4,3,5,8,7,9}, new int[]{0,2,3,4,5,6,7,8,9});
        TreeNode p = n.left, q = n.left.right;
        System.out.println(lowestCommonAncestor(n, p, q).val);
    }
}
