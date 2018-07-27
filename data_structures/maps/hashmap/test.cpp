#include <iostream>
#include "hashmap.h"

using namespace dat;

int main(int argc, char* argv[]) {

    HashMap<std::string, int> employeeAges;

    employeeAges.add("Jimothy", 5);
    employeeAges.add("Craig", 6);

    employeeAges["Jimothy"] = 5;
    std::cout << employeeAges["Craig"] << std::endl;
    return 0;
}