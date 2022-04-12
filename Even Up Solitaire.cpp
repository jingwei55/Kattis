#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, card;
    ll sum;
    //vector<ll> cards;
    stack<ll> even;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> card;
        if (!even.empty()) {
            sum = card + even.top();
        }
        even.push(card);
        if (even.size() > 1 && sum % 2 == 0) {
            even.pop();
            even.pop();
        }
    }
    cout << even.size();

}

