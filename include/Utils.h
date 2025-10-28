#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Product.h"

// Utility to split string by a delimiter
std::vector<std::string> split(const std::string& s, char delimiter);

// Trim whitespace from string
std::string trim(const std::string& s);
