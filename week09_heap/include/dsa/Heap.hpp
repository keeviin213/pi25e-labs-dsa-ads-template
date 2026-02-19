//
// Created by marius on 2/19/26.
//

#pragma once
#include <cstddef>
#include <stdexcept>
#include "dsa/DynamicArray.hpp"

namespace dsa {

    // Max-Heap (priority queue)
    template <class T>
    class Heap {
    public:
        Heap() = default;

        bool empty() const { return data_.size() == 0; }
        std::size_t size() const { return data_.size(); }

        const T& top() const {
            if (empty()) throw std::out_of_range("Heap::top on empty heap");
            return data_[0];
        }

        void push(const T& value) {
            // TODO: push_back then sift_up
            (void)value;
        }

        void pop() {
            // TODO: swap root with last, pop_back, sift_down
        }

    private:
        static std::size_t parent(std::size_t i) { return (i - 1) / 2; }
        static std::size_t left(std::size_t i) { return 2 * i + 1; }
        static std::size_t right(std::size_t i) { return 2 * i + 2; }

        void sift_up(std::size_t i) {
            // TODO
            (void)i;
        }

        void sift_down(std::size_t i) {
            // TODO
            (void)i;
        }

    private:
        DynamicArray<T> data_;
    };

} // namespace dsa