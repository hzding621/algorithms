#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countPrimes(int n) {
    int* array = (int*) calloc(n, sizeof(int));
    array[0] = 1;
    int k = 2, nk, sqn = sqrt(n);
    while (k <= sqn) {
        if (k < 46341)
            for (nk = k * k; nk < n; nk += k)
                array[nk-1] = 1;
        k++;
        while (k < n && array[k-1])
            k++;
    }
    int cnt = 0, i = 2;
    for (; i < n; i++)
        if (!array[i-1])
            cnt++;
    free(array);
    return cnt;
}
int main() {

    printf("countPrimes(%d) = %d\n", 49979, countPrimes(49979));

    return 0;
}
