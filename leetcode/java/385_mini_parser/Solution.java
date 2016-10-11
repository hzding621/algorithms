import util.Pair;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class NestedInteger {
    private int value;
    private final List<NestedInteger> list;
    private final boolean isInteger;

    public NestedInteger(int value) {
        this.value = value;
        this.list = Collections.emptyList();
        this.isInteger = true;
    }

    public NestedInteger() {
        this.value = 0;
        this.list = new ArrayList<>();
        this.isInteger = false;
    }

    public boolean isInteger() {
        return isInteger;
    }

    public Integer getInteger() {
        if (!isInteger) {
            throw new IllegalStateException("Not An Integer!");
        }
        return value;
    }

    public void setInteger(int value) {
        if (!isInteger) {
            throw new IllegalStateException("Not An Integer!");
        }
        this.value = value;
    }

    public void add(NestedInteger ni) {
        list.add(ni);
    }

    public List<NestedInteger> getList() {
        return list;
    }
}

public class Solution {

    public NestedInteger deserialize(String s) {
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        } else {
            return extractList(s, 0).getFirst();
        }
    }

    private Pair<NestedInteger, Integer> extractList(String s, int head) {
        if (s.charAt(head) != '[') {
            throw new IllegalStateException("Does not start with [");
        }
        NestedInteger rootList = new NestedInteger();
        head++;
        while (s.charAt(head) != ']') {
            if (s.charAt(head) == '[') {
                final Pair<NestedInteger, Integer> result = extractList(s, head);
                rootList.add(result.getFirst());
                head = result.getSecond();
            } else {
                int endOfInt = head;
                while (s.charAt(endOfInt) != ']' && s.charAt(endOfInt) != ',') {
                    endOfInt++;
                }
                rootList.add(new NestedInteger(Integer.parseInt(s.substring(head, endOfInt))));
                head = endOfInt;
            }
            if (s.charAt(head) == ',') {
                head++;
            }
        }
        head++;
        return Pair.of(rootList, head);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        NestedInteger ni = solution.deserialize("[123,456,[788,799,833],[[]],10,[]]");
    }
}