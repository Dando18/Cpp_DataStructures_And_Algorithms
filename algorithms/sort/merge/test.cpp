#include <iostream>
#include <vector>
#include "merge.h"

using namespace alg;

int main(int argc, char* argv[]) {

    std::vector<int> nums = {5, 3, 1, 4, 2, 6};
    for (int i : nums) 
        std::cout << i << " ";
    std::cout << "\n";

    mergeSort(nums);

    for (int i : nums) 
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}