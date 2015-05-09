public class Solution {
    
    
    List<List<Integer>> combinationSumHelper(int[] candidates, int target, int index) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (target == 0) {
            ret.add(new ArrayList<Integer>());
        }
        else if (target > 0) {
            for (int i=0; i<=index; i++) {
                
                List<List<Integer>> partial = combinationSumHelper(candidates, target - candidates[i], i);
                for (List<Integer> l : partial) {
                    l.add(candidates[i]);
                    ret.add(l);
                }
            }
        }
        return ret;
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return combinationSumHelper(candidates, target, candidates.length-1);
    }
}