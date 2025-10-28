#include "Utils.h"
#include <algorithm>
#include <cctype>
#include <sstream> // Needed for stringstream in split

// Split a string `s` by the given `delimiter` and trim
// Handles cases around delimiters
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delimiter)) {
        tokens.push_back(trim(item)); // Trim whitespace from each token
    }
    return tokens;
}

// Remove leading and trailing whitespace from a string
std::string trim(const std::string& s) {
    std::string result = s;

    // Remove leading whitespace
    result.erase(result.begin(), std::find_if(result.begin(), result.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));

    // Remove trailing whitespace
    result.erase(std::find_if(result.rbegin(), result.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());

    return result;
}
