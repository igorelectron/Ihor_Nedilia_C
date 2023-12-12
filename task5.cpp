#include <iostream>
#include <string_view>
#include <vector>


std::vector<std::string_view> partial_split(std::string_view s, std::string_view sep) {
    std::vector<std::string_view> ret{};
    if (s.substr(0, sep.size()) == sep) 
        s.remove_prefix(sep.size()); 
    while (!s.empty()) {
        size_t pos = s.find(sep);
        if (pos == std::string_view::npos) {
            ret.push_back(s);
            break;
        }
        ret.push_back(s.substr(0, pos));
        s = s.substr(pos + sep.size());
    }
    return ret;
}

int main() {
    auto a = partial_split("42, 26, 1426", ", ");
}