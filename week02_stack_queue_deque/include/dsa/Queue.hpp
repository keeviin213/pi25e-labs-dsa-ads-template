//
// Created by marius on 1/26/26.
//

#pragma once
#include <cstddef>

namespace dsa {

    template <class T>
    class Queue {
    public:
        Queue();

        void enqueue(const T& value);
        void dequeue();
        T& front();
        const T& front() const;

        bool empty() const;
        std::size_t size() const;

    private:
        // circular buffer fields
    };

}
