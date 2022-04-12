#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std; 
template<class T> 
class ListArray {
private:
    int N;
    T A[2001];
public:
    ListArray() : N(0) {}
    T get(int i) { //get name at the index of the array
        return A[i];
    }
    int search(T v) { //search for name, get index
        for (int i = 0; i < N; ++i)
            if (A[i] == v)
                return i;
        return -1;
    }
    void insert(int i, T v) { //insert new name at that index
        if ((N == 2001) || (i < 0) || (i > N)) return;
        for (int j = N - 1; j >= i; j--)
            // for (int j = i; j <= N-1; ++j) 
            A[j + 1] = A[j];
        A[i] = v;
        ++N;
    }
    void remove(int i) { //remove name at that index, reduce size of array
        for (int j = i; j < N - 1; ++j)
            A[j] = A[j + 1];
        --N;
    }
    void printList() {
        for (int i = 0; i < N; ++i)
            cout << A[i] << '\n';
    }
    void initialise() {
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
    }
    void counter(int i) {
        for (int j = 0; j < i; ++j) {
            N++;
        }
    }
};

    int main() {
        int people, events, pos;
        string word, name1, name2;
        cin >> people;
        ListArray<string>* queue = new ListArray<string>();
        queue->counter(people);
        queue->initialise();
        //queue->printList(); works

        cin >> events;
        for (int i = 0; i < events; ++i) {
            cin >> word;
            if (word == "cut") {
                cin >> name1; //name of person that cut queue
                cin >> name2; //name of person being cut
                pos = queue->search(name2);
                queue->insert(pos, name1);
            }
            else if (word == "leave") {
                cin >> name2; //name of person leaving
                pos = queue->search(name2);
                queue->remove(pos);
            }
        }

        queue->printList();
        return 0;
    }