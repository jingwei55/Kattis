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
    unordered_set<string> names;
    unordered_map<string, ll> nickname;
    vector<string> nickname2;
    ll n1, n2;
    cin >> n1;
    string value;
    while (n1--) {
        cin >> value;
        names.insert(value);
    }
    cin >> n2;
    while (n2--) {
        cin >> value;
        nickname[value] = 0;
        nickname2.push_back(value);
    }
    unordered_set<string>::iterator it;
    for (it = names.begin(); it != names.end(); it++) {
        ll length = (*it).size();
        for (ll i = 1; i <= length; i++) {
            string nick = (*it).substr(0, i);
            if (nickname.count(nick) == 1) nickname[nick] += 1;
        }
    }
    for (ll i = 0; i < nickname2.size(); i++) {
        cout << nickname[nickname2[i]] << '\n';
    }
}