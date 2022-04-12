#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;

bool sortCoworker(const pair<ll, ll>& a, const pair<ll, ll>& b) { //this will return b NOT a
    /*if (a.first + a.second == b.first + b.second) {
        return a.first > b.first;
    }
    else {*/
        return a.first + a.second > b.first + b.second;
    //}
} 

int main()
{
    ll help;
    ll coworkers;
    cin >> help >> coworkers;
    pair<int, int> data;
    priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, decltype(&sortCoworker)> level(sortCoworker);

    for (int i = 0; i < coworkers; i++) {
        cin >> data.first >> data.second;
        //data.first += data.second;
        level.push(data);
    }
    for (int i = 0; i < help; i++) {
        data = level.top();
        level.pop();
        data.first += data.second;
        level.push(data);
    }

    data = level.top();
    level.pop();
    while (!level.empty()) {
        if (level.top().first > data.first) {
            data = level.top();
        }
        level.pop();
    }
    cout << data.first;
}