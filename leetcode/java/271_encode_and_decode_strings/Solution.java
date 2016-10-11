import java.util.ArrayList;
import java.util.Arrays;
import java.util.IllegalFormatException;
import java.util.List;
import java.util.Scanner;

/**
 * Created by haozhending on 10/11/16.
 */
public class Solution {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder stringBuilder = new StringBuilder();
        for (String s: strs) {
            stringBuilder.append("<");
            stringBuilder.append(s.length());
            stringBuilder.append(">");
            stringBuilder.append(s);
        }
        return stringBuilder.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> strs = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) != '<') {
                throw new IllegalStateException("Expected <");
            }
            i++;
            int j = i;
            while (s.charAt(j) != '>') {
                j++;
            }
            int length = Integer.parseInt(s.substring(i, j));
            String token = s.substring(j + 1, j + length + 1);
            strs.add(token);
            i = j + length + 1;
        }
        return strs;
    }

    public static void main(String[] args) {
        List<String> strs = Arrays.asList("abc", "bcd");
        Solution solution = new Solution();
        String encoded = solution.encode(strs);
        System.out.println(encoded);
        List<String> decoded = solution.decode(encoded);
        System.out.println(decoded);
    }
}
