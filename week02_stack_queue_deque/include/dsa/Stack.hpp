//
// Created by marius on 1/26/26.
//

#pragma once
#include <cstddef>

namespace dsa {

    template <class T>
    class Stack {
    public:
        Stack();

        void push(const T& value);
        void pop();
        T& top();
        const T& top() const;

        bool empty() const;
        std::size_t size() const;

    private:
        // student decides representation
    };

}
