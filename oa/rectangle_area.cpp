#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool overflow(unsigned long long n) {
    return n > (unsigned long long) INT_MAX;
}

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
    // write your code in C++11
    unsigned long long ox = 0, oy = 0;
    vector<int> xs, ys;
    if (!(M < P) && !(K > R)) {
        xs.push_back(K);
        xs.push_back(M);
        xs.push_back(P);
        xs.push_back(R);
        sort(xs.begin(), xs.end());
        ox = (long long)(xs[2]) - (long long)(xs[1]);
    }
    if ( !(S < L) && !(Q > N)) {
        ys.push_back(L);
        ys.push_back(N);
        ys.push_back(Q);
        ys.push_back(S);
        sort(ys.begin(), ys.end());
        oy = (long long)(ys[2]) - (long long)(ys[1]);
    }
    unsigned long long o = ox * oy;
    unsigned long long w1 = (long long)M - (long long)K;
    unsigned long long h1 = (long long)N - (long long)L;
    unsigned long long area1 = w1 * h1;
    unsigned long long w2 = (long long)R - (long long)P;
    unsigned long long h2 = (long long)S - (long long)Q;
    unsigned long long area2 = w2 * h2;
    
    unsigned long long res = area1-o;
    if (overflow(res))
        return -1;
    if (overflow(area2))
        return -1;
    res = res + area2;    
    if (overflow(res))
        return -1;
    return (int)res;
}

int main() {


	int K = -INT_MAX/2, L = 0;
	int M = 0, N = 1;
	int P = 0, Q = 0;
	int R = INT_MAX/2, S = 1;
	cout << solution(K, L, M, N, P, Q, R, S) << endl;

	return 0;
}