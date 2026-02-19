#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dsa/HashTable.hpp"

TEST_CASE("HashTable basic put/get/contains") {
    dsa::HashTable ht(10);

    CHECK(ht.size() == 0);
    CHECK(ht.bucket_count() == 10);
    CHECK(ht.contains(5) == false);
    CHECK(ht.get(5) == nullptr);

    CHECK(ht.put(5, 50) == true);        // inserted
    CHECK(ht.size() == 1);
    CHECK(ht.contains(5) == true);
    REQUIRE(ht.get(5) != nullptr);
    CHECK(*ht.get(5) == 50);

    CHECK(ht.put(5, 500) == false);      // updated
    CHECK(ht.size() == 1);
    REQUIRE(ht.get(5) != nullptr);
    CHECK(*ht.get(5) == 500);
}

TEST_CASE("HashTable collisions with chaining") {
    // capacity=10 -> keys 1, 11, 21 collide
    dsa::HashTable ht(10);

    CHECK(ht.put(1, 100) == true);
    CHECK(ht.put(11, 1100) == true);
    CHECK(ht.put(21, 2100) == true);

    CHECK(ht.size() == 3);

    REQUIRE(ht.get(1) != nullptr);
    REQUIRE(ht.get(11) != nullptr);
    REQUIRE(ht.get(21) != nullptr);

    CHECK(*ht.get(1) == 100);
    CHECK(*ht.get(11) == 1100);
    CHECK(*ht.get(21) == 2100);
}

TEST_CASE("HashTable remove: head/middle/tail in chain") {
    dsa::HashTable ht(10);

    // Same bucket chain
    ht.put(1, 100);
    ht.put(11, 1100);
    ht.put(21, 2100);

    CHECK(ht.size() == 3);

    // remove head (depends on insertion strategy; our teacher impl inserts at head)
    CHECK(ht.remove(21) == true);
    CHECK(ht.size() == 2);
    CHECK(ht.get(21) == nullptr);

    // remove middle / remaining
    CHECK(ht.remove(11) == true);
    CHECK(ht.size() == 1);
    CHECK(ht.get(11) == nullptr);

    CHECK(ht.remove(1) == true);
    CHECK(ht.size() == 0);
    CHECK(ht.get(1) == nullptr);

    CHECK(ht.remove(1) == false); // already removed
}

TEST_CASE("HashTable supports negative keys") {
    dsa::HashTable ht(10);

    CHECK(ht.put(-1, 999) == true);
    CHECK(ht.contains(-1) == true);
    REQUIRE(ht.get(-1) != nullptr);
    CHECK(*ht.get(-1) == 999);

    CHECK(ht.remove(-1) == true);
    CHECK(ht.contains(-1) == false);
}