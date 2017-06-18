#include "salesman.h"

#include <ctime>
#include <complex>
#include <iostream>
#include <fstream>

#include <vector>

#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE salesman_func_test

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TEST_SALESMAN)

    BOOST_AUTO_TEST_CASE(nearestWithReturnTest) {
        std::vector<std::vector<int>> data = {{0, 0, 0, 0, 0},
                                              {0, 0, 1, 100, 4},
                                              {0, 1, 0, 2, 100},
                                              {0, 100, 2, 0, 3},
                                              {0, 4, 100, 3, 0}};
        size_t edges_num = 6;
        size_t nodes_num = 4;
        auto res = salesman::nearest_neighbour(data, nodes_num, edges_num);
        int min_with = res.first;
        int min_without = res.second;
        BOOST_CHECK_EQUAL(min_with, 10);
    }


    BOOST_AUTO_TEST_CASE(fullWithReturnTest) {
            std::vector<std::vector<int>> data = {{0, 0, 0, 0, 0},
                                                  {0, 0, 1, 100, 4},
                                                  {0, 1, 0, 2, 100},
                                                  {0, 100, 2, 0, 3},
                                                  {0, 4, 100, 3, 0}};
        size_t edges_num = 6;
        size_t nodes_num = 4;
        auto res = salesman::full_search(data, nodes_num, edges_num);
        int min_with = res.first;
        int min_without = res.second;
        BOOST_CHECK_EQUAL(min_with, 10);
    }


BOOST_AUTO_TEST_SUITE_END()
