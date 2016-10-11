package util;

import java.util.Comparator;

/**
 * Utility class, Hash-by-value
 */
public class Tuple4<A, B, C, D> {
    private final A first;
    private final B second;
    private final C third;
    private final D fourth;

    private Tuple4(A first, B second, C third, D fourth) {
        this.first = first;
        this.second = second;
        this.third = third;
        this.fourth = fourth;
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

    public D getFourth() {
        return fourth;
    }

    public static <A, B, C, D>  Tuple4<A, B, C, D> of(A first, B second, C third, D fourth) {
        return new Tuple4<>(first, second, third, fourth);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Tuple4<?, ?, ?, ?> tuple4 = (Tuple4<?, ?, ?, ?>) o;

        if (first != null ? !first.equals(tuple4.first) : tuple4.first != null) return false;
        if (second != null ? !second.equals(tuple4.second) : tuple4.second != null) return false;
        if (third != null ? !third.equals(tuple4.third) : tuple4.third != null) return false;
        return fourth != null ? fourth.equals(tuple4.fourth) : tuple4.fourth == null;

    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        result = 31 * result + (third != null ? third.hashCode() : 0);
        result = 31 * result + (fourth != null ? fourth.hashCode() : 0);
        return result;
    }

    public static <A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>, D extends Comparable<D>>
    Comparator<Tuple4<A, B, C, D>> naturalOrder() {
        return naturalOrder(false, false, false, false);
    }

    public static <A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>, D extends Comparable<D>>
    Comparator<Tuple4<A, B, C, D>> naturalOrder(boolean reverseA, boolean reverseB, boolean reverseC, boolean reverseD) {
        return (o1, o2) -> {
            int cmp = reverseA ? o1.getFirst().compareTo(o2.getFirst()) : o2.getFirst().compareTo(o1.getFirst());
            if (cmp == 0) {
                cmp = reverseB ? o1.getSecond().compareTo(o2.getSecond()) : o2.getSecond().compareTo(o1.getSecond());
            }
            if (cmp == 0) {
                cmp = reverseC ? o1.getThird().compareTo(o2.getThird()) : o2.getThird().compareTo(o1.getThird());
            }
            if (cmp == 0) {
                cmp = reverseD ? o1.getFourth().compareTo(o2.getFourth()) : o2.getFourth().compareTo(o1.getFourth());
            }
            return cmp;
        };
    }

}
