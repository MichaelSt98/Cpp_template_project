//
// Created by Michael Staneker on 08.12.20.
//

#ifndef CPP_TEMPLATE_PROJECT_FUNCTIONS_H
#define CPP_TEMPLATE_PROJECT_FUNCTIONS_H

/**
 * # Function parameters and arguments
 */

/**
 * ## Pass by value
 *
 * By default, non-pointer arguments in C++ are passed by value.
 * When an argument is **passed by value**, the argument's value is copied into the value
 * of the corresponding function parameter. Therefore the original argument can not be modified
 * by the function!
 *
 * ### Pros
 * * Arguments can be anything
 * * Arguments are never changed by the function (prevents possibly unwanted side effects)
 *
 * ### Cons
 * * Copying classes and structs can incur a significant performance penalty
 *
 * ### When to use
 *
 * * When passing fundamental data type and enumerators, and the function does not need to change the argument.
 *
 * ### When not to use
 *
 * *  When passing structs or classes (including std::array, std::vector, and std::string)
 *
 */


/**
 * \fn void pass_by_value(int)
 * \brief Function passing argument by value
 */
void pass_by_value(int);

#endif //CPP_TEMPLATE_PROJECT_FUNCTIONS_H
