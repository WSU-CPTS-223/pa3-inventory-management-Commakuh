#include <iostream>
#include <cassert>
#include "../include/HashTable.h"
using namespace std;

// simple insert & find
void testInsertAndFind() {
    HashTable<string, int> table(10);
    table.insert("pen", 100);
    table.insert("pineapple", 200);

    int value;
    assert(table.find("pen", value) && value == 100);
    assert(table.find("pineapple", value) && value == 200);
    cout << "testInsertAndFind passed.\n";
}

// missing key returns false
void testFindMissingKey() {
    HashTable<string, int> table(10);
    int value;
    assert(!table.find("missing", value));
    cout << "testFindMissingKey passed.\n";
}

// force collisions, still correct
void testCollisionHandling() {
    HashTable<int, string> table(2); // small table
    table.insert(1, "One");
    table.insert(3, "Three"); // likely same bucket

    string value;
    assert(table.find(1, value) && value == "One");
    assert(table.find(3, value) && value == "Three");
    cout << "testCollisionHandling passed.\n";
}

// duplicate key overwrites
void testDuplicateInsert() {
    HashTable<string, int> table(10);
    table.insert("key", 10);
    table.insert("key", 20); // overwrite

    int value;
    assert(table.find("key", value) && value == 20);
    cout << "testDuplicateInsert passed.\n";
}

int main() {
    cout << "Running HashTable tests...\n";
    testInsertAndFind();
    testFindMissingKey();
    testCollisionHandling();
    testDuplicateInsert();
    cout << "All HashTable tests passed successfully.\n";
    return 0;
}