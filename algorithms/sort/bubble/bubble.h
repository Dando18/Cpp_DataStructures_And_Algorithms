#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <vector>

namespace alg {

template <typename T>
void bubbleSort(std::vector<T>& v) {
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = v.size()-1; j > i; --j) {
            if (v[j] < v[j - 1]) {
                // swap v[j] and v[j-1]
                T tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
            }
        }
    }
}

}

#endif