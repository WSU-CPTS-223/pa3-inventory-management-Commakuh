#include "Product.h"
#include <iostream>

Product::Product(const std::string& id, const std::string& name, const std::vector<std::string>& cats)
    : uniqId(id), productName(name), categories(cats) {
}

const std::string& Product::getId() const { return uniqId; }
const std::string& Product::getName() const { return productName; }
const std::vector<std::string>& Product::getCategories() const { return categories; }

void Product::printDetails() const {
    std::cout << "Product ID: " << uniqId << std::endl;
    std::cout << "Product Name: " << productName << std::endl;
    std::cout << "Categories: ";
    for (size_t i = 0; i < categories.size(); i++) {
        std::cout << categories[i];
        if (i != categories.size() - 1) std::cout << " | ";
    }
    std::cout << std::endl;
}
