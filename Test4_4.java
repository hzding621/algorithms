/* https://oj.leetcode.com/problems/binary-tree-level-order-traversal/ */

import java.util.*;

public class Test4_4 {
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        ArrayList<TreeNode> current = new ArrayList<TreeNode>(), parents;
        if (root != null) {
            current.add(root);
        }
        
        while (!current.isEmpty()) {
            
            ArrayList<Integer> res = new ArrayList<Integer>();
            for (TreeNode n: current) {
                res.add(n.val);
            }
            result.add(res);
            
            parents = current;
            current = new ArrayList<TreeNode>();
            for (TreeNode n: parents) {
                if (n.left != null)
                    current.add(n.left);
                if (n.right != null)
                    current.add(n.right);
            }
        }
        return result;
            
    }
}