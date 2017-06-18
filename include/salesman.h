#include <utility>
#include <vector>
#include <cstddef>

namespace salesman {
    int const INF = 1E6 + 10;

    std::pair<int, int>
    nearest_neighbour(const std::vector <std::vector<int>> &graph, size_t count_node,
                                                                   size_t count_edge);

    std::pair<int, int>
    full_search(const std::vector <std::vector<int>> &graph, size_t count_node,
                                                             size_t count_edge);
}
