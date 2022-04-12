#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ll num;
    string w;
    list<string> w2;
    cin >> num;
    getline(cin, w);
    vector<list<string>> words;
    for (ll i = 0; i < num; i++) {
        getline(cin, w);
        w2.push_back(w);
        words.push_back(w2);//vector of lists
        w2.pop_back();
    }

    ll finalindex = 0;
    for (ll i = 1; i < num; i++) {
        ll index1;
        ll index2;
        cin >> index1;
        cin >> index2;
        index1--;
        index2--;
        list<string>::iterator place = words[index1].end();
        words[index1].splice(place, words[index2]);
        if (i == num - 1) {
            finalindex = index1;
        }
    }
    
    for (auto v : words[finalindex]) {
        cout << v;
    }
}
