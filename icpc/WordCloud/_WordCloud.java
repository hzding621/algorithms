import java.util.*;
import java.io.*;

class Word {
	public String name;
	public int count; 
	public int point;

	public Word(String s, int i) {
		name = s;
		count = i;
	}

	public int setPoint(int p) {
		this.point = p;
		return p;
	}

	public int getWordWidth() {

		return (int) (Math.ceil(9.0/16 * this.name.length() *this.point ));
	}
	
	
}

class WordComparator implements Comparator<Word> {
    @Override
    public int compare(Word c, Word d ) {
		return c.name.compareTo(d.name);
	}
}

class DataSet {
	public ArrayList<Word> data;
	public int width;
	public int id;

	public DataSet(ArrayList<Word> data, int width, int id) {
		this.data = data;
		this.width = width;
		this.id = id;
	}
}

public class WordCloud {

	static int dataSetCount = 1;

	public static int getMaxCount(DataSet dt) {
		int max = 0;
		for (Word w: dt.data) {
			int c = w.count;
			max = Math.max(max, c);
		}
		return max;
	} 

	public static ArrayList<DataSet> parseData(String input) {

		ArrayList<DataSet> datas = new ArrayList<DataSet>();

		// System.out.print(input);

		String[] lines = input.split("\n");
		int width, num;
		int i = 0;
		while (true) {
			String[] in = lines[i].split(" ");
			width = Integer.parseInt(in[0]);
			num = Integer.parseInt(in[1]);
			// System.out.println(width + " " +num);

			if (num == 0)
				break;

			ArrayList<Word> lists = new ArrayList<Word>();

			for (int j=1; j<=num; j++) {
				String[] dt = lines[j].split(" ");
				String name = dt[0];
				int count = Integer.parseInt(dt[1]);
				lists.add(new Word(name, count));
			}
			DataSet d = new DataSet(lists, width, dataSetCount);
			datas.add(d);

			i += num + 1;
			dataSetCount += 1;
			// System.out.println("Once");
			
		}
		return datas;
	}

	public static int formula(int count, int maxCount) {
		return (int) Math.ceil( 8 + ( 40.0 * (count - 4) / (maxCount - 4)) );
	}

	public static void solve(ArrayList<DataSet> datas) {
		for (DataSet dt : datas) {
			ArrayList<Word> lists = dt.data;

			// Collections.sort(lists, new WordComparator());
			int maxCount = getMaxCount(dt);
			
			for (Word w : lists) {
				// System.out.print(w.name + " ");
				// System.out.println(w.count);
				double p = w.setPoint(formula(w.count, maxCount));
				// System.out.println(p);
				// System.out.println(w.getWordWidth());
			}

			int lineMax = dt.width;
			int curLen = 0;
			int curLineHeight = 0;
			int height = 0;

			curLen = lists.get(0).getWordWidth();
			curLineHeight = lists.get(0).point;
			// System.out.println("apple: " + lists.get(0).point + " " + lists.get(0).getWordWidth());
			// System.out.println("banana: " + lists.get(1).point + " " + lists.get(1).getWordWidth());
			for (int i = 1; i<=lists.size()-1; i++) {
				Word w = lists.get(i);
				int wordWidth = w.getWordWidth();
				if (curLen + wordWidth + 10<= lineMax) {
					// System.out.print(w.getWordWidth() + " ");
					curLen += wordWidth + 10;
					curLineHeight = Math.max(curLineHeight, w.point);
				}
				else {
					// System.out.print('\n' + w.getWordWidth() + " ");
					height += curLineHeight;
					curLen = wordWidth;
					curLineHeight = w.point;
				}
			}
			height += curLineHeight;
			System.out.println("CLOUD " + dt.id +": " + height);


		}
	}

	static String test = "260 6\napple 10\nbanana 5\ngrape 20\nkiwi 18\norange 12\nstrawberry 10\n250 6\napple 10\nbanana 5\ngrape 20\nkiwi 18\norange 12\nstrawberry 10\n610 6\napple 10\nbanana 5\ngrape 20\nkiwi 18\norange 12\nstrawberry 10\n0 0";

	public static void main(String[] args) throws IOException{
		StringBuilder sb = new StringBuilder();

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    String s;
	    while ((s = in.readLine()) != null && s.length() != 0) {
	    	sb.append(s + '\n');
	    }
	    solve(parseData(sb.toString()));
	}
}