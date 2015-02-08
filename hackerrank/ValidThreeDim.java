import java.io.*;
import java.util.*;
import java.math.*;

public class ValidThreeDim {
		
	public static boolean solve(int a_size) {

		if (a_size < 8)
				return false;
			
		boolean[] table = new boolean[a_size+1];
		// false if prime and true if even
		table[1] = false;
		table[2] = false;
		for (int j=2; j<=a_size; j++) {
			if (table[j] == false) {
				int factor = 2;
				while (j * factor <= a_size) {
					table[j * factor] = true;
					factor++;
				}
			}
		}
		for (int j=4; j<a_size; j++) {
			if (table[j] == true && (a_size % j == 0) )
				return true;
		}
		return false;


	}
	   
	public static void main(String args[] ) throws Exception {
		
		int[] array = new int[] {8,10,12,15,18,20,21};
		for (int j=0; j<array.length; j++) {
			System.out.println(array[j] + " " + solve(array[j]));
		}

	}
}