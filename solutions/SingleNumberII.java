// https://oj.leetcode.com/problems/single-number-ii/

// Given an array of integers, every element appears three times,
// except for one, which appears only once
// Find that single one.

// The idea is to keep track of all those appears once, twice, and thrice.

public class SingleNumberII {

	public static int singleNumber(int[] A) {
        int ones=0, twos=0, threes=0;
        for (int i=0; i<A.length; i++) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }


}