package util;

import java.util.Comparator;

/**
 * Utility class, Hash-by-value
 */
public class Triple<A, B, C> {
    private final A first;
    private final B second;
    private final C third;

    private Triple(A first, B second, C third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
    public A getFirst() {
        return first;
    }

    public B getSecond() {
        return second;
    }

    public C getThird() {
        return third;
    }

    public static <A, B, C>  Triple<A, B, C> of(A first, B second, C third) {
        return new Triple<>(first, second, third);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Triple<?, ?, ?> triple = (Triple<?, ?, ?>) o;

        if (first != null ? !first.equals(triple.first) : triple.first != null) return false;
        if (second != null ? !second.equals(triple.second) : triple.second != null) return false;
        return third != null ? third.equals(triple.third) : triple.third == null;

    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        result = 31 * result + (third != null ? third.hashCode() : 0);
        return result;
    }

    public static <A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>>
    Comparator<Triple<A, B, C>> naturalOrder() {
        return naturalOrder(false, false, false);
    }

    public static <A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>>
    Comparator<Triple<A, B, C>> naturalOrder(boolean reverseA, boolean reverseB, boolean reverseC) {
        return (o1, o2) -> {
            int cmp = reverseA ? o1.getFirst().compareTo(o2.getFirst()) : o2.getFirst().compareTo(o1.getFirst());
            if (cmp == 0) {
                cmp = reverseB ? o1.getSecond().compareTo(o2.getSecond()) : o2.getSecond().compareTo(o1.getSecond());
            }
            if (cmp == 0) {
                cmp = reverseC ? o1.getThird().compareTo(o2.getThird()) : o2.getThird().compareTo(o1.getThird());
            }
            return cmp;
        };
    }
}