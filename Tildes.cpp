#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

typedef vector<ll> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    ll numSets;
public:
    UnionFind(ll N) {
        p.assign(N, 0); for (ll i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }

    ll numDisjollSets() { return numSets; }      // optional
    ll sizeOfSet(ll i) { return setSize[findSet(i)]; } // optional

    void unionSet(ll i, ll j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        ll x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    char command;
    ll a, b, c;
    cin >> n >> q;
    UnionFind UF(n);
    for (ll i = 0; i < q; i++) {
        cin >> command;
        if (command == 't') {
            cin >> a >> b;
            UF.unionSet(a - 1, b - 1);
        }
        else if (command == 's') {
            cin >> c;
            cout << UF.sizeOfSet(c - 1) << '\n';
        }
    }
}