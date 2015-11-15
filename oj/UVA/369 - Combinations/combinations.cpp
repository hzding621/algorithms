#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define uint unsigned int 
using namespace std;
 
uint binom[101][101];

int main() {

	int maxRow = 1;
	binom[1][0] = 1;
	binom[1][1] = 1;
	int n, m;
	while (scanf("%d %d\n", &n, &m), n || m) {
		if (n > maxRow) {
			for (int i=maxRow+1; i<=n; i++) {
				binom[i][0] = 1;
				for (int j=1; j<i; j++) {
					binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
				}
				binom[i][i] = 1;
			}
			maxRow = n;
		}
		printf("%d things taken %d at a time is %u exactly.\n", n, m, binom[n][m]);
	}

	return 0;
}