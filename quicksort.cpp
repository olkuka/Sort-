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

/*template<typename IteratorType>
void qsort(IteratorType first, IteratorType last) {

    IteratorType it = first, jt = last;
    IteratorType pivot = first + distance(first, last)/2;
    do {
        while (*it < *pivot) it++;
        while (*jt > *pivot) jt--;
        if (it <= jt) {
            iter_swap(it, jt);
            it++;
            jt--;
        }
    } while (it <= jt);

    if(first < jt) qsort(first, jt);
    if(last > it) qsort(it, last);
}*/

template<typename IteratorType>
IteratorType partition(IteratorType first, IteratorType last) {
    IteratorType pivot = last;
    IteratorType it = first;
    for (IteratorType jt = first; jt != last; jt++) {
        if (*jt < *pivot) {
            iter_swap(it, jt);
            it++;
        }
    }
    iter_swap(it, last);
    return it;
}

template<typename IteratorType>
void quicksort(IteratorType first, IteratorType last) {
    if(first < last) {
        IteratorType p = partition<vector<string>::iterator>(first, last);
        quicksort(first, p);
        quicksort(p, last);
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
    cout << "Before quick sort: \n";
    print(v);
    auto t1 = chrono::high_resolution_clock::now();
    quicksort<vector<string>::iterator>(v.begin(), v.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "After quick sort: \n";
    print(v);
    cout << "Quick sort duration: " << dt.count() << " milisekund.\n";

    in.close();
    return 0;
}