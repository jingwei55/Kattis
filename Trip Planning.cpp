#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    ll M;
    cin >> N >> M;
    ll index = 1;
    ll element;
    pair<ll, ll> cities;
    pair<ll, ll> final;
    vector<ll> count(N, 0);

    for (ll i = 0; i < M; i++) {
        cin >> cities.first >> cities.second;
        if (N > 2) {
            if (abs(cities.first - cities.second) == 1) { //adjacent
                if (cities.first > cities.second) {
                    element = cities.second;
                }
                else {
                    element = cities.first;
                }
                count[element - 1] += index;
                index++;
            }

            else { //potentially from N to 1
                if ((cities.first == N && cities.second == 1) || (cities.first == 1 && cities.second == N)) {
                    count[N - 1] += index;
                    index++;
                }
            }
        }
        else { //N == 2
            if ((M == 1 && cities.first == 1 && cities.second == 2) || (M == 1 && cities.first == 2 && cities.second == 1)) {
                count = { 1, 1 };
            }
            /*else {
                if (i == 0) {
                    final = cities;
                }
                else {
                    if (cities.first == final.second && cities.second == final.first) {
                        count = { 1, 1 };
                    }
                }
            }*/
            
        }
        
    }

    bool possible = true;
    for (ll i = 0; i < N; i++) {
        if (count[i] == 0) {
            possible = false;
            break;
        }
    }
    if (possible == true) {
        for (ll i = 0; i < N; i++) {
            cout << count[i] << '\n';
        }
    }
    else {
        cout << "impossible";
    }
}
