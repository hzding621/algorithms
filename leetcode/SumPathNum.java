/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 
public class SumPathNum {
    
    public class IntWrapper {
        int n = 0;
        public IntWrapper(int n) { this.n=n; }
        public int getNum() { return this.n; }
        public void setNum(int n) { this.n = n; }
    } 
    
    public int sumNumbers(TreeNode root) {
        IntWrapper sum = new IntWrapper(0);
        List<Integer> path = new ArrayList<Integer>();
        traverse(root, path, sum);
        return sum.getNum();
    }
    
    public void traverse(TreeNode root, List<Integer> path, IntWrapper sum) {
        if (root == null)
            return;
        
        path.add(root.val);
        if (root.left == null && root.right == null) {
            int number = pathToInt(path);
            int storedNum = sum.getNum();
            sum.setNum(storedNum + number);
        }
        else {
            traverse(root.left, path, sum);
            traverse(root.right, path, sum);
        }
        path.remove(path.size()-1);
    }
    
    public int pathToInt(List<Integer> path) {
        int sum = 0;
        for (int digit : path) {
            sum = sum * 10 + digit;
        }
        return sum;
    }
    
}