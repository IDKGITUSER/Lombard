#include "enter.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

void Enter::waitForEnter() {
    std::cout << "Press Enter to continue...";

    getchar();
    while (1) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
    }
}
