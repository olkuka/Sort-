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
void merge(IteratorType first, IteratorType last) {
    IteratorType mid = first + distance(first, last) / 2;

    vector<string> temp;
    IteratorType it1 = first;
    IteratorType it2 = mid + 1;

    while (it1 <= mid && it2 <= last) {
        if (*it1 < *it2) {
            temp.push_back(*it1);
            it1++;
        }
        else {
            temp.push_back(*it2);
            it2++;
        }
    }

    if (it1 > mid) {
        while (it2 <= last) {
            temp.push_back(*it2);
            it2++;
        }
    }
    else {
        while(it1 <= mid) {
            temp.push_back(*it1);
            it1++;
        }
    }

    int i = 0;
    for (IteratorType jt = first; jt != last; jt++) {
        *(jt) = temp.at(i);
        i++;
    }
    
}

void msort(auto first, auto last) {
    auto mid = first + distance(first, last) / 2;
    if(first < mid) msort(first, mid);
    if(mid < last) msort(mid + 1, last);
    merge(first, last);
}

int main() {
    vector<string> v;
    fstream in;
    in.open("plik.txt", ios::in);
    string input;
    while (in >> input) {
        v.push_back(input);
    }
    cout << "Before merge sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    msort(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After merge sort: \n";
    print(v);
    cout << "Merge sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}