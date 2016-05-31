#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void print_median(priority_queue<int>& small, priority_queue<int, vector<int>, greater<int>>& large) {
  int n ;
  if (small.size() > large.size())
    n = small.top();
  else if (small.size() < large.size())
    n = large.top();
  else
    n = (small.top() + large.top())/2;
  printf("%d\n", n);
}

int main() {

  int n;
  priority_queue<int> smaller_number;
  priority_queue<int, vector<int>, greater<int>> larger_number;
  while(scanf("%d\n", &n) != EOF) {
    if (!smaller_number.empty()) {
      if (n < smaller_number.top())
        smaller_number.push(n);
      else
        larger_number.push(n);
    } else if (!larger_number.empty()) {
      if (n >= larger_number.top())
        larger_number.push(n);
      else
        smaller_number.push(n);
    } else
      smaller_number.push(n);
    if (larger_number.size() > 1 + smaller_number.size()) {
      smaller_number.push(larger_number.top());
      larger_number.pop();
    } else if (smaller_number.size() > 1 + larger_number.size()) {
      larger_number.push(smaller_number.top());
      smaller_number.pop();
    }

    print_median(smaller_number, larger_number);

  }
  return 0;
}
