#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dsa/BST.hpp"
#include <stdexcept>

TEST_CASE("BST starts empty") {
    dsa::BST<int> t;
    CHECK(t.empty());
    CHECK(t.size() == 0);
    CHECK(t.height() == 0);
    CHECK(t.contains(10) == false);
    CHECK_THROWS_AS(t.min(), std::out_of_range);
    CHECK_THROWS_AS(t.max(), std::out_of_range);
}

TEST_CASE("Insert + contains + inorder sorted") {
    dsa::BST<int> t;
    int vals[] = {5, 2, 8, 1, 3, 7, 9};
    for (int x : vals) t.insert(x);

    CHECK(t.size() == 7);
    CHECK_FALSE(t.empty());
    CHECK(t.contains(7));
    CHECK_FALSE(t.contains(6));

    int out[7];
    t.inorder(out);
    int expected[] = {1,2,3,5,7,8,9};
    for (int i = 0; i < 7; ++i) CHECK(out[i] == expected[i]);

    CHECK(t.min() == 1);
    CHECK(t.max() == 9);
}

TEST_CASE("Insert ignores duplicates") {
    dsa::BST<int> t;
    t.insert(5);
    t.insert(5);
    t.insert(5);
    CHECK(t.size() == 1);
    CHECK(t.contains(5));
}

TEST_CASE("Remove leaf") {
    dsa::BST<int> t;
    for (int x : {5,2,8,1,3}) t.insert(x);

    CHECK(t.remove(1) == true);
    CHECK(t.size() == 4);
    CHECK_FALSE(t.contains(1));
}

TEST_CASE("Remove node with one child") {
    dsa::BST<int> t;
    // 5,2,8,1 (2 has left child only after remove 3 not present)
    for (int x : {5,2,8,1}) t.insert(x);

    CHECK(t.remove(2) == true); // 2 has one child (1)
    CHECK(t.size() == 3);
    CHECK_FALSE(t.contains(2));
    CHECK(t.contains(1));
}

TEST_CASE("Remove node with two children") {
    dsa::BST<int> t;
    for (int x : {5,2,8,1,3,7,9}) t.insert(x);

    CHECK(t.remove(5) == true); // root has two children
    CHECK(t.size() == 6);
    CHECK_FALSE(t.contains(5));

    int out[6];
    t.inorder(out);
    int expected[] = {1,2,3,7,8,9};
    for (int i = 0; i < 6; ++i) CHECK(out[i] == expected[i]);
}

TEST_CASE("Remove not found returns false") {
    dsa::BST<int> t;
    for (int x : {5,2,8}) t.insert(x);
    CHECK(t.remove(100) == false);
    CHECK(t.size() == 3);
}

TEST_CASE("clear resets tree") {
    dsa::BST<int> t;
    for (int x : {5,2,8,1,3}) t.insert(x);

    CHECK(t.size() == 5);
    t.clear();
    CHECK(t.size() == 0);
    CHECK(t.empty());
    CHECK(t.height() == 0);
    CHECK_FALSE(t.contains(5));
    CHECK_THROWS_AS(t.min(), std::out_of_range);
}
