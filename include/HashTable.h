#pragma once
#include <vector>
#include <list>
#include <functional>
#include <iostream>
#include <cassert>

// Templated hash table for general key-value storage
template<typename Key, typename Value>
class HashTable {
private:
    std::vector<std::list<std::pair<Key, Value>>> table;
    size_t capacity;
    size_t currentSize;

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % capacity;
    }

public:
    HashTable(size_t cap = 100) : capacity(cap), currentSize(0) {
        table.resize(capacity);
    }

    void insert(const Key& key, const Value& value) {
        size_t index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value; // overwrite
                return;
            }
        }
        table[index].emplace_back(key, value);
        currentSize++;
    }

    bool find(const Key& key, Value& value) const {
        size_t index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false;
    }

    std::list<Value> findMultiple(const Key& key) const {
        std::list<Value> result;
        size_t index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                result.push_back(kv.second);
            }
        }
        return result;
    }

    size_t size() const { return currentSize; }
};
