#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dsa/Graph.hpp"
#include <cstddef>

// Simple capture buffer for visit()
static int g_out[256];
static std::size_t g_out_len = 0;

static void reset_capture() {
    g_out_len = 0;
}

static void capture(int v) {
    g_out[g_out_len++] = v;
}

static void check_sequence(const int* expected, std::size_t n) {
    REQUIRE(g_out_len == n);
    for (std::size_t i = 0; i < n; ++i) {
        CHECK(g_out[i] == expected[i]);
    }
}

TEST_CASE("Graph: vertex_count and add_edge undirected") {
    dsa::Graph g(4, false);
    CHECK(g.vertex_count() == 4);

    // basic smoke
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
}

TEST_CASE("BFS order (undirected)") {
    // Graph:
    // 0 - 1 - 3
    // |   |
    // 2 - 4
    dsa::Graph g(5, false);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);

    reset_capture();
    g.bfs(0, capture);

    // With adjacency lists appended in add_edge order:
    // BFS from 0: 0, 1, 2, 3, 4
    const int exp[] = {0, 1, 2, 3, 4};
    check_sequence(exp, 5);
}

TEST_CASE("DFS order (undirected, recursive)") {
    // Same graph as BFS test
    dsa::Graph g(5, false);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);

    reset_capture();
    g.dfs(0, capture);

    // Recursive DFS using neighbor order:
    // 0 -> 1 -> 3 -> back -> 4 -> back -> 2
    const int exp[] = {0, 1, 3, 4, 2};
    check_sequence(exp, 5);
}

TEST_CASE("bfs_all visits disconnected components") {
    // Components:
    // (0-1-2) and (3-4)
    dsa::Graph g(5, false);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    reset_capture();
    g.bfs_all(capture);

    // bfs_all starts at vertex 0, then next unvisited is 3
    const int exp[] = {0, 1, 2, 3, 4};
    check_sequence(exp, 5);
}

TEST_CASE("dfs_all visits disconnected components") {
    dsa::Graph g(5, false);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    reset_capture();
    g.dfs_all(capture);

    // dfs_all: start 0 -> 1 -> 2, then start 3 -> 4
    const int exp[] = {0, 1, 2, 3, 4};
    check_sequence(exp, 5);
}

TEST_CASE("Directed graph affects reachability") {
    // 0 -> 1 -> 2, but no edges back
    dsa::Graph g(3, true);
    g.add_edge(0, 1);
    g.add_edge(1, 2);

    reset_capture();
    g.bfs(2, capture);
    const int exp1[] = {2};
    check_sequence(exp1, 1);

    reset_capture();
    g.bfs(0, capture);
    const int exp2[] = {0, 1, 2};
    check_sequence(exp2, 3);
}

TEST_CASE("Cycles do not cause infinite loops") {
    dsa::Graph g(3, false);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0); // cycle

    reset_capture();
    g.bfs(0, capture);
    CHECK(g_out_len == 3);

    reset_capture();
    g.dfs(0, capture);
    CHECK(g_out_len == 3);
}
