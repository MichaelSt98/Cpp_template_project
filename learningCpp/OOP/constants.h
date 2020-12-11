//
// Created by Michael Staneker on 01.12.20.
//

/**
 * # Header (only) file for constants
 *
 * This can be achieved using a namespace and **const expressions**.
 */

#ifndef CPP_TEMPLATE_PROJECT_CONSTANTS_H
#define CPP_TEMPLATE_PROJECT_CONSTANTS_H

namespace constants {

    constexpr double pi { 3.141519};
    constexpr double avogadro { 6.0221413e23 };

    //extern const double pi { 3.141519};
    //extern const double avogadro { 6.0221413e23 };

    // C++17 or newer
    //inline constexpr double pi { 3.14159 }; // inline constexpr is C++17 or newer only
    //inline constexpr double avogadro { 6.0221413e23 };

    //#include "constants.h"
    //
    //double circumfence { 2.0 * radius * constants::pi}
}

#endif //CPP_TEMPLATE_PROJECT_CONSTANTS_H
