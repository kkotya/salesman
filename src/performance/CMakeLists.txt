set(PERF_SRC_LIST main.cpp)
add_executable( PERF_MESUARE ${PERF_SRC_LIST})
target_link_libraries( PERF_MESUARE SALESMAN_LIB)
