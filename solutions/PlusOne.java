public class PlusOne {

	public boolean checkAllNine(int[] digits) {
		for (int i=0; i<digits.length; i++)
			if (digits[i] != 9)
				return false;
		return true;
	}
	
	public int[] plusOne(int[] digits) {
		if (checkAllNine(digits)) {
			int[] answer = new int[digits.length+1];
			answer[0] = 1;
			return answer;
		}
		
		if (digits[digits.length-1] == 9) {
			digits[digits.length-1]  = 0;
		}
		else {
			digits[digits.length-1] = digits[digits.length-1] + 1;
			return digits;
		}
			
		
		for (int i=digits.length-2; i>=0; i--) {
			int d = digits[i];
			if (d == 9) {
				digits[i] = 0;
			} else {
				digits[i] = d + 1;
				return digits;
			}
		}
		
		return new int[] {}; // should never reach here
	}
	
}