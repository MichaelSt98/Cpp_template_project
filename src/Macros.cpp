//
// Created by Michael Staneker on 01.12.20.
//

#include <iostream>

/** Header guards (conditional compilation directive)*/
//#ifnedf SOME_UNIQUE_NAME_HERE
//#define SOME_UNIQUE_NAME_HERE
//
//#endif

// or alternatively use, but bit supported by all compilers
//#pragma once
/** */

// define macro (with substitution text)
#define PI 3.1415

// empty substitution text
#define EULER



int main() {

#ifdef PI // or if not defined use #ifndef
    std::cout << "PI is: " << PI << std::endl
//#elif
//#else
#endif

#ifdef EULER
    std::cout << "EULER is defined, but not replaceable, or rather replaceable by empty"
#endif

    return 0;
}
