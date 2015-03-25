import java.util.*;

public class PossibleScores {

	public static int PossibleScores(int score, int[] increments) {
		boolean[] all = new boolean[score];
        Queue<Integer> q = new ArrayDeque<Integer>();
        for(int i=0; i<increments.length; i++){
            if (increments[i] <= score)
                q.add(increments[i]);
        }
        while (!q.isEmpty()) {
            int n = q.remove();
            all[n-1] = true;
            for (int j=0; j<increments.length; j++) {
                if (n+increments[j] <= score && all[n+increments[j]-1] == false){
                    q.add(n+increments[j]);
                }
            }
        }
        return all[score-1] == true ? 1 : 0;
	}

	public static void main(String[] args) {
		System.out.println(possible(7, new int[] {11,3,2,3}));
	}
}