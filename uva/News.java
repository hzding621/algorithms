// 924	Spreading The News

import java.util.*;

public class News {


	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		while (stdin.hasNext()) {
			int numEmployee = stdin.nextInt();
			boolean[][] friendships = new boolean[numEmployee][numEmployee];
			for (int i=0; i<numEmployee; i++) {
				int count = stdin.nextInt();
				for (int j=0; j<count; j++) {
					int friend = stdin.nextInt();
					friendships[i][friend] = true;
				}
			}
			int numTestCases = stdin.nextInt();
			while (numTestCases>0) {

				int start = stdin.nextInt();
				List<Integer> current = new ArrayList<Integer>();
				List<Integer> next = new ArrayList<Integer>();
				List<Integer> boomSize = new ArrayList<Integer>();
				boolean[] visited = new boolean[numEmployee];
				current.add(start);
				visited[start] = true;
				while (!current.isEmpty()) {
					
					for (int i=0; i<current.size(); i++) {
						int people = current.get(i);
						for (int k=0; k<numEmployee; k++) {
							if (friendships[people][k] == true && visited[k] == false) {
								visited[k] = true;
								next.add(k);
							}
						}
					}

					boomSize.add(current.size());
					current = next;
					next = new ArrayList<Integer>();
				}
				int maxBoom = 0;
				int index = 0;
				for (int s=1; s<boomSize.size(); s++) {
					if (boomSize.get(s) > maxBoom) {
						maxBoom = boomSize.get(s);
						index = s;
					}
				}
				
				if (boomSize.size() == 1) 
					System.out.println(0);
				else {
					System.out.println(maxBoom + " " + index);
				}

				numTestCases--;
			}


		}		
	}
}