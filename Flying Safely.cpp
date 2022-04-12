#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vector<vi> AL;
vi visited;

ll bfs(ll s) { // s is the starting/source vertex
    ll edges = 0;
    queue<ll> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto& v : AL[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                edges++;
                q.push(v);
            }
        }
    }
    return edges;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, cities, pilots;
    ll a, b;
    cin >> n;
    while (n--) {
        ll roads = 0;
        cin >> cities >> pilots;
        AL.assign(cities, vi()); //Adjacency list for each vertex
        while (pilots--) {
            cin >> a >> b;
            AL[a-1].push_back(b-1);
            AL[b-1].push_back(a-1); // both sides since undirected
        }
        visited.assign(cities, 0); //initialize m size vector of 0s
        for (ll i = 0; i < cities; i++) {
            if (visited[i] == 0) {
                cout << bfs(i) << '\n';
 
            }
        }
    }
}
