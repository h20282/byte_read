#include <cctype>
#include <cstdio>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "color.h"

void PutLine(const std::vector<uint8_t> &line) {
    printf("  |  ");
    for (auto c : line) {
        if (std::isprint(c)) {
            printf("%c", c);
        } else {
            color::Print(color::kGray, ".");
        }
    }
}

int main(int argc, char **argv) {

    std::string file_name = argv[1];

    int line_width = 16;
    if (argc >= 3) { line_width = std::stoi(argv[2]); }

    std::ifstream ifs(file_name, std::ios::in | std::ios::binary);

    uint8_t c;
    int cnt = 0;
    std::vector<uint8_t> line;
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c))) {
        printf("%02x ", c);
        line.push_back(c);
        if (++cnt % line_width == 0) {
            PutLine(line);
            line.clear();
            putchar('\n');
        }
    }
    if (!line.empty()) {
        int n = line_width - line.size();
        while (n--) { printf("   "); }
        PutLine(line);
    }

    putchar('\n');
    return 0;
}
