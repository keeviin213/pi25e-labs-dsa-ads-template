#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dsa/Heap.hpp"
#include "dsa/Sorting.hpp"
#include <cstddef>

static bool is_sorted_non_decreasing(const int* a, int n) {
    for (int i = 1; i < n; ++i) if (a[i-1] > a[i]) return false;
    return true;
}

TEST_CASE("Heap: push/top/pop basic") {
    dsa::Heap<int> h;
    CHECK(h.empty());
    CHECK(h.size() == 0);
    CHECK_THROWS_AS(h.top(), std::out_of_range);
    CHECK_THROWS_AS(h.pop(), std::out_of_range);

    h.push(10);
    CHECK_FALSE(h.empty());
    CHECK(h.top() == 10);

    h.push(5);
    CHECK(h.top() == 10);

    h.push(20);
    CHECK(h.top() == 20);

    h.pop(); // remove 20
    CHECK(h.top() == 10);

    h.pop(); // remove 10
    CHECK(h.top() == 5);

    h.pop(); // remove 5
    CHECK(h.empty());
}

TEST_CASE("Heap: repeated pop produces descending order") {
    dsa::Heap<int> h;
    int vals[] = {4, 1, 7, 3, 8, 5, 2, 6};
    for (int x : vals) h.push(x);

    int out[8];
    for (int i = 0; i < 8; ++i) {
        out[i] = h.top();
        h.pop();
    }

    // out should be descending
    for (int i = 1; i < 8; ++i) CHECK(out[i-1] >= out[i]);
}

TEST_CASE("build_heap creates valid max-heap (spot-check top)") {
    int a[] = {3, 1, 6, 5, 2, 4};
    dsa::build_heap(a, 6);
    CHECK(a[0] == 6); // max should be at root
}

TEST_CASE("heapsort sorts random values") {
    int a[] = {5, 1, 9, 3, 7, 2, 8, 6, 4};
    dsa::heapsort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("heapsort sorts already sorted") {
    int a[] = {1,2,3,4,5,6,7,8,9};
    dsa::heapsort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("heapsort sorts reverse sorted") {
    int a[] = {9,8,7,6,5,4,3,2,1};
    dsa::heapsort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("heapsort sorts duplicates") {
    int a[] = {3, 1, 2, 3, 3, 0, 2, 1};
    dsa::heapsort(a, 8);
    CHECK(is_sorted_non_decreasing(a, 8));
}