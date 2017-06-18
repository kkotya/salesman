#include "salesman.h"

#include <algorithm>
#include <set>

namespace salesman {
    std::pair<int, int>
    nearest_neighbour(const std::vector <std::vector<int>> &graph_vec, size_t count_node,
                                                                       size_t count_edge) {
        int u, v, w;
        int min_edge = INF;
        int first, second;
        if (count_node == 1) {
            return std::make_pair(0, 0);
        }
        if (count_edge != count_node * (count_node - 1) / 2) {
            return std::make_pair(-1, -1);
        }
        std::vector < std::set < std::pair < int, int >> > graph(count_node + 1);
        for (int i = 1; i <= count_node; ++i) {
            for (int j = i + 1; j <= count_node; ++j) {
                if (graph_vec[i][j] == 0) {
                    continue;
                }
                u = i;
                v = j;
                w = graph_vec[i][j];
                if (w < min_edge) {
                    min_edge = w;
                    first = u;
                    second = v;
                }
                graph[u].insert(std::make_pair(w, v));
                graph[v].insert(std::make_pair(w, u));
            }
        }
        std::vector<bool> visited(count_node + 1, false);
        std::vector<int> way;
        way.push_back(first);
        visited[first] = true;
        way.push_back(second);
        visited[second] = true;
        int length_way = min_edge;
        std::vector < std::set < std::pair < int, int >> >::iterator it;
        for (int i = 1; i <
                        count_node; ++i) {
            v = way[i];
            auto it = graph[v].begin();
            if (i < count_node - 1) {
                while (visited[it->second]) {
                    ++it;
                }
                way.push_back(it->second);
                visited[it->second] = true;
                length_way += it->first;
            } else {
                while (it->second !=
                       way[0]) {
                    ++it;
                }
                length_way += it->first;
            }
        }
        return std::make_pair(length_way, length_way);
    }

    std::pair<int, int>
    full_search(const std::vector <std::vector<int>> &graph, size_t count_node,
                                                             size_t count_edge) {
        std::vector<int> permutations;  // в std::vector<int> permutations генерируем и храним всевозможные перестановки
                                                            // всех вершин от 1 до count_node
        for (int i = 0; i < count_node; ++i) {  // сохраняем начальную последовательность от 1 до node_count
            permutations.push_back(i + 1);
        }
        int min_sum_with_return = INF;
        int min_sum_without_return = INF;
        int cur_sum;
        do {
            cur_sum = 0;  // длина пути для текущей перестановки вершин
            for (int i = 1; i < count_node; ++i) {
                int I = permutations[i];  // i - ое значение в текущей перестановке
                int I_ = permutations[i - 1];  // (i - 1) - ое значение в текущей перестановке
                if (!graph[I][I_]) {  // если нет ребра между i и (i-1) вершиной, пути не существует
                    cur_sum = INF;
                    break;
                }
                else {
                    cur_sum += graph[I][I_];
                }
            }
            int last_node = permutations[count_node - 1];  // последняя
            int first_node = permutations[0];  // и первая вершины в текущей i - ой перестановке
            if (graph[first_node][last_node]) {  // если есть ребро между последней и первой вершинами
                                                 // в текущей перестановке
                if (cur_sum + graph[first_node][last_node] < min_sum_with_return) {  // если нужно, заменяем длину минимального пути с возвратом
                    min_sum_with_return = cur_sum + graph[first_node][last_node];
                }
            }
            else {  // если ребра нет
                if (cur_sum + graph[first_node][last_node] < min_sum_without_return) {  // если нужно, заменяем длину
                                                                                        // минимального пути без возврата
                    min_sum_without_return = cur_sum + graph[first_node][last_node];
                }
            }
        } while (std::next_permutation(permutations.begin(), permutations.end()));
        return std::make_pair(min_sum_with_return, min_sum_without_return);
    };
}