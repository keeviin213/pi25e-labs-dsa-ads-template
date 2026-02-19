//
// Created by marius on 2/19/26.
//

#pragma once
#include <cstddef>

namespace dsa {

    // Choose ONE partition scheme and implement correctly.
    // We recommend Lomuto: pivot = arr[high]
    template <class T>
    int partition(T* arr, int low, int high) {
        // TODO
        (void)arr; (void)low; (void)high;
        return low;
    }

    template <class T>
    void quicksort(T* arr, int low, int high) {
        // TODO
        (void)arr; (void)low; (void)high;
    }

    // Convenience overload for raw arrays
    template <class T>
    void quicksort(T* arr, std::size_t n) {
        if (n < 2) return;
        quicksort(arr, 0, static_cast<int>(n) - 1);
    }

} // namespace dsa

