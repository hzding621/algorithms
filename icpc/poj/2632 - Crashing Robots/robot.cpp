#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int move(vector<vector<pair<int, int> > >& table, vector<pair<int, int> >& rbs, int id, char type) {
  pair<int, int> p = rbs[id-1];
  int o = table[p.first][p.second].second;
  if (type == 'L') {
    table[p.first][p.second].second = (o + 2) % 4 + 1;
  } else if (type == 'R') {
    table[p.first][p.second].second = o % 4 + 1;
  } else {
    int nx, ny;
    if (o == 1) {
      nx = p.first-1; ny = p.second;
    } else if (o == 2) {
      nx = p.first; ny = p.second + 1;
    } else if (o == 3) {
      nx = p.first+1; ny = p.second;
    } else {
      nx = p.first; ny = p.second - 1;
    }
    // cout << nx << " " << ny << endl;
    // cout << table[0].size() << endl;
    // cout << "o=" << o <<  " id=" << id << " x=" << p.first << " y=" << p.second << " nx=" << nx << " ny=" << ny << endl;
    if (nx < 0 || ny < 0 || nx >= table.size() || ny >= table[0].size())
      return -1;
    else if (table[nx][ny].second != 0)
      return table[nx][ny].first;
    table[nx][ny].first = id;
    table[nx][ny].second = o;
    table[p.first][p.second].first = 0;
    table[p.first][p.second].second = 0;
    rbs[id-1] = make_pair(nx, ny);
  }
  return 0;
}

int main() {

  int n;
  cin >> n;
  while (n-- > 0) {

    vector<vector<pair<int,int> > > table;
    int r, c;
    cin >> c >> r;
    for (int i=0; i<r; i++) {
      table.push_back(vector<pair<int,int> >(c, make_pair(0, 0)));
    }
    int rb_count, inst_count;
    cin >> rb_count >> inst_count;
    //
    // cout << "rb=" << rb_count << endl;
    // cout << "inst=" << inst_count << endl;

    vector<pair<int,int> > rbs;
    for (int i=0; i<rb_count; i++) {
      int x, y;
      cin >> y >> x;
      x = table.size() - x;
      y = y - 1;
      // cout << x << " " << y << endl;
      rbs.push_back(make_pair(x, y));
      char c;
      cin >> c;
      // cout << c << endl;
      switch(c) {
        case 'N':
          table[x][y] = make_pair(i+1, 1);
          break;
        case 'E':
          table[x][y] = make_pair(i+1, 2);
          break;
        case 'S':
          table[x][y] = make_pair(i+1, 3);
          break;
        case 'W':
          table[x][y] = make_pair(i+1, 4);
          break;
      }
    }
    bool crashed = false;
    while (inst_count-- > 0) {
      int i, r;
      char type;
      cin >> i >> type >> r;
      for (int ii=0; ii<r; ii++) {
        if (crashed) continue;
        // cout << i << " " << type << endl;
        int ret = move(table, rbs, i, type);
        if (ret < 0)
          cout << "Robot " <<  i << " crashes into the wall" << endl;
        else if (ret > 0)
          cout << "Robot " << i << " crashes into robot " << ret << endl;
        if (ret != 0) crashed = true;
      }
    }
    if (!crashed) cout << "OK" << endl;
  }
  return 0;
}
