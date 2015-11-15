#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

int main() {

	int n;
	while (cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool bs = true, bq = true, bpq = true;
		for (int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			if (x == 1) {
				if (bs) s.push(y);
				if (bq) q.push(y);
				if (bpq) pq.push(y);
			} else {
				// x == 2
				if (bs) {
					if (s.size() == 0 || s.top() != y)
						bs = false;
					else
						s.pop();
				}
				if (bq) {
					if (q.size() == 0 || q.front() != y)
						bq = false;
					else
						q.pop();
				}
				if (bpq) {
					if (pq.size() == 0 || pq.top() != y)
						bpq = false;
					else
						pq.pop();
				}

			}
		}
		if (bs && !bq && !bpq)
			cout << "stack" << endl;
		else if (!bs && bq && !bpq)
			cout << "queue" << endl;
		else if (!bs && !bq && bpq)
			cout << "priority queue" << endl;
		else if (!bs && !bq && !bpq)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}


}
