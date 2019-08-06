#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100100;
int perm1[MAXN], perm2[MAXN], n, m;
bool was[MAXN];
vector<int>go[MAXN]; //ek array hai of type integer vector

void solve() {

  cin>>n>>m;
  set<int>s1, s2;
  for (int i = 1; i <= n; i++) {
   cin>>perm1[i];
    s1.insert( perm1[i] );
  }
  for (int i = 1; i <= n; i++) {
    cin>>perm2[i];
    s2.insert( perm2[i] );
  }

  for (int i = 1; i <= n; i++) {

   go[i].clear();
  }
  //array ke harr position ku clear kr rhe

  for (int i = 1; i <= m; i++) {
    int aa, bb;
    cin>>aa>>bb;
    go[aa].push_back(bb);
    go[bb].push_back(aa);
  }
  //kaunse kaunse goodpairs hai

  for (int i = 1; i <= n; i++) {
    was[i] = false;
  }


  for (int i = 1; i <= n; i++) {
    if (was[i] == true) {
      continue;
    }

    vector<int>q;
    int st = 0;
    q.push_back(i);
    was[i] = true;

    while (st < q.size() ) {
      int x = q[st]; st++;

      for (int j = 0; j < go[x].size(); j++) {
        int to = go[x][j];
        if (was[to] == false) {
          was[to] = true;
          q.push_back(to);
        }
      }
    }
    vector<int>v1, v2;

    for (int j = 0; j < q.size(); j++) {
	    v1.push_back( perm1[ q[j] ] );
	    v2.push_back( perm2[ q[j] ] );
    }
    sort(v1.begin(), v1.end() );
    sort(v2.begin(), v2.end() );

    if (v1 != v2) {
      cout<<"NO\n";
      return ;
    }
  }

  cout<<"YES\n";
}

int main() {

  int test;
  cin>>test;
  while (test--) {
    solve();

  }

  return 0;

}
