#include <stdlib.h>
#include <stdio.h>

/*
 * Complete the function below.
 */
int getNumberOfPrimes(int N) {
    int *array = calloc(sizeof(int), N+1);
    
    array[0] = 1;
    array[1] = 1; // 0 and 1 are not used;
    
    int i=2;
    for (; i<=N; i++) {
        if (array[i] == 0) {
            int factor = 2;
            while (i * factor <= N) {
                array[i * factor] = 1;
                factor++;
            }
        }
    }
    
    int count = 0;
    int j = 2;
    for (; j<=N; j++) {
        if (array[j] == 0)
            count++;
    }
    return count;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    int res;
    int _N;
    scanf("%d", &_N);
    
    res = getNumberOfPrimes(_N);
    fprintf(f, "%d\n", res);
    
    fclose(f);
    return 0;
}