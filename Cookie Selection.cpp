#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <string>
#include <iterator>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    multiset<ll> cookies;
    string com;
    multiset<ll>::iterator it;
    while (cin >> com) {
        if (com == "#") {
            multiset<ll>::iterator median = it;
            cout << *it << " ";
            if (cookies.size() % 2 == 0) --it;
            else ++it;
            cookies.erase(median);
        }
        else {
            cookies.insert(stoi(com));
            if (cookies.size() == 1) it = cookies.begin();
            else {
                if (stoi(com) >= *it and cookies.size() % 2 == 0) { //even
                    ++it;
                }
                if (stoi(com) < *it and cookies.size() % 2 != 0) { //odd
                    --it;
                }
            }
        }
        //for (auto v : cookies) cout << v;
    }

  
}