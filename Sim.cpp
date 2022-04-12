#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    int input;
    string letter;
    //char a;
    cin >> input;
    //cin >> a;
    getline(cin, letter);
    

    for (int j = 0; j < input; j++) {
        getline(cin, letter);
        list<char> sentence;
        list<char>::iterator place = sentence.end(); //by default put at end/last position of list
        int i = 0;
        while (i < letter.length()) {
            if ((letter[i] == '<' && sentence.empty()) || (letter[i] == '<' && place == sentence.begin())) { //if sentence empty or iterator at start do nth
                i++;
                i--;
            }
            else if (letter[i] == '<' && !sentence.empty() || (letter[i] == '<' && place != sentence.begin())) { //if have characters to delete then delete
                list<char>::iterator place2 = place;
                place2--; //delete previous element
                sentence.erase(place2); 
            }
            else if (letter[i] == '[') {
                place = sentence.begin(); 
            }
            else if (letter[i] == ']') {
                place = sentence.end();
            }
            else {
                sentence.insert(place, letter[i]); //add character at iterator position
            }
            i++;
        }
        for (auto v : sentence) {
            cout << v;
        }
        cout << endl;

    }

}