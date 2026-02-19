#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dsa/Sorting.hpp"
#include <cstddef>

static bool is_sorted_non_decreasing(const int* a, std::size_t n) {
    for (std::size_t i = 1; i < n; ++i)
        if (a[i - 1] > a[i]) return false;
    return true;
}

TEST_CASE("Quicksort: empty and size 1") {
    int a0[] = {};
    dsa::quicksort(a0, 0);
    CHECK(true);

    int a1[] = {42};
    dsa::quicksort(a1, 1);
    CHECK(is_sorted_non_decreasing(a1, 1));
}

TEST_CASE("Quicksort: sorts random values") {
    int a[] = {5, 1, 9, 3, 7, 2, 8, 6, 4};
    dsa::quicksort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("Quicksort: already sorted") {
    int a[] = {1,2,3,4,5,6,7,8,9};
    dsa::quicksort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("Quicksort: reverse sorted") {
    int a[] = {9,8,7,6,5,4,3,2,1};
    dsa::quicksort(a, 9);
    CHECK(is_sorted_non_decreasing(a, 9));
}

TEST_CASE("Quicksort: duplicates") {
    int a[] = {3, 1, 2, 3, 3, 0, 2, 1};
    dsa::quicksort(a, 8);
    CHECK(is_sorted_non_decreasing(a, 8));
}

TEST_CASE("partition: returns valid pivot index and partitions correctly (Lomuto expected)") {
    // This test assumes Lomuto pivot = arr[high]
    int a[] = {4, 2, 7, 3, 6, 1, 5};
    int low = 0, high = 6;
    int pivotValue = a[high];

    int p = dsa::partition(a, low, high);

    CHECK(p >= low);
    CHECK(p <= high);
    CHECK(a[p] == pivotValue);

    // All left <= pivot, all right > pivot (Lomuto typical)
    for (int i = low; i < p; ++i) CHECK(a[i] <= pivotValue);
    for (int i = p + 1; i <= high; ++i) CHECK(a[i] > pivotValue);
}
