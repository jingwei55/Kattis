#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

void steps(vector<vector<ll>> acells, vector<vector<ll>> student_pos, vector<ll>& distance, ll S) {
    ll i = 0;
    ll j = 0;
    ll num;
    while (i < S) {
        
        if (student_pos[i][0] == acells[j][0]) {
            num = abs(student_pos[i][2] - acells[j][1]) + abs(student_pos[i][3] - acells[j][2]);
            distance[i] = num;
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    
}

ll total_steps(vector<ll> T_value, vector<ll>& distance, ll a, ll b, ll c) { //goes into faculty_steps array
    ll sum = 0;
    stable_sort(distance.begin() + a, distance.begin() + b); //sort steps by faculty
    for (int i = 0; i < T_value[c]; i++) {
        sum += distance[i + a];
    }
    return sum; //sum of steps per faculty
}

void sum(vector<ll>& faculty_steps, ll G) {
    ll total = 0;
    stable_sort(faculty_steps.begin(), faculty_steps.end());
    //total = accumulate(faculty_steps.begin(), faculty_steps.begin() + G, 0);
    for (ll i = 0; i < G; i++) {
        total += faculty_steps[i];
    }
    cout << total;
}
int main()
{
    ll R, C, F, S, G, f_num, x, y, s_num, f_x;
    cin >> R >> C >> F >> S >> G;
    vector<vector<ll>> acells;
    vector<vector<ll>> student_pos;
    vector<ll> T_value;
    vector<ll> distance(S);
    vector<ll> faculty_steps;
    vector<ll> counter;

    for (ll i = 0; i < F; i++) {
        cin >> f_num;
        for (ll j = 0; j < f_num; j++) {
            vector<ll> xi;
            cin >> x >> y;
            xi.push_back(i + 1); //faculty name at the start
            xi.push_back(x);
            xi.push_back(y);
            acells.push_back(xi); //2D array of all the coords
        }

    }

    for (ll i = 0; i < S; i++) {
        vector<ll> c;
        cin >> x >> y >> s_num >> f_x;
        c.push_back(f_x); //faculty number
        c.push_back(s_num); //student ID
        c.push_back(x);
        c.push_back(y);
        student_pos.push_back(c); //studentID then their current position
    }

    for (ll i = 0; i < F; i++) {
        ll t;
        cin >> t;
        T_value.push_back(t);
    }

    stable_sort(student_pos.begin(), student_pos.end());
    stable_sort(acells.begin(), acells.end());

    ll index = 0;
    ll fac = 1;
    ll coo = 0;
    while (index < S) {
        if (student_pos[index][0] == fac) {
            coo++;
            index++;
        }
        else {
            counter.push_back(coo);
            coo = 0;
            fac++;
        }
    }
    counter.push_back(coo); // count number of students per faculty

    steps(acells, student_pos, distance, S); 

    ll a = 0;
    ll b = counter[0];
    for (ll i = 0; i < F; i++) {
        ll step = total_steps(T_value, distance, a, b, i);
        faculty_steps.push_back(step);
        if (i + 1 < F) {
            a = b;
            b += counter[i + 1];
        }
    }
    //for (int i = 0; i < 7; i++) {
    //  for (int j = 0; j < 3; j++) {
    //      cout << acells[i][j];
    //  }
    //}
    //for (int i = 0; i < S; i++) {
    //  cout << distance[i];
    //}

    sum(faculty_steps, G);

}