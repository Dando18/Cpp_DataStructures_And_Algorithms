#include <iostream>
#include <vector>
#include "bubble.h"

using namespace alg;

int main(int argc, char* argv[]) {

    std::vector<int> vals = {3, 2, 1, 5, 4, 8, 7, 6};
    for (int i : vals) std::cout << i << " ";
    std::cout << "\n";

    std::cout << "sorting...\n";
    bubbleSort(vals);

    for (int i : vals) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}