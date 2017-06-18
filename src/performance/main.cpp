#include "salesman.h"

#include <ctime>
#include <complex>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

const double EPS = 1e6 + 7;
const bool LOG_SCALE = true;
std::string path_to_test_folder;

typedef std::pair<std::vector<std::vector<int>>, size_t> test_pair;

test_pair
read_test(size_t n) {
    std::string file_name = "test" + std::to_string(n);
    std::ifstream fin(path_to_test_folder + "/" + file_name);
    size_t count_node;
    fin >> count_node;
    size_t count_edge;
    fin >> count_edge;
    std::vector<std::vector<int>> graph(count_node + 1);
    for (int i = 0; i <= count_node; ++i) {
        for (int j = 0; j <= count_node; ++j) {
            graph[i].push_back(0);
        }
    }
    int u, v, w;
    for (int i = 0; i < count_edge; ++i) {  // заполняем матрицу смежности для графа
        fin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    fin.close();
    return make_pair(graph, count_node);
}

template <typename TMethod>
double time_measure(test_pair& test_data,
                    TMethod func) {
    std::clock_t timer = std::clock();
    auto result = func(test_data.first, test_data.second,
                                        test_data.second * (test_data.second - 1) / 2);
    double time = 1e3 * static_cast<double>(std::clock() - timer) / CLOCKS_PER_SEC;
    if (LOG_SCALE)
        time = std::log2(time);
    return time;
}

void log_measures(std::vector<double>& measures,
                  std::vector<int>& dataset_sizes,
                  std::string name) {
    std::ofstream fout(path_to_test_folder + "/" + name + ".csv");
    for (size_t i = 0; i < measures.size(); ++i) {
        fout <<  dataset_sizes[i] << "; " << measures[i] << "\n";
    }
    fout.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: enter the path to folder with tests (performance test data)\n"
                  << argv[0] << " <PATH to tests>" << std::endl;
        return 1;
    }
    std::ios::sync_with_stdio(false);
    path_to_test_folder = argv[1];
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<double> slow_measures;
    std::vector<double> fast_measures;
    for (auto test_size : vec) {
        auto test = read_test(test_size);
        auto slow_res = time_measure(test, salesman::full_search);
        auto fast_res = time_measure(test, salesman::nearest_neighbour);

        slow_measures.push_back(slow_res);
        fast_measures.push_back(fast_res);
    }
    log_measures(slow_measures, vec, "full search");
    log_measures(fast_measures, vec, "nearest neighbour");
}