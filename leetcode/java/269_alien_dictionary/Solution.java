package test;

import java.util.HashMap;
import java.util.HashSet;

public class Solution {

    public String alienOrder(String[] words) {
        HashMap<Character, Integer> nodeStatus = new HashMap<>();
        HashMap<Character, HashSet<Character>> neighbors = new HashMap<>();
        if (!findRelations(words, nodeStatus, neighbors)) {
            return "";
        }

        StringBuilder sortedChars = new StringBuilder();
        for (char c: nodeStatus.keySet()) {
            if (nodeStatus.get(c) == 0) {
                if (!dfs(c, sortedChars, nodeStatus, neighbors)) {
                    return "";
                }
            }
        }
        return sortedChars.reverse().toString();
    }

    private boolean dfs(char currentNode, StringBuilder sortedChars,
                        HashMap<Character, Integer> nodeStatus,
                        HashMap<Character, HashSet<Character>> neighbors) {
        if (nodeStatus.get(currentNode) == 1) {
            return false;
        }
        if (nodeStatus.get(currentNode) == 2) {
            return true;
        }
        nodeStatus.put(currentNode, 1);
        for (char c: neighbors.get(currentNode)) {
            if (!dfs(c, sortedChars, nodeStatus, neighbors)) {
                return false;
            }
        }
        nodeStatus.put(currentNode, 2);
        sortedChars.append(currentNode);
        return true;
    }

    private boolean findRelations(String[] words,
                                  HashMap<Character, Integer> nodeStatus,
                                  HashMap<Character, HashSet<Character>> neighbors) {
        for (String s: words) {
            for (int i = 0; i < s.length(); i++) {
                nodeStatus.put(s.charAt(i), 0);
                neighbors.putIfAbsent(s.charAt(i), new HashSet<>());
            }
        }

        for (int i = 1; i < words.length; i++) {
            int j = 0;
            while (j < words[i-1].length() && j < words[i].length()) {
                if (words[i-1].charAt(j) != words[i].charAt(j)) {
                    neighbors.get(words[i-1].charAt(j)).add(words[i].charAt(j));
                    break;
                }
                j++;
            }
            if (j == words[i].length() && j < words[i-1].length()) {
                return false;
            }
        }
        return true;
    }


    public static void main(String[] args) {
        String[] words = new String[] {
                "wrt","wrf","er","ett","rftt"
        };
        Solution solution = new Solution();
        System.out.println(solution.alienOrder(words));
    }
}
