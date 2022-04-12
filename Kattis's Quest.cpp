#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p2;

//struct quest {
//    ll energy;
//    ll gold;
//    bool operator< (const quest& data) const { //make set be properly ordered
//        if (energy == data.energy) {
//            return gold > data.gold;
//        }
//        else {
//            return energy < data.energy;
//        }
//    }
//};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, energy;
    ll cost, gold;
    string com;
    map<ll, priority_queue<ll>> quests;
    map<ll, priority_queue<ll>>::iterator it;
    cin >> N;
    while (N--) {
        cin >> com;
        if (com == "add") {
            cin >> cost >> gold;
            quests[cost].push(gold);
        }
        else if (com == "query") {
            ll gold = 0;
            cin >> energy;
            while (energy > 0 && !quests.empty()) {
                it = quests.upper_bound(energy);
                if (it == quests.begin()) break;
                it--;
                gold += it->second.top();
                it->second.pop();
                energy -= it->first;
                if (it->second.empty()) quests.erase(it);
                /*for (it = quests.begin(); it != quests.end(); it++) {
                    if (it->first < energy) {
                        energy -= it->first;
                        gold += it->second.top();
                        it->second.pop();
                        if (it->second.empty()) {
                            quests.erase(it->first);
                        }
                    }
                }*/
            }
            cout << gold << '\n';
        }
        
    }
}