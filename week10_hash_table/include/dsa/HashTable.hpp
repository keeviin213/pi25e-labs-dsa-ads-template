//
// Created by marius on 2/20/26.
//

#pragma once
#include <cstddef>
#include <stdexcept>

namespace dsa {

    class HashTable {
    private:
        struct Node {
            int key;
            int value;
            Node* next;
            Node(int k, int v, Node* n=nullptr) : key(k), value(v), next(n) {}
        };

    public:
        explicit HashTable(int capacity);
        ~HashTable();

        HashTable(const HashTable&) = delete;
        HashTable& operator=(const HashTable&) = delete;

        bool put(int key, int value);   // true if inserted, false if updated
        bool contains(int key) const;
        int* get(int key);              // nullptr if not found
        bool remove(int key);           // true if removed
        int size() const;
        int bucket_count() const;

    private:
        int index_for(int key) const;   // handle negative keys
        void clear_bucket(Node*& head);

    private:
        Node** buckets_;
        int capacity_;
        int size_;
    };

} // namespace dsa