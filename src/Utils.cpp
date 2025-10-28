#include "Utils.h"
#include <algorithm>
#include <cctype>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delimiter)) {
        tokens.push_back(trim(item));
    }
    return tokens;
}

std::string trim(const std::string& s) {
    std::string result = s;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));
    result.erase(std::find_if(result.rbegin(), result.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());
    return result;
}
