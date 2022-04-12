#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <set>
using namespace std;
typedef long long ll;


struct cat {
    ll index;
    ll infect;
    string name;
    bool operator< (const cat &data) const { //make set be properly ordered
        if (infect == data.infect) {
            return index < data.index;
        }
        else {
            return infect > data.infect;
        }
    }
};


int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll commands;
    ll com_type;
    cat data; //store data of the cat entering clinic
    ll infection;
    string catname;
    set<cat> clinic; //store all cat data
    map<string, pair <ll, ll>> prev; //store data for any updates
    set<cat>::iterator it;
    cin >> commands;
    ll cats = 0;

    for (ll i = 0; i < commands; i++) {
        cin >> com_type;

        if (com_type == 0) {
            cin >> catname >> infection;
            data.index = cats;
            data.infect = infection;
            data.name = catname;
            clinic.insert(data);
            prev[catname] = { cats, infection };
            cats++; //increase index counter to ensure priority
        }

        else if (com_type == 1) {
            cin >> catname >> infection;
            data.name = catname;
            data.index = prev[catname].first;
            data.infect = prev[catname].second;
            it = clinic.find(data); //find old cat data
            clinic.erase(it);
            data.infect += infection; 
            clinic.insert(data); //update cat data
            prev[catname].second += infection;
        }

        else if (com_type == 2) {
            cin >> catname;
            data.name = catname;
            data.index = prev[catname].first;
            data.infect = prev[catname].second;
            it = clinic.find(data);
            clinic.erase(it);
        }

        else if (com_type == 3) {
            if (clinic.empty()) {
                cout << "The clinic is empty" << '\n';
            }
            else {
                it = clinic.begin();
                cout << (*it).name << '\n';
            }
        }
    }
}