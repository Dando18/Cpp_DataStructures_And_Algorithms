#ifndef _MERGE_H_
#define _MERGE_H_

#include <vector>

namespace alg {

template <typename T>
void _merge(std::vector<T>& list, int low, int high, int mid) {
    std::vector<T> tmp(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;

    // merge into tmp
    while (i <= mid && j <= high) {
        if (list[i] < list[j]) {
            tmp[k] = list[i];
            k++;
            i++;
        } else {
            tmp[k] = list[j];
            k++;
            j++;
        }
    }

    // move values from i to mid into tmp
    while (i <= mid) {
        tmp[k] = list[i];
        k++;
        i++;
    }

    // move values from j on into tmp
    while (j <= high) {
        tmp[k] = list[j];
        k++;
        j++;
    }

    // move now sorted elements from
    // tmp to list
    for (i = low; i <= high; ++i) {
        list[i] = tmp[i - low];
    }
}

template <typename T>
void _mergeSort(std::vector<T>& list, int low, int high) {
    int mid = 0;
    if (low < high) {
        mid = (low + high) / 2;

        // divide data into halves
        _mergeSort(list, low, mid);
        _mergeSort(list, mid + 1, high);

        // merge the two lists
        _merge(list, low, high, mid);
    }
}

    

    template <typename T>
    void mergeSort(std::vector<T>& list) {
        if (list.size() <= 1) return;
        _mergeSort(list, 0, list.size() - 1);
    }
}

#endif