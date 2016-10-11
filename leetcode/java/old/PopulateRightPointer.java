import java.util.*;

public class PopulateRightPointer {
	static class TreeLinkNode{
		int val;
		TreeLinkNode left, right, next;
		TreeLinkNode(int x) { val = x; }
	}

	public static void connect(TreeLinkNode root) {
		if (root == null)
			return;

        ArrayList<TreeLinkNode> current = new ArrayList<TreeLinkNode>();
        
        current.add(root);

        while (!current.isEmpty()) {
            
        	
        	for (int i=1; i<current.size(); i++) {
        		current.get(i-1).next = current.get(i);
        	}
        	current.get(current.size()-1).next = null;

            ArrayList<TreeLinkNode> next = new ArrayList<TreeLinkNode>();
        	for (TreeLinkNode n: current) {

        		if (n.left != null)
        			next.add(n.left);
        		if (n.right != null)
        			next.add(n.right);
        	}
        	current = next;
        }
        return;

    }
}