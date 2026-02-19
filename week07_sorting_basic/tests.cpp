#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dsa/Sorting.hpp"
#include <cstddef>

static bool is_sorted_non_decreasing(const int* a, std::size_t n) {
    for (std::size_t i = 1; i < n; ++i)
        if (a[i-1] > a[i]) return false;
    return true;
}

TEST_CASE("Bubble sort: empty and size 1") {
    int a0[] = {};
    auto st0 = dsa::bubble_sort(a0, 0);
    CHECK(st0.comparisons == 0);
    CHECK(st0.swaps == 0);

    int a1[] = {42};
    auto st1 = dsa::bubble_sort(a1, 1);
    CHECK(is_sorted_non_decreasing(a1, 1));
    CHECK(st1.comparisons == 0);
    CHECK(st1.swaps == 0);
}

TEST_CASE("Bubble sort: sorts correctly") {
    int a[] = {5, 1, 4, 2, 8};
    auto st = dsa::bubble_sort(a, 5);
    CHECK(is_sorted_non_decreasing(a, 5));
    CHECK(st.comparisons > 0);
}

TEST_CASE("Bubble sort: already sorted does 0 swaps (if optimized or not?)") {
    // Even without early-exit optimization, swaps should be 0.
    int a[] = {1,2,3,4,5};
    auto st = dsa::bubble_sort(a, 5);
    CHECK(is_sorted_non_decreasing(a, 5));
    CHECK(st.swaps == 0);
    CHECK(st.comparisons > 0);
}

TEST_CASE("Shell sort: empty and size 1") {
    int a0[] = {};
    auto st0 = dsa::shell_sort(a0, 0);
    CHECK(st0.comparisons == 0);
    CHECK(st0.swaps == 0);

    int a1[] = {42};
    auto st1 = dsa::shell_sort(a1, 1);
    CHECK(is_sorted_non_decreasing(a1, 1));
    CHECK(st1.comparisons == 0);
    CHECK(st1.swaps == 0);
}

TEST_CASE("Shell sort: sorts correctly") {
    int a[] = {9, 8, 3, 7, 5, 6, 4, 1};
    auto st = dsa::shell_sort(a, 8);
    CHECK(is_sorted_non_decreasing(a, 8));
    CHECK(st.comparisons > 0);
}

TEST_CASE("Shell sort vs Bubble sort: shell should use fewer swaps on a typical case") {
    // Not a strict theoretical guarantee for all arrays, but for this input it should.
    int b1[] = {9, 8, 3, 7, 5, 6, 4, 1};
    int b2[] = {9, 8, 3, 7, 5, 6, 4, 1};

    auto sb = dsa::bubble_sort(b1, 8);
    auto ss = dsa::shell_sort(b2, 8);

    CHECK(is_sorted_non_decreasing(b1, 8));
    CHECK(is_sorted_non_decreasing(b2, 8));

    CHECK(ss.swaps <= sb.swaps);
}
