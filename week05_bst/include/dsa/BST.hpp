//
// Created by marius on 2/19/26.
//

#pragma once
#include <cstddef>
#include <stdexcept>

namespace dsa {

    template <class T>
    class BST {
    private:
        struct Node {
            T key;
            Node* left;
            Node* right;
            Node(const T& k) : key(k), left(nullptr), right(nullptr) {}
        };

    public:
        BST();
        ~BST();

        BST(const BST&) = delete;
        BST& operator=(const BST&) = delete;

        bool empty() const;
        std::size_t size() const;

        bool contains(const T& key) const;

        // Insert: ignore duplicates (do not increase size)
        void insert(const T& key);

        // Remove: returns true if removed, false if not found
        bool remove(const T& key);

        const T& min() const; // throws if empty
        const T& max() const; // throws if empty

        // Writes keys in sorted order into out[0..size-1]
        void inorder(T* out) const;

        std::size_t height() const; // empty=0, leaf=1

        void clear();

    private:
        Node* insert(Node* node, const T& key, bool& inserted);
        bool contains(Node* node, const T& key) const;

        Node* remove(Node* node, const T& key, bool& removed);
        Node* find_min_node(Node* node) const;

        const T& min(Node* node) const;
        const T& max(Node* node) const;

        void inorder(Node* node, T* out, std::size_t& idx) const;

        std::size_t height(Node* node) const;
        void clear(Node* node);

    private:
        Node* root_;
        std::size_t size_;
    };

} // namespace dsa
