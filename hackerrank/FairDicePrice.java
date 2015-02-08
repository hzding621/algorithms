import java.io.*;
import java.util.*;
import java.math.*;

public class FairDicePrice {
	
	public static double expectation(double s, int rolls) {
			
			int cutoff = (int) s;
			int winRangeSum = 0;
			for (int c = cutoff+1; c <= 6 ; c++)
				winRangeSum += c;
			double winRangeAverage = winRangeSum * 1.0 / (6-cutoff);
			double loseRangeAverage = (21-winRangeSum) * 1.0/cutoff;
			double pLose = cutoff * 1.0 / 6.0;
			double pWin = 1-pLose;
			double pCum = 1;
			double exp = 0;
			for (int j =0; j<rolls; j++) {
				exp += (winRangeAverage) * (pCum * pWin);
				pCum *= pLose;
			}
			exp += (loseRangeAverage) * pCum;
			return exp;

	}

	public static int die_game_fair_value(int rolls) {
			int s = 10000;
			int opt = 10000;
			int minDiff = Integer.MAX_VALUE;
			for (; s < 60000; s += 100) {
				
				double exp = expectation(s * 1.0 / 10000, rolls);
				int diff = Math.abs((int)(exp*10000) - s );
				if (diff < minDiff) {
					minDiff = diff;
					opt = s;
				}
			}
			return opt;
		}
	   
	public static void main(String args[] ) throws Exception {
		
		System.out.println(die_game_fair_value(2));

	}
}