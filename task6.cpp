#include <iostream>
#include <cctype>
#include <string>
#include <string_view>


std::string_view shortest_world(std::string_view s) {
    std::string_view shortest = s;
    bool ok = false;
    for (size_t i = 0; i < s.size(); i++) {
        while (i < s.size() && !std::isalnum(static_cast<unsigned char>(s[i]))) i++;
        if (i == s.size()) break;
        size_t beg = i;
        while (i < s.size() && std::isalnum(static_cast<unsigned char>(s[i]))) i++;
        std::string_view cur = s.substr(beg, i-beg);
        if (!ok || cur.size() < shortest.size()) {
            shortest = cur;
            ok = true;
        }
    }
    if (!ok) return s.substr(0, 0);
    return shortest;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << '`' << shortest_world(s) << '`' << '\n';
}