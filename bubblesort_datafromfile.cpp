#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

void print(const vector<string>& v) {
    for (auto i : v) 
        cout << i << " ";
    cout << "\n";
}

template<typename IteratorType>
void bsort(IteratorType first, IteratorType last) {

    for (IteratorType jt = last; jt != first; --jt) {
        for (IteratorType it = first; it < jt - 1; ++it) {
            if (*it > *(it + 1)) {
                iter_swap(it, it + 1);
            }
        }
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
    cout << "Before bubble sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    bsort<vector<string>::iterator>(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After bubble sort: \n";
    print(v);
    cout << "Bubble sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}