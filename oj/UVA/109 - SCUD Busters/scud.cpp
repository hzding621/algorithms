#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
struct point {
  int x; int y;
};
bool operator<(point& i, point& j) {
  return i.x < j.x || (i.x == j.x && i.y < j.y);
}

bool isLower(point& i, point& j) {
  return i.y * j.x < i.x * j.y;
}

class compareAngle {
public:
  compareAngle(point origin) : o(origin) {}
  bool operator()(point i, point j) {
    i.x -= o.x; i.y -= o.y;
    j.x -= o.x; j.y -= o.y;
    return isLower(i, j);
  }
private:
  point o;
};

vector<point> findConvexHull(vector<point>& p) {
  point o = p[0];
  int ind = 0;
  for (int i=1; i<p.size(); i++) {
    if (p[i] < o) {
      o = p[i];
      ind = i;
    }
  }
  swap(*p.begin(), *(p.begin() + ind));
  sort(p.begin() + 1, p.end(), compareAngle(o));

  vector<point> ch;
  ch.push_back(p[0]);
  ch.push_back(p[1]);
  point lastVec = {p[1].x-p[0].x, p[1].y-p[0].y};
  for (int i=2; i<p.size(); i++) {
    point curVec = { p[i].x-ch.back().x, p[i].y-ch.back().y};
    while (isLower(curVec, lastVec)) {
      ch.pop_back();
      curVec.x = p[i].x - ch.back().x;
      curVec.y = p[i].y - ch.back().y;
      lastVec.x = ch.back().x - (ch.end() - 2)->x;
      lastVec.y = ch.back().y - (ch.end() - 2)->y;
    }
    ch.push_back(p[i]);
    lastVec = curVec;
  }
  ch.push_back(ch[0]);
  return ch;
};


bool pointInConvexHull(point pt, vector<point>& pts) {
  for (int i=0; i<pts.size()-1; i++) {
    point a =  {pt.x - pts[i].x, pt.y - pts[i].y};
    point b =  {pts[i+1].x - pts[i].x, pts[i+1].y - pts[i].y};
    if (isLower(a, b)) return false;
  }
  return true;
}

int findArea(vector<point>& pts) {
  int area = 0;
  for (int i=0; i<pts.size()-1; i++) {
    area += pts[i].x * pts[i+1].y - pts[i+1].x * pts[i].y;
  }
  return area;
}

void testConvexHull() {
  vector<point> pts;
  pts.push_back(point{0,0});
  pts.push_back(point{1,2});
  pts.push_back(point{2,0});
  pts.push_back(point{2,2});
  pts.push_back(point{1,1});

  auto ch = findConvexHull(pts);
  for (auto& p: ch)
    cout << p.x << "," << p.y << endl;

  cout << boolalpha;
  cout << pointInConvexHull(point{0,1},ch) << endl;
  cout << pointInConvexHull(point{1,1},ch) << endl;
  cout << pointInConvexHull(point{2,1},ch) << endl;

}

int main() {

  // testConvexHull();

  vector<vector<point>> chs;
  point pt;
  int k;
  while (scanf("%d\n", &k), k > 0) {
    vector<point> kingdom;
    for (int i=0; i<k; i++) {
      scanf("%d %d\n", &pt.x, &pt.y);
      kingdom.push_back(pt);
    }
    vector<point> hull = findConvexHull(kingdom);
    chs.push_back(hull);
  }
  int n = chs.size();
  vector<bool> hit(n);
  int sumArea = 0;
  while (scanf("%d %d\n", &pt.x, &pt.y) == 2) {
    for (int i=0; i<n; i++) {
      if (!hit[i] && pointInConvexHull(pt, chs[i])) {
        hit[i] = true;
        sumArea += findArea(chs[i]);
        break;
      }
    }
  }
  printf("%.2f\n", sumArea / 2.0);
}
