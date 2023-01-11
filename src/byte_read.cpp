#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void PutLine(const std::vector<uint8_t> &line) {
    printf("  |  ");
    for (auto c : line) {
        if (std::isprint(c)) {
            printf(" %c ", c);
        } else {
            printf(" * ");
        }
    }
}

int main(int argc, char **argv) {
    std::ifstream ifs(argv[1], std::ios::in | std::ios::binary);
    uint8_t c;
    int cnt = 0;
    std::vector<uint8_t> line;
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c))) {
        printf("%02x ", c);
        line.push_back(c);
        if (++cnt % 16 == 0) {
            PutLine(line);
            line.clear();
            cout << endl;
        }
    }
    if (!line.empty()) {
        int n = 16 - line.size();
        while (n--) { printf("   "); }
        PutLine(line);
    }

    cout << endl;
    return 0;
}
