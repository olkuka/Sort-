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
void shsort(IteratorType first, IteratorType last) {
    auto size = distance(first, last);

    for (int gap = size/2; gap > 0; gap /= 2) {
        for (IteratorType it = first + gap; it != last; it++) {
            for (IteratorType jt = it; (jt - first) >= gap && *(jt - gap) > *(jt); jt -= gap) {
                swap(*(jt - gap), *(jt));
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
    cout << "Before shell sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    shsort<vector<string>::iterator>(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After shell sort: \n";
    print(v);
    cout << "Shell sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}