//
// Created by Michael Staneker on 03.12.20.
//

/**
 *
 * # Reference variables
 *
 * Reference variables are references to variables.
 *
 */

#include <iostream>

int main() {

    int value {5};

    /** Reference variables */
    int &reference{ value }; // "reference to" value
    //int& reference{ value }; // valid
    //int & reference{ value }; // valid

    int x{ 5 }; // normal integer
    int &y{ x }; // y is a reference to x
    int &z{ y }; // z is also a reference to x

    std::cout << " x = " <<  x << std::endl;
    std::cout << " y = " <<  y << std::endl;
    std::cout << " z = " <<  z << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "&y = " << &y << std::endl;
    std::cout << "&z = " << &z << std::endl;

    // References cannot be reassigned !
    // reference = value; // not valid


    /** */

    return 0;
}

