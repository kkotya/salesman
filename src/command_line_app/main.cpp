#include <iostream>
#include <vector>
#include <algorithm>

#include <salesman.h>

int main() {
    size_t count_node;
    std::cin >> count_node;
    size_t count_edge;
    std::cin >> count_edge;
    std::vector<std::vector<int>> graph(count_node + 1);
    for (int i = 0; i <= count_node; ++i) {
        for (int j = 0; j <= count_node; ++j) {
            graph[i].push_back(0);
        }
    }
    int u, v, w;
    for (int i = 0; i < count_edge; ++i) {  // заполняем матрицу смежности для графа
        std::cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    std::cout << "Which method should to use:\n (0) to full search\n (1) to nearest neighbour\n";
    int method;
    std::cin >> method;
    while (method < 0 || method > 1) {
        std::cout << "Invalid option. Try one more time.\n";
        std::cin >> method;
    }

    std::pair<int, int> res;
    if (method == 0) {
        auto res_m0 = salesman::full_search(graph, count_node, count_edge);
        std::swap(res_m0, res);
    } else {
        auto res_m1 = salesman::nearest_neighbour(graph, count_node, count_edge);
        std::swap(res_m1, res);
    }

    int min_sum_with_return = res.first;
    int min_sum_without_return = res.second;
    if (min_sum_without_return == salesman::INF && min_sum_with_return == salesman::INF) {
        std::cout << "the way does not exist\n";
    }
    else if (min_sum_without_return == salesman::INF) {
        std::cout << "the length of the way with return " << min_sum_with_return << "\n";
    }
    else {
        std::cout << "the length of the way without return " << min_sum_without_return << "\n";
    }
}

