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
    stack<ll> high;
    stack<ll> low;
    ll height, h;
    ll max = 0;
    cin >> height;
    vector<ll> hs;
    for (ll i = 0; i < height; i++) {
        cin >> h;
        hs.push_back(h);
    }
    for (ll i = 0; i < height; i++) { //assume have higher peak to the right
        if (high.empty()) {
            high.push(hs[i]);
        }
        else {
            if (low.empty() && hs[i] < high.top()) {
                low.push(hs[i]);
            }
            else if (!low.empty() && hs[i] < low.top()) {
                low.push(hs[i]);
            }
            else if (low.empty() && hs[i] >= high.top()) {
                high.push(hs[i]);
            }
            else if (hs[i] >= high.top()) {
                if (max < high.top() - low.top()) max = high.top() - low.top();
                high.push(hs[i]);
                while (!low.empty()) low.pop(); // reset lowest height
            }
        }
    }
    while (!low.empty()) {
        low.pop();
    }
    while (!high.empty()) {
        high.pop();
    }
    for (ll i = height - 1; i >= 0; i--) { //no higher peak to right, check left
        if (high.empty()) {
            high.push(hs[i]);
        }
        else {
            if (low.empty() && hs[i] < high.top()) {
                low.push(hs[i]);
            }
            else if (!low.empty() && hs[i] < low.top()) {
                low.push(hs[i]);
            }
            else if (low.empty() && hs[i] >= high.top()) {
                high.push(hs[i]);
            }
            else if (hs[i] >= high.top()) {
                if (max < high.top() - low.top()) max = high.top() - low.top();
                high.push(hs[i]);
                while (!low.empty()) low.pop(); // reset lowest height
            }
        }
    }
    cout << max;
}
