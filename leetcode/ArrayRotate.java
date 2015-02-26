import java.util.*;

public class ArrayRotate {

	public static void rotate(int[] nums, int k) {
        ArrayDeque<Integer> q = new ArrayDeque<Integer>();
        for (int i=0; i<nums.length; i++)
            q.addLast(nums[i]);
        for (int j=0; j<k; j++)
            q.addFirst(q.removeLast());
        for (int m=0; m<nums.length; m++)
            nums[m] = q.removeFirst();
    }

    public static void main(String[] args) {
    	int[] nums = new int[]{1,2,3,4,5,6,7};
    	rotate(nums, 3);
    	Helpers.print(nums);
    }

}