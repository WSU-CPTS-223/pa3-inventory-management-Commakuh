#pragma once
#include <vector>
#include <list>
#include <functional>
#include <iostream>
#include <cassert>

// templated hash table
template<typename Key, typename Value>
class HashTable {
private:
    std::vector<std::list<std::pair<Key, Value>>> table; // buckets
    size_t capacity;   // total slots
    size_t currentSize; // items stored

    // compute index
    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % capacity;
    }

public:
    HashTable(size_t cap = 100) : capacity(cap), currentSize(0) {
        table.resize(capacity); // init buckets
    }

    // add or update
    void insert(const Key& key, const Value& value) {
        size_t index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value; // overwrite existing
                return;
            }
        }
        table[index].emplace_back(key, value); // new pair
        currentSize++;
    }

    // get single
    bool find(const Key& key, Value& value) const {
        size_t index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false; // not found
    }

    // get multiple (same key)
    std::list<Value> findMultiple(const Key& key) const {
        std::list<Value> result;
        size_t index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) result.push_back(kv.second);
        }
        return result;
    }

    size_t size() const { return currentSize; } // number of items
};