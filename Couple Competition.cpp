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
    vector<pll> blocks;
    //vector<ll> height;
    stack<pll> left;
    stack<pll> right;
    ll n, h;
    cin >> n;
    vector<pll> lnr(n);
    vector<ll> output(n);
    for (ll i = 0; i < n; i++) {
        cin >> h;
        blocks.push_back({ h, i });
        //height.push_back(h);
    }
    //left higher block
    for (ll i = 0; i < n; i++) {
        if (left.empty()) {
            left.push(blocks[i]);
            lnr[i].first = -1;
        }
        else {
            while (!left.empty() && blocks[i].first >= left.top().first) {
                left.pop();
            }
            if (!left.empty()) {
                lnr[i].first = left.top().second;
                left.push(blocks[i]);
            }
            else {
                lnr[i].first = -1;
                left.push(blocks[i]);
            }
        }
    }
    //right higher block
    for (ll i = n - 1; i >= 0; i--) {
        if (right.empty()) {
            right.push(blocks[i]);
            lnr[i].second = -1;
        }
        else {
            while (!right.empty() && blocks[i].first >= right.top().first) {
                right.pop();
            }
            if (!right.empty()) {
                lnr[i].second = right.top().second;
                right.push(blocks[i]);
            }
            else {
                lnr[i].second = -1;
                right.push(blocks[i]);
            }
        }

    }

    stable_sort(blocks.begin(), blocks.end());
    ll i = n - 1;
    ll max_index = i;
    //for (ll a = n - 1; a >= 0; a--) {
    //    if (blocks[i].first == max) {
    //        max_index = a;
    //    }
    //    else {
    //        break;
    //    }
    //}
    //if (max_index - 1 >= 0) {
    //    max2 = blocks[max_index - 1].first;
    //}
    //else {
    //    max2 = -1;
    //}
    
    //cout << i;
    while (i >= 0) {
        if (blocks[i].first == blocks[max_index].first) { //highest
            output[blocks[i].second] = 0;
            max_index = i;
        }
        else if (max_index > 0 && blocks[i].first == blocks[max_index - 1].first) { //second highest
            output[blocks[i].second] = 1;
        }
        else { //other blocks
            ll leftindex = lnr[blocks[i].second].first; //left taller block of current block
            ll rightindex = lnr[blocks[i].second].second; //right taller block of currrent block
            if (leftindex == -1) { //no left higher block
                output[blocks[i].second] = 1 + output[rightindex];
            }
            else if (rightindex == -1) { //no right higher block
                output[blocks[i].second] = 1 + output[leftindex];
            }
            else if (output[rightindex] < output[leftindex]) {
                output[blocks[i].second] = 1 + output[rightindex];
            }
            else if (output[rightindex] >= output[leftindex]) {
                output[blocks[i].second] = 1 + output[leftindex];
            }
        }
        i--;
    }

    for (auto v : output) {
        cout << v << " ";
    }

}