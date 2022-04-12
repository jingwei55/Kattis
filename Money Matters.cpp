#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
vector<vll> AL;
vll dfs_num;

enum { UNVISITED = -1, VISITED = -2 };

void dfs(ll u, ll& pay, unordered_map<ll, ll> &debt) {
    dfs_num[u] = VISITED;                     
    for (auto& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            pay += debt[v];
            dfs(v, pay, debt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll friends, friendships, owe, f1, f2;
    unordered_map<ll, ll> debt;
    cin >> friends >> friendships;
    AL.assign(friends, vll());
    for (ll i = 0; i < friends; i++) {
        cin >> owe;
        debt[i] = owe;
    }
    /*for (auto v : debt) {
        cout << v.first << v.second;
    }*/
    //cout << friendships;
    while (friendships--) {
        cin >> f1 >> f2;
        AL[f1].push_back(f2);
        AL[f2].push_back(f1);
    }
    ll status = 1;
    dfs_num.assign(friends, UNVISITED);
    for (ll i = 0; i < friends; i++) {
        if (dfs_num[i] == UNVISITED) {
            ll money = debt[i];
            dfs(i, money, debt);
            if (money < 0) {
                cout << "IMPOSSIBLE";
                status = 0;
                break;
            }
        }
    }
    if (status) cout << "POSSIBLE";
}
