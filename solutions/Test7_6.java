/* https://oj.leetcode.com/problems/max-points-on-a-line/ */

import java.util.*;

public class Test7_6 {
	
	public static float getSlope(Point a, Point b) {
        return (b.x - a.x) == 0 ? Float.MAX_VALUE : (float) (b.y-a.y) / (b.x-a.x); 
    }

	public static int maxPoints(Point[] points) {
		HashMap<Float, Integer> statistic = new HashMap<Float, Integer>();
		int maxNum = 0;
		for (int i=0; i<points.length; i++) {
			statistic.clear();
			statistic.put(Float.MIN_VALUE, 0);
			int duplicate = 1;
			for (int j=0; j<points.length; j++) {
				if (j == i)
					continue;
				if (points[j].x == points[i].x && points[j].y == points[i].y) {
					duplicate++;
					continue;
				}
				float key = getSlope(points[j], points[i]);
				if (!statistic.containsKey(key)) {
					statistic.put(key,1);
				}
				else {
					statistic.put(key, statistic.get(key)+1);
				}
			}
			for (Map.Entry<Float, Integer> e: statistic.entrySet()) {
				if (e.getValue() + duplicate > maxNum) {
					maxNum = e.getValue() + duplicate;
				}
			}
		}
		return maxNum;
	}

}
