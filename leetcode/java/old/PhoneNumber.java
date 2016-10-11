import java.util.*;

public class PhoneNumber {


    static HashMap<Integer, ArrayList<Character>> table = null;
    
    public static void preprocess() {
        if (table == null) {
            table = new HashMap<Integer, ArrayList<Character>>();
            ArrayList<Character> two = new ArrayList<Character>();
            two.add('a'); two.add('b'); two.add('c');
            table.put(2, two);
            ArrayList<Character> three = new ArrayList<Character>();
            three.add('d'); three.add('e'); three.add('f');
            table.put(3, three);
            ArrayList<Character> four = new ArrayList<Character>();
            four.add('g'); four.add('h'); four.add('i');
            table.put(4, four);
            ArrayList<Character> five = new ArrayList<Character>();
            five.add('j'); five.add('k'); five.add('l');
            table.put(5, five);
            ArrayList<Character> six = new ArrayList<Character>();
            six.add('m'); six.add('n'); six.add('o');
            table.put(6, six);
            ArrayList<Character> seven = new ArrayList<Character>();
            seven.add('p'); seven.add('q'); seven.add('r'); seven.add('s');
            table.put(7, seven);
            ArrayList<Character> eight = new ArrayList<Character>();
            eight.add('t'); eight.add('u'); eight.add('v'); 
            table.put(8, eight);
            ArrayList<Character> nine = new ArrayList<Character>();
            nine.add('w'); nine.add('x'); nine.add('y'); nine.add('z'); 
            table.put(9, nine);
            table.put(1, new ArrayList<Character>());
            table.put(0, new ArrayList<Character>());
        }
    }
    public static List<String> letterCombinations(String digits) {
    	preprocess();
        List<String> result = new ArrayList<String>();
        result.add("");

        for (int i=0; i<digits.length(); i++) {
        	int digit = digits.charAt(i) - '0';
        	// System.out.println(digit);
        	List<Character> allChars = table.get(digit);
        	for (char ch: allChars) {
        		// System.out.println(ch + " " + digit);
        	}

        	List<String> newStrings = new ArrayList<String>();
        	for (Character c: allChars) {
        		for (String str: result) {
        			String newStr = str + c;
        			newStrings.add(newStr);
        		}
        	}
        	result = newStrings;
        }
        return result;
    }

    public static void main(String[] args) {
    	List<String> lists = letterCombinations("2222");
    	for (String s: lists) {
    		System.out.println(s);
    	}
    }



}