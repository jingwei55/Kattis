#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vector<vi> AL;
vi visited;

void bfs(ll s) { // s is the starting/source vertex
    queue<ll> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto& v : AL[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }  
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, vert, edge;
    ll a, b;
    cin >> n;
    while (n--) {
        ll roads = 0;
        cin >> vert >> edge;
        AL.assign(vert, vi()); //Adjacency list for each vertex
        while (edge--) {
            cin >> a >> b;
            AL[a].push_back(b);
            AL[b].push_back(a); // both sides since undirected
        }
        visited.assign(vert, 0); //initialize m size vector of 0s
        for (ll i = 0; i < vert; i++) {
            if (visited[i] == 0) {
                bfs(i);
                roads++;
            }
        }
        cout << roads-1 << '\n';
    }
}
