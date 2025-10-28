#pragma once
#include <string>
#include <vector>
#include <iostream>

// product class, stores info
class Product {
private:
    std::string uniqId;           // id
    std::string productName;      // name
    std::vector<std::string> categories; // category list

public:
    Product() = default;          // default ctor
    Product(const std::string& id, const std::string& name, const std::vector<std::string>& cats); // init ctor

    // getters
    const std::string& getId() const;
    const std::string& getName() const;
    const std::vector<std::string>& getCategories() const;

    void printDetails() const;    // display info
};