#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

int flip(int n, int i, int j) {
  int p = i*4+j;
  int k = 15 - p;
  n = n ^ (1 << k);
  if (i > 0) {
    k = 15 -((i-1)*4+j);
    n = n ^ (1 << k);
  }
  if (j > 0) {
    k = 15 -(i*4+(j-1));
    n = n ^ (1 << k);
  }
  if (i < 3) {
    k = 15 - ((i+1)*4+j);
    n = n ^ (1 << k);
  }
  if (j < 3) {
    k = 15 - (i*4+(j+1));
    n = n ^ (1 << k);
  }
  return n;
}


int main() {

  int n = 0;
  for (int i=0; i<4; i++) {
    char s[10];
    scanf("%s\n", s);
    for (int j=0; j<4; j++) {
      if (s[j] == 'w')
        n = n << 1;
      else
        n = (n << 1) + 1;
    }
  }
  char visited[65536];
  memset(visited, 0, sizeof(visited));
  int t1 = (1 << 16) - 1, t2 = 0;
  queue<int> q;
  queue<int> q_dist;
  q.push(n);
  q_dist.push(0);
  visited[n] = 1;
  while (!q.empty()){
    int k = q.front(), kd = q_dist.front();
    q.pop();
    q_dist.pop();
    if (k == t1 || k == t2) {
      printf("%d\n", kd);
      return 0;
    }
    // for (int i=0; i<4; i++) {
    //   for (int j=0; j<4; j++) {
    //     int l = flip(k, i, j);
    //     int d = kd + 1;
    //     if (!visited[l]) {
    //       q.push(l);
    //       q_dist.push(d);
    //     }
    //   }
    // }
    for(int i = 0; i < 16; i++){
				int elem = k;
				elem = elem^(1 << i);
				if(i > 3)
					elem = elem^(1 << (i - 4));
				if(i < 12)
					elem = elem^(1 << (i + 4));
				if(i % 4 != 0)
					elem = elem^(1 << (i - 1));
				if(i % 4 != 3)
					elem = elem^(1 << (i + 1));
				if(!visited[elem]){
					visited[elem] = 1;
					q.push(elem);
          q_dist.push(kd+1);
				}
			}
  }
  printf("Impossible\n");
  return 0;

}
