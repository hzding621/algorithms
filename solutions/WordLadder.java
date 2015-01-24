// https://oj.leetcode.com/problems/word-ladder/

import java.util.*;

public class WordLadder {

	public static int ladderLength(String start, String end, Set<String> dict) {
        
        dict.add(start);
        dict.add(end);
        
        Map<String, Set<String>> neighbors = new HashMap<String, Set<String>>();
        for (String s: dict) {
            neighbors.put(s, new HashSet<String>());

            for (int i=0; i<s.length(); i++) {
                for (char c='a'; c <= 'z'; c++) {
                    char[] charS = s.toCharArray();
                    charS[i] = c;
                    String next = new String(charS);
                    if (dict.contains(next))
                        neighbors.get(s).add(next);
                }
            }
        }
        
        Map<String, Boolean> visited = new HashMap<String, Boolean>();
        Map<String, Integer> path = new HashMap<String, Integer>();
        for (String s: dict) {
            visited.put(s, false);
            path.put(s, Integer.MAX_VALUE);
        }
        visited.put(start, true);
        path.put(start, 1);
        
        Queue<String> queue = new ArrayDeque<String>();
        queue.add(start);
        
        while (!queue.isEmpty()) {
            String str = queue.remove();
            for (String s: neighbors.get(str)) {
                if (!visited.get(s)) {
                    if (s.equals(end))
                        return path.get(str) + 1;
                    path.put(s, path.get(str)+1);
                    visited.put(s, true);
                    queue.add(s);
                }
            }
        }
        return 0;
        
    }

    public static void main(String[] agrs) {
    	String start = "hit";
		String end = "cog";
		String[] dict = {"hot","dot","dog","lot","log"};
        HashSet<String> set = new HashSet<String>();
		for (int i=0; i<dict.length; i++)
            set.add(dict[i]);
        set.add(start);
        set.add(end);

        System.out.println(ladderLength(start, end, set));
    }

}