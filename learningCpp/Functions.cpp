//
// Created by Michael Staneker on 08.12.20.
//

#include "Functions.h"

#include <iostream>

void pass_by_value(int x) {
    std::cout << "func: pass_by_value(int x)" << std::endl;
    std::cout << "x = " << x << std::endl;
}

int main() {

    int x = 5;
    pass_by_value(x);

    return 0;
}
