// https://oj.leetcode.com/problems/container-with-most-water/

public class MaxContainer {

	public static int maxArea(int[] height) {
		int i = 0;
        int j = height.length - 1;
        int maxArea = 0;
        while ( i < j) {
            maxArea = Math.max(maxArea, Math.min(height[i], height[j]) * (j-i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
	}
}