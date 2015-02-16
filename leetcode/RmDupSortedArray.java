// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

public class RmDupSortedArray {
	
    public static int removeDuplicates(int[] A) {
        if (A.length < 2)
            return A.length;
        
        int readHead = 0, value;
        int writeHead = 0;
        
        while (true) {
            value = A[readHead];
            while (readHead < A.length-1 && A[readHead+1] == value) {
                readHead++;
            }
            
            A[writeHead] = value;
            if (readHead == A.length-1)
                break;
            writeHead++;
            readHead++;
        }
        return writeHead + 1;
        
    }
}
