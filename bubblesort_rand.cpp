#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define VEC_SIZE 5
#define START_RANGE -100        // zakres liczb do losowania
#define RANGE 200

void fill(std::vector<int>& v) {
    int num;
    for (size_t i = 0; i < VEC_SIZE; i++) {
        num = START_RANGE + rand() % RANGE;
        v.push_back(num);
    }
}

void print(const std::vector<int>& v) {
    for (auto i : v) 
        std::cout << i << " ";
    std::cout << "\n";
}

void bsort(std::vector<int>& v) {

    for (std::vector<int>::const_iterator jt = v.end(); jt != v.begin(); --jt) {
        for (std::vector<int>::iterator it = v.begin(); it < jt-1; ++it) {
            if (*it > *(it + 1)) {
                std::iter_swap(it, it + 1);
            }
        }
    }
}

int main() {
    std::vector<int> v;
    srand(time(NULL));
    fill(v);
    std::cout << "Before bubble sort: \n";
    print(v);
    bsort(v);
    std::cout << "After bubble sort: \n";
    print(v);
    return 0;
}