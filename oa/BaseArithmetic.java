import java.io.*;
import java.util.*;
import java.math.*;

public class BaseArithmetic {
		
	public static char largestDigit(int base) {
		if (base <= 10) {
			return (char)(base - 1 + '0');
		}
		else {
			return (char)(base - 11 + 'a');
		}
	}    

	public static int getVal(char c) {
		if (c >= '0' && c <= '9')
			return (int)(c-'0');
		else 
			return (int)(c-'a'+10);
	}
		
	public static boolean validDigit(char c, char bound) {
		if (bound <= '9')
			return (c >= '0' && c <= bound);
		else
			return (c >= '0' && c <= '9') || ( c >= 'a' && c <= bound);
	}
	   
	public static void main(String args[] ) throws Exception {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */
		Scanner stdin = new Scanner(System.in);
		int base = stdin.nextInt();
		if (base < 2 || base > 36) {
			System.out.println("base invalid");
			System.exit(0);
		}
		
		String number = stdin.next();
		char bound = largestDigit(base);
		BigInteger numberVal = new BigInteger("0");
		BigInteger baseBig = new BigInteger("" + base);
		// System.out.println(baseBig.toString());
		for (int j = 0; j<number.length(); j++) {
			
			char c = number.charAt(j);
			if (validDigit(c, bound) == false) {
				System.out.println("number invalid");
				System.exit(0);
			}
			 
			BigInteger digitValue = new BigInteger("" + getVal(c));
			System.out.println(digitValue.toString()); 

			numberVal = numberVal.multiply(baseBig);
			numberVal = numberVal.add(digitValue);
			// System.out.println(numberVal.toString());
		}
		System.out.println(numberVal.toString());
		
	}
}