#ifndef _INSERTION_H_
#define _INSERTION_H_

#include <vector>

namespace alg {

template <typename T>
void insertionSort(std::vector<T>& v) {
    int i, key, j;
    for (i = 1; i < v.size(); ++i) {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
};

}  // namespace alg
#endif