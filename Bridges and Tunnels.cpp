#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
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
    int n;
    string b1, b2;
    int count = 0;
  //  int count2;
    unordered_map <string, int> index;
    cin >> n;
    UnionFind UF(2*n);
    for (int i = 0; i < n; i++) {
        cin >> b1 >> b2;
        if (index.count(b1) == 0) {
            index[b1] = count;
            count++;

        }
        if (index.count(b2) == 0) {
            index[b2] = count;
            count++;
        }
        UF.unionSet(index.find(b1)->second, index.find(b2)->second);
        cout << UF.sizeOfSet(index.find(b1)->second) << '\n';
    }
}