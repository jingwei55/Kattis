#include <iostream>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    int tright = 0;
    int lright = 0;
    int tleft = 0;
    int lleft = 0;
    bool right = false;
    bool left = false;
    string teeth[n];
    char condition[n];
    
    for (int i = 0; i < n; i ++) {
        cin >> teeth[i];
        cin >> condition[i];
        if (condition[i] == 'b') {
            if (teeth[i][0] == '+' || teeth[i][0] == '-' ) {
                left = true;
            } else {
                right = true;
            }
        } else { //if teeth is missing
            if (teeth[i][0] == '+') {
                tleft ++;
            } else if (teeth[i][0] == '-') {
                lleft ++;
            } else if (teeth[i][1] != '+') {
                tright ++;
            } else if (teeth[i][1] != '-') {
                lright ++;
            }
        }
    }
    
    if (left == true && right == true) {
        cout << 2;
    } else if (left == true && tright != 8 && lright != 8) {
        cout << 1;
    } else if (right == true && tleft != 8 && lleft != 8) {
        cout << 0;
    } else {
        cout << 2;
    }
    
    return 0;
    
}