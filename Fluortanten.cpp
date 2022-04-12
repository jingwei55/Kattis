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
vll visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> queue;
    ll kids, child, chappy, max, newmax;
    ll inihappy = 0;
    cin >> kids;
    while (kids--) {
        cin >> child;
        if (child != 0)
        queue.push_back(child);
    }
    //for (auto v : queue) cout << v;
    for (ll i = 0; i < queue.size(); i++) {
        chappy = (i+1) * queue[i];
        inihappy += chappy;
    }
    max = inihappy;
    for (ll i = queue.size() - 1; i >= 0; i--) {
        inihappy += queue[i];
        if (max < inihappy) {
            max = inihappy;
        }
        //cout << max;
    }
    
cout << max;

}