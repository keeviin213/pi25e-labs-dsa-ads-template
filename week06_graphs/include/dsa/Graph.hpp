#pragma once
#include <cstddef>
#include <stdexcept>

#include "dsa/DynamicArray.hpp"
#include "dsa/Queue.hpp"
// #include "dsa/Stack.hpp" // optional

namespace dsa {

    class Graph {
    public:
        Graph(int vertices, bool directed = false);

        int vertex_count() const;

        void add_edge(int u, int v);

        // Traversal: calls visit(vertex) exactly once per vertex reached
        void bfs(int start, void (*visit)(int)) const;
        void dfs(int start, void (*visit)(int)) const;

        // Traversal over all components
        void bfs_all(void (*visit)(int)) const;
        void dfs_all(void (*visit)(int)) const;

    private:
        void validate_vertex(int v) const;

        // recursive DFS helper (allowed)
        void dfs_rec(int v, bool* visited, void (*visit)(int)) const;

    private:
        int V_;
        bool directed_;

        // adjacency list: adj_[u] is DynamicArray<int> of neighbors
        DynamicArray< DynamicArray<int> > adj_;
    };

} // namespace dsa
