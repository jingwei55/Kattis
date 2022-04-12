#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<char> output;
    string input;
    getline(cin, input);
    for (ll i = 0; i < input.size(); i++) {
        if (input[i] != '<') {
            output.push_back(input[i]);
        }
        else if (!output.empty()) {
            output.pop_back();
        }
    }

    for (auto v : output) {
        cout << v;
    }
}