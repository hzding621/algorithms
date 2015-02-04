public class MaxSubarrayProduct {

	public static int maxProduct(int[] A) {
        
        int[] maxUntil = new int[A.length];
        int[] minUntil = new int[A.length];
        
        maxUntil[0] = A[0];
        minUntil[0] = A[0];
        
        for (int i=1; i<A.length; i++) {
            int maxUntilLast = maxUntil[i-1];
            int minUntilLast = minUntil[i-1];
            int max = A[i];
            if (A[i] > 0 && maxUntilLast > 0)
                max = Math.max(max, A[i] * maxUntilLast);
            else if (A[i] < 0 && minUntilLast < 0)
                max = Math.max(max, A[i] * minUntilLast);
            int min = A[i];
            if (A[i] > 0 && minUntilLast < 0)
                min = Math.min(min, A[i] * minUntilLast);
            else if (A[i] < 0 && maxUntilLast > 0)
                min = Math.min(min, A[i] * maxUntilLast);
            maxUntil[i] = max;
            minUntil[i] = min;
        }
        
        int allMax = A[0];
        for (int i=1; i<A.length; i++) {
            allMax = Math.max(allMax, maxUntil[i]);
        }
        return allMax;
    }
}