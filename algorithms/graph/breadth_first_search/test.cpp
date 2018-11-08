#include <vector>
#include <cstdio>
#include "breadth_first_search.h"
using namespace alg;

int main(int argc, char** argv) {

    // adjacency list
    std::vector<std::vector<int> > adj { {1,3}, {0,2,6}, {1,5}, {0,4}, {3,5}, {2,6,7}, {1,5,9}, {5,8}, {7,10}, {6,10}, {9,8} };
    int start = 0;
    int target = 8;
    std::vector<int> path;
    bool verbose = true;

    breadth_first_search(adj, start, target, path, verbose);

    for (int i = 0; i < path.size(); ++i)
        printf ("%d%s", path[i], (i==path.size()-1)?"\n":" --> ");

    return 0;
}
