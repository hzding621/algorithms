#include <stdio.h>

double myPow(double x, int n) {
	if (n >= 0) {
		int n2 = n;
		double expo[32];
		expo[0] = x;
		int i=0;
		while (n != 0) {
			expo[i+1] = expo[i] * expo[i];
			i++;
			n >>= 1;
		}
		double ans = 1;
		i = 0;
		while (n2 != 0) {
			if (n2 & 1) {
				ans *= expo[i];
			}
			i++;
			n2 >>= 1;
		}
		return ans;
	} else {
		if (n != -2147483648) {	
			double denom = myPow(x, -n);
			return 1 / denom;
		} else {
			int k = 30;
			double expo = x;
			while (k > 0) {
				k--;
				expo = expo * expo;
			}
			return 1 / expo;
		}
	}
}

int main() {

	printf("%0.f\n", myPow(2,0));
	return 0;
}