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
void ssort(IteratorType first, IteratorType last) {

    IteratorType kt;
    for (IteratorType it = first; it != last - 1; it++) {
        kt = it;
        for (IteratorType jt = it + 1; jt != last; jt++) {
            if(*jt < *kt) iter_swap(kt, jt);
            iter_swap(it, kt);
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
    cout << "Before selection sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    ssort<vector<string>::iterator>(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After selection sort: \n";
    print(v);
    cout << "Selection sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}