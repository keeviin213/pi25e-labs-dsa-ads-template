//
// Created by marius on 1/26/26.
//

#pragma once
#include <cstddef>

namespace dsa {

    template <class T>
    class Deque {
    public:
        Deque();

        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();

        T& front();
        T& back();

        bool empty() const;
        std::size_t size() const;

    private:
        // circular buffer fields
    };

}
