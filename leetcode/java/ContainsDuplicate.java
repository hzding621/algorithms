import java.util.*;

public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hash = new HashSet<Integer>();
        for (int n: nums) {
            if (!hash.add(n))
                return true;
        }
        return false;
    }

    public static void main(String[] args) {

    }
}