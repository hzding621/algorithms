package util;

import java.util.Comparator;

/**
 * Utility class, Hash-by-value
 */
public class Pair<A, B> {
    private final A first;
    private final B second;
    private Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    public A getFirst() {
        return first;
    }

    public B getSecond() {
        return second;
    }

    public static <A, B>  Pair<A, B> of(A first, B second) {
        return new Pair<>(first, second);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair<?, ?> pair = (Pair<?, ?>) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
        return second != null ? second.equals(pair.second) : pair.second == null;

    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public static <A extends Comparable<A>, B extends Comparable<B>> Comparator<Pair<A, B>> naturalOrder() {
        return naturalOrder(false, false);
    }

    public static <A extends Comparable<A>, B extends Comparable<B>> Comparator<Pair<A, B>>
    naturalOrder(boolean reverseA, boolean reverseB) {
        return (o1, o2) -> {
            int cmp = reverseA ? o1.getFirst().compareTo(o2.getFirst()) : o2.getFirst().compareTo(o1.getFirst());
            if (cmp == 0) {
                cmp = reverseB ? o1.getSecond().compareTo(o2.getSecond()) : o2.getSecond().compareTo(o1.getSecond());
            }
            return cmp;
        };
    }
}
