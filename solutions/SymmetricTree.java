public class SymmetricTree {

	static TreeNode cloneMirror(TreeNode root) {
        if (root == null)
            return null;
        
        TreeNode newRoot = new TreeNode(root.val);
        newRoot.left = cloneMirror(root.left);
        newRoot.right = cloneMirror(root.right);
        return newRoot;
    }
    
    static boolean isSymmetric(TreeNode a, TreeNode b) {
        
        if (a == null && b == null)
            return true;
        if (a == null || b == null)
            return false;
            
        if (a.val != b.val )
            return false;
        
        return isSymmetric(a.left, b.right) && isSymmetric(a.right, b.left);   
        
    }
    
    static public boolean isSymmetric(TreeNode root) {
        TreeNode mirror = cloneMirror(root);
        return isSymmetric(root, mirror);
    }

}