#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

void print(const vector<string>& v) {
    for (auto i : v) 
        cout << i << " ";
    cout << "\n";
}

template<typename IteratorType>
void isort(IteratorType first, IteratorType last) {

    for (IteratorType it = first + 1; it != last; it++) {
        IteratorType jt = it - 1;
        string el = *it;
        while (jt >= first and *jt > el) {
            iter_swap(jt + 1, jt);
            jt--;
        }
        iter_swap(jt + 1, &el);
    }
}

int main() {
    vector<string> v;
    fstream in;
    in.open("plik.txt", ios::in);
    string input;
    while (in >> input) {
        v.push_back(input);
    }
    cout << "Before insertion sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    isort<vector<string>::iterator>(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After insertion sort: \n";
    print(v);
    cout << "Insertion sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}