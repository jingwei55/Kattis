#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;

void makemap(unordered_map<string, char>& convert) {
    convert["clank"] = 'a';
    convert["bong"] = 'b';
    convert["click"] = 'c';
    convert["tap"] = 'd';
    convert["poing"] = 'e';
    convert["clonk"] = 'f';
    convert["clack"] = 'g';
    convert["ping"] = 'h';
    convert["tip"] = 'i';
    convert["cloing"] = 'j';
    convert["tic"] = 'k';
    convert["cling"] = 'l';
    convert["bing"] = 'm';
    convert["pong"] = 'n';
    convert["clang"] = 'o';
    convert["pang"] = 'p';
    convert["clong"] = 'q';
    convert["tac"] = 'r';
    convert["boing"] = 's';
    convert["boink"] = 't';
    convert["cloink"] = 'u';
    convert["rattle"] = 'v';
    convert["clock"] = 'w';
    convert["toc"] = 'x';
    convert["clink"] = 'y';
    convert["tuc"] = 'z';
    convert["whack"] = ' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, char> words;
    makemap(words);
    int N;
    string sound;
    cin >> N;
    bool caps = false;
    vector<char> output;
    for (ll i = 0; i < N; i++) {
        cin >> sound;
        if (sound == "pop") {
            if (!output.empty()) output.pop_back();
        }
        else if (sound == "bump" || sound == "dink" || sound == "thumb") caps = !caps;
        else if (caps) output.push_back(toupper(words.find(sound)->second));
        else if (!caps) output.push_back(words.find(sound)->second);
    }
    for (auto v : output) {
        cout << v;
    }
}
