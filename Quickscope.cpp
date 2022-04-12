#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iterator>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    string types;
    vector < unordered_map<string, string> > brackets;
    unordered_map<string, string> code;
    unordered_map<string, vector<ll>> record;
    unordered_map<string, vector<ll>>::iterator it;
    pair <string, string> value;
    string key;
    ll index = 0;
    ll last_value;
    string first;
    brackets.push_back(code);
    for (ll i = 0; i < N; i++) {
        cin >> types;
        if (types == "{") {
            code.clear();
            brackets.push_back(code);
            index++;
        }
        else if (types == "}") {
            index--;
            for (auto& v : brackets.back()) { //for all mapping in just popped bracket index
                it = record.find(v.first); //index of declaration
                if (it->second.back() > index) { //last declaration already popped
                    it->second.pop_back();
                }
            }
            brackets.pop_back();
        }

        else if (types == "DECLARE") {
            cin >> value.first >> value.second;
            if (brackets[index].count(value.first) == 1) { //key declared before
                cout << "MULTIPLE DECLARATION";
                break;
            }
            else {
                brackets[index][value.first] = value.second;
                record[value.first].push_back(index);
            }

        }
        else if (types == "TYPEOF") {
            cin >> key;
            if (!record[key].empty()) {
                last_value = record[key].back();
                cout << brackets[last_value].find(key)->second << '\n';
            }
            else {
                cout << "UNDECLARED" << '\n';
            }
        }
    }
}
