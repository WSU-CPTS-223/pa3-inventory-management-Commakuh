#pragma once
#include <string>
#include <vector>
#include <iostream>

class Product {
private:
    std::string uniqId;
    std::string productName;
    std::vector<std::string> categories;

public:
    Product() = default;
    Product(const std::string& id, const std::string& name, const std::vector<std::string>& cats);

    const std::string& getId() const;
    const std::string& getName() const;
    const std::vector<std::string>& getCategories() const;

    void printDetails() const;
};
