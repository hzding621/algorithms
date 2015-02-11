import java.util.*;

public class PARTY{

	static class Pair {
		public int a;
		public int b;
		public Pair(int a, int b){
			this.a=a;
			this.b=b;
		}
	}

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);

		while (stdin.hasNext()) {

			int budget = stdin.nextInt();
			int size = stdin.nextInt();

			if (budget == 0)
				break;
			List<Pair> parties = new ArrayList<Pair>();		

			while (size>0) {
				int a = stdin.nextInt();
				int b = stdin.nextInt();
				Pair x = new Pair(a,b);
				parties.add(x);
				size--;
			}

			int[][] table = new int[budget+1][parties.size()];

			for (int i=0; i<=parties.size()-1; i++) {// i up to ith parties you can use
				for (int j=0; j<=budget; j++) { // j current budget you have
					for (int k=0; k<=i; k++) {
						if (j >= parties.get(k).a) {
							if (k == 0)
								table[j][i] = parties.get(k).b;
							else if (table[j][i] < table[j-parties.get(k).a][k-1] + parties.get(k).b)
								table[j][i] = table[j-parties.get(k).a][k-1] + parties.get(k).b;	
						}
					}
				}
			}

			int opt = table[budget][parties.size()-1];
			int min = budget-1;
			while (table[min][parties.size()-1] == opt)
				min--;
			min++;
			System.out.println(min + " " + opt);

		}
	}
}
