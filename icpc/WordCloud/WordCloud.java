import java.util.*;

public class WordCloud{

	static int pointSize(int count, int maxCount) {

		return 8 + (int) Math.ceil(40.0 * (count-4) / (maxCount - 4));

	}


	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int lineWidth = stdin.nextInt();
		int loop = 1;

		while (lineWidth != 0 ){

			int dtSize = stdin.nextInt();
			// System.out.println("size: " + dtSize);
			LinkedHashMap<String, Integer> data = new LinkedHashMap<String, Integer>();
			int maxCount = 0;

			while (dtSize > 0) {
				
				String word = stdin.next();
				int count = stdin.nextInt();
				data.put(word, count);
				maxCount = Math.max(maxCount, count);

				dtSize--;
			}

			int curLength = 0;
			int totalHeight = 0;
			int curMaxPointSize = 0;


			for (Map.Entry<String, Integer> e: data.entrySet()) {

				int pointSize = pointSize(e.getValue(), maxCount);
				// System.out.println(pointSize);

				int wordWidth = (int) Math.ceil(9.0/16*e.getKey().length() * pointSize);
				// System.out.println(wordWidth);
				if (curLength + wordWidth <= lineWidth ) {

					curLength += (wordWidth + 10);
					curMaxPointSize = Math.max(curMaxPointSize, pointSize);
				}
				else {
					totalHeight += curMaxPointSize;
					curLength = wordWidth + 10;
					curMaxPointSize = pointSize;
				}

			}
			totalHeight += curMaxPointSize;
			System.out.println("CLOUD " + loop +": " + totalHeight);

			lineWidth = stdin.nextInt();
			loop++;

		}


	}

}