//
// Created by marius on 2/19/26.
//

#pragma once
#include <cstddef>

namespace dsa {

    struct SortStats {
        std::size_t comparisons = 0;
        std::size_t swaps = 0;
    };

    // Sorts array a[0..n-1] in non-decreasing order.
    // Returns operation counts (comparisons + swaps).
    template <class T>
    SortStats bubble_sort(T* a, std::size_t n) {
        SortStats st;
        // TODO: implement bubble sort
        // Count:
        // - st.comparisons++ every time you compare two elements
        // - st.swaps++ every time you swap two elements
        (void)a; (void)n;
        return st;
    }

    // Shell sort using gap sequence: n/2, n/4, ..., 1
    template <class T>
    SortStats shell_sort(T* a, std::size_t n) {
        SortStats st;
        // TODO: implement shell sort
        // Count comparisons when you compare elements in the inner loop.
        // Count swaps when you perform a swap OR when you do a move-based swap.
        (void)a; (void)n;
        return st;
    }

} // namespace dsa
