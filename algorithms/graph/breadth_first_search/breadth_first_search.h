#ifndef _BREADTH_FIRST_SEARCH_H_
#define _BREADTH_FIRST_SEARCH_H_

#include <vector>
#include <deque>
#include <cstdio>

namespace alg {


bool breadth_first_search(const std::vector<std::vector<int> >& adj, int start, int target, std::vector<int>& path, bool verbose) {

    // if we're looking for the start of the search then our job is easy
    if (start == target) {
        path.clear();
        path.push_back(start);
        if (verbose) printf("visiting %d\n", start);
        return true;
    }

    std::vector<bool> visited (adj.size(), false);
    std::deque<int> to_visit;
    std::map<int, int> previous_elements (adj.size());
    bool found = false;
    
    to_visit.push_back(start);

    while (to_visit.size() != 0 && !found) {
        int cur_node = to_visit.front();
        to_visit.pop_front();
        visited[cur_node] = true;
        
        for (int i = 0; i < adj[cur_node].size(); ++i) {
            int adjacent_node = adj[cur_node][i];
            if (visited[adjacent_node]) continue;
            visited[adjacent_node] = true;

            if (adjacent_node == target) {
                found = true;
                break;
            } else {
                to_visit.push_back(adjacent_node);
            }

        }

        if (verbose) { 
            printf("visiting: %d deque:", cur_node);
            for (std::deque<int>::iterator it = to_visit.begin(); it != to_visit.end(); it++) printf(" %d", *it);
            printf("\n");
        }
    }
    
    return found;
}


} // namespace alg

#endif
