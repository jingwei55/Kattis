#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, Q;
    string cmd;
    cin >> N >> Q;
    ll s1, s2, s;
    unordered_map<ll, ll> money;
    money[N + 1] = 0;
    //for (ll i = 1; i <= N; i++) { //initialise all to 0 kroners
    //  money[i] = 0;
    //}

    for (int i = 0; i < Q; i++) {
        cin >> cmd;
        if (cmd == "RESTART") {
            money.clear();
            cin >> s;
            money[N + 1] = s;
        }
        else if (cmd == "PRINT") {
            cin >> s;
            if (money.find(s) == money.end()) { //check
                cout << money[N + 1] << '\n';
            }
            else {
                cout << money[s] << '\n';
            }   
        }
        else { //SET
            cin >> s1 >> s2;
            money[s1] = s2;
        }
    }
}