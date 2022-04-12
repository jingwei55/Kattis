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
const ll MAX = 1e12;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vll fruits, fruit_clearing, fruit_dist;
    pll w_n;
    ll n1, n2, w, f;
    ll reachable = 0;
    ll node, edge, clearing, time, days;
    cin >> node >> edge >> clearing >> time >> days;
    vector<vector<pll>> AL(node, vector<pll>());
    vector<pll>::iterator it;
    while (edge--) {
        cin >> n1 >> n2 >> w;
        AL[n1-1].push_back({ n2-1, w });
        AL[n2 - 1].push_back({ n1 - 1, w }); // bidirectional
    }

    vll dist(node, MAX);
    dist[0] = 0; //clearing one has no distance
    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    pq.push({ 0, 0 });

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        w_n = pq.top(); pq.pop();            // shortest unvisited u
        if (w_n.first > dist[w_n.second]) continue;                   // a very important check
        
        for (it = AL[w_n.second].begin(); it != AL[w_n.second].end(); it++) {                 // all edges from u
            if (dist[w_n.second] + (*it).second >= dist[(*it).first]) continue;        // not improving, skip
            dist[(*it).first] = dist[w_n.second] + (*it).second;                       // relax operation
            pq.push({ dist[(*it).first], (*it).first });                     // enqueue better pair
        }
    }
    while (clearing--) {
        cin >> f;
        fruits.push_back(f-1); //index of clearings with fruit, both reachable + non-reachable
    }

    for (ll i = 0; i < fruits.size(); i++) {
        if (dist[fruits[i]] != MAX) {
            reachable++;
            fruit_clearing.push_back(fruits[i]); //only get reachable clearings with fruit
        }
    }

    for (ll i = 0; i < fruit_clearing.size(); i++) {
        fruit_dist.push_back(dist[fruit_clearing[i]]); //distance to reachable fruit clearings
    }


    stable_sort(fruit_dist.begin(), fruit_dist.end());
    if (reachable >= days && days < time) { //more clearings than days    
        cout << fruit_dist[days-1] * 2;
    }
    else if (reachable >= time) { //regrow faster than it takes to clear all clearings
        cout << fruit_dist[time-1] * 2;
    }
    else {
        cout << -1;
    }

    //cout << reachable;
   /* for (auto v : dist) {
        cout << v;
    }*/
}