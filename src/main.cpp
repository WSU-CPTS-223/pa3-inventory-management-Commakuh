#include <iostream>
#include <fstream>
#include <sstream>
#include "Product.h"
#include "HashTable.h"
#include "Utils.h"

using namespace std;

HashTable<string, Product> productsTable(1000);
HashTable<string, list<Product>> categoryTable(1000);

void printHelp() {
    cout << "\nSupported commands:\n";
    cout << "1. find <inventoryid>          - Find product by ID and display details\n";
    cout << "2. listInventory <category>    - List all products in the specified category\n";
    cout << "3. help                        - Show this help message\n";
    cout << "4. quit                        - Exit the program\n\n";
}

void evalCommand(const string& line) {
    istringstream iss(line);
    string command;
    iss >> command;

    if (command == "help") {
        printHelp();
    }
    else if (command == "find") {
        string id;
        if (!(iss >> id)) {
            cout << "Usage: find <inventoryid>\n";
            return;
        }

        Product p;
        if (productsTable.find(id, p)) {
            p.printDetails();
        }
        else {
            cout << "Inventory/Product not found\n";
        }
    }
    else if (command == "listInventory") {
        string category;
        if (!(iss >> ws) || !getline(iss, category) || category.empty()) {
            cout << "Usage: listInventory <category>\n";
            return;
        }
        category = trim(category);

        list<Product> plist;
        if (categoryTable.find(category, plist) && !plist.empty()) {
            for (auto& p : plist) {
                cout << p.getId() << " | " << p.getName() << endl;
            }
        }
        else {
            cout << "Invalid Category\n";
        }
    }
    else if (command == "quit") {
        exit(0);
    }
    else {
        cout << "Command not recognized. Type 'help' for a list of commands.\n";
    }
}

void bootStrap(const string& filename) {
    cout << "Welcome to Amazon Inventory Query System!\n";
    cout << "Loading products from CSV... Please wait.\n";

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening CSV file: " << filename << endl;
        exit(1);
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        stringstream ss(line);
        string uniqId, productName, categoryStr;

        getline(ss, uniqId, ',');
        getline(ss, productName, ',');
        // skip brand, asin
        getline(ss, line, ',');
        getline(ss, line, ',');
        getline(ss, categoryStr, ',');

        if (uniqId.empty() || productName.empty()) continue;

        vector<string> categories;
        if (categoryStr.empty()) categories.push_back("NA");
        else categories = split(categoryStr, '|');

        Product p(trim(uniqId), trim(productName), categories);

        // Insert into products table
        productsTable.insert(p.getId(), p);

        // Efficient category insertion
        for (const auto& cat : categories) {
            list<Product> existingList;
            if (categoryTable.find(cat, existingList)) {
                existingList.push_back(p);
                categoryTable.insert(cat, existingList);
            }
            else {
                list<Product> newList;
                newList.push_back(p);
                categoryTable.insert(cat, newList);
            }
        }
    }

    cout << "Loaded " << productsTable.size() << " products.\n";
    printHelp();
}

int main() {
    // Automatically load CSV from the data folder
    string csvFile = "data/marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv";
    bootStrap(csvFile);

    string line;
    cout << "> ";
    while (getline(cin, line)) {
        evalCommand(trim(line));
        cout << "> ";
    }

    return 0;
}
