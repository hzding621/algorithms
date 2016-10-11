// https://oj.leetcode.com/problems/zigzag-conversion/

import java.util.*;

public class ZigZag {
	static void printMap(ArrayList<ArrayList<Character>> map, int nRows) {
		for (int m=0; m<nRows; m++) {
			for (int n=0; n<map.get(m).size(); n++) {
				char c = map.get(m).get(n);
				if (c!='\0')
					System.out.print(c);
				else
					System.out.print(' ');
			}
			System.out.println();

		}
	}

	public static String convert(String s, int nRows) {
		if (nRows == 1)
			return s;

		ArrayList<ArrayList<Character>> map = new ArrayList<ArrayList<Character>>();
		for (int i=0; i<nRows; i++) {
			ArrayList<Character> newRow = new ArrayList<Character>();
			newRow.add('\0');
			map.add(newRow);

		}

		boolean goingDown = true;
		int curRow = 0, curCol = 0;
		for (int i=0; i<s.length(); i++) {
			// iterate through the characters
			

			map.get(curRow).set(curCol, s.charAt(i));
			if (goingDown == true) {
				if (curRow == nRows-1) {
					for (int j=0; j<nRows; j++) {
						map.get(j).add('\0');// expand each row
					}
					goingDown = false;
					curRow--;
					curCol++;
				} else {
					curRow++;
				}
			} else {
				if (curRow == 0) {
					goingDown = true;
					curRow++;
				}
				else {
					for (int j=0; j<nRows; j++) {
						map.get(j).add('\0');// expand each row
					}
					curRow--;
					curCol++;
				}
			}

			
		}


		// printMap(map, nRows);
		StringBuilder str = new StringBuilder();
		for (int i=0; i<nRows; i++) {
			for (int j=0; j<map.get(i).size(); j++) {
				char c = map.get(i).get(j);
				if (c != '\0')
					str.append(c);
			}
		}
		return str.toString();
		
	}

	public static void main(String[] args) {
		System.out.println(convert("PAYPALISHIRING", 3));
	}
}