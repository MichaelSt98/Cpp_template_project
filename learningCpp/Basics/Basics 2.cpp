//
// Created by Michael Staneker on 01.12.20.
//

#include <iostream>
#include <cstdint>
#include <chrono>
#include <thread>
#include <array>

/** # C++ Basics */

/** ## Global variables */
// global variables have file scope
int g_global_integer { 1 };
// AVOID using non-constant global variables!

// internal linkage --> limits the use of an identifier to a single file
// non-constant globals have external linkage by default
static int g_x_1; // adding static makes them internal linkage
// const & constexpr globals have internal linkage by default

// external linkage --> "truly global"
// functions have external linkage by default!
extern const int g_x_2 { 2 }; // making const external
/** */

/** ## include order
 *
 * The following include order is recommended:
 *
 * * user-defined headers (alphabetically)
 * * third-party library headers (alphabetically)
 * * standard library header (alphabetically)
 */

int main() {

    /** ## Initialization
     *
     * ```cpp
     * // copy initialization
     * int a = 1;
     * // direct initialization
     * int b(1);
     * // list (uniform/brace) initialization
     * //direct
     * int c_1{1};
     * //copy
     * int c_2 = {1};
     * ```
     * */

    // copy initialization
    int a = 1;
    // direct initialization
    int b(1);
    // list (uniform/brace) initialization
    //direct
    int c_1{1};
    //copy
    int c_2 = {1};
    /** */

    /** ## Fundamental data types
     *
     * ### floating point
     *
     * * float
     * * double
     * * long double
     *
     * ### Integral characters
     *
     * * char
     * * w_chart_t
     * * char8_t, char16_t, char32_t
     *
     * ### Integers
     *
     * * short
     * * int
     * * long
     * * long long
     * */
    // floating point
    float float_a = 3.14159; // at least 4 bytes
    double float_b = 3.14159; // at least 8 bytes
    long double float_c = 3.14159; // at least 8 bytes
    // Inf represents Infinity
    // NaN represents Not a Number

    // integral characters
    char char_a = 'c'; // always 1 byte
    wchar_t char_b = 'c'; // at least 1 byte
    //char8_t char_c = 'c'; // C++20
    //char16_t char_d = 'c'; // C++11 // at least 2 bytes
    //char32_t char_e = 'c'; // C++11 // at least 4 bytes

    // 0b12 --> binary
    // 012 --> octal
    // 0x12 --> hexadecimal
    // use std::dec , std::oct , std::hex

    // Integers
    short int_a = 1; // at least 2 bytes
    int int_b = 1; // at least 2 bytes
    long int_c = 1; // at least 4 bytes
    //long long int_d = 1; // C++11

    // Boolean
    bool bool_a = true; // or false

    // Null pointer
    //std::nullptr_t null_pointer = nullptr;

    // void

    // using cstdint
    //std::int8_t
    //std::uint8_t
    //std::int16_t
    //std::uint16_t
    //std::int32_t
    //std::uint32_t
    //std::int64_t
    //std::uint64_t

    // there is also the std::int_fast#_t providing the fastest signed integer with at least # bits
    // there is also the std::int_least#_t providing the smallest signed integer with at least # bits

    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n"; // C++11 only
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n"; // C++11 only
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n"; // C++11 only
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

    // use const
    //const int const_int = 1;
    // for variables that should not be modifiable after initialization
    // and whose initializer is NOT known at compile-time

    // use constexpr
    //constexpr int constexpr_int = 1;
    // for variables that should not be modifiable after initialization
    // and whose initializer is known at compile-time
    /** */

    /** ## escape sequences
     * \code
     * */
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << "\a"; // makes an alert
    }
    std::cout << "Backspace \b" << std::endl;
    std::cout << "Formfeed \f" << std::endl;
    std::cout << "Newline \n" << std::endl;
    std::cout << "Carriage return \r" << std::endl;
    std::cout << "Horizontal \t tab" << std::endl;
    std::cout << "Vertical tab \v" << std::endl;
    std::cout << "Single quote \' or double quote \"" << std::endl;
    std::cout << "Octal number \12" << std::endl;
    std::cout << "Hex number \x14" << std::endl;

    /**
     * \endcode
     * */

    /** ## Conditional operator */
    int x_1 = 2;
    int x_2 = 3;
    int max_x = (x_1 > x_2) ? x_1 : x_2;
    std::cout << "max_x = " << max_x << std::endl;
    /** */

    /** ## Namespaces
     *
     * ```cpp
     * // define a namespace
     * namespace namespace_1 {
     * //nested namespace
     *      namespace namespace_1_nested {
     *      }
     * }
     * // accessible using "::"
     * // namespace alias
     * namespace nested_namespace = namespace_1::namespace_1_nested;
     * ```
     */

    /** ## Static local variables */

    // static local variables are not destroyed when out of scope (in contrast to automatic)
    static int var_1 { 1 };
    // AVOID using static variables unless the variable never needs to be reset
    /** */


    /** ## Typedefs and type aliases */
    typedef double distance_t; // define distance_t as an alias for type double
    //which is equivalent to: using distance_t = double;
    // The following two statements are equivalent:
    // double howFar; //equivalent to
    distance_t howFar;
    /** */


    /** ## Type conversion */

    // IMPLICIT type conversion (coercion)
    float f_int { 3 }; // initializing floating point variable with int 3

    // EXPLICIT type conversion
    // static_cast
    int i1 { 10 };
    int i2 { 4 };
    // convert an int to a float so we get floating point division rather than integer division
    float f { static_cast<float>(i1) / i2 };

    /** */

    /** ## Enumerations */
    enum Color
    {
        color_black, // assigned 0
        color_red, // assigned 1
        color_blue, // assigned 2
        color_green, // assigned 3
        color_white, // assigned 4
        color_cyan, // assigned 5
        color_yellow, // assigned 6
        color_magenta // assigned 7
    };
    Color paint{ color_white };
    std::cout << paint;

    // enum classes (scoped enumerations)
    enum class Fruit
    {
        banana, // banana is inside the scope of Fruit
        apple
    };
    Fruit fruit{ Fruit::banana }; // note: banana is not directly accessible any more, we have to use Fruit::banana
    /** */

    /** ## Structs */
    struct Employee
    {
        short id;
        int age;
        double wage;
    };

    Employee joe{ 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
    Employee frank{ 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

    //Employee joe; // create an Employee struct for Joe
    //joe.id = 14; // assign a value to member id within struct joe
    //joe.age = 32; // assign a value to member age within struct joe
    //joe.wage = 24.15; // assign a value to member wage within struct joe

    //Employee frank; // create an Employee struct for Frank
    //frank.id = 15; // assign a value to member id within struct frank
    //frank.age = 28; // assign a value to member age within struct frank
    //frank.wage = 18.27; // assign a value to member wage within struct frank

    // nested structs
    struct Company
    {
        Employee CEO; // Employee is a struct within the Company struct
        int numberOfEmployees;
    };
    Company myCompany{{ 1, 42, 60000.0 }, 5 };
    /** */

    /** ## Control flows */
    // halt (using <cstdlib>)
    //std::exit(0); // terminate and return 0 to operating system
    // ATTENTION: be aware of leaking resources

    // Conditional branches
    if (true) {

    } else if (false) {

    } else {

    }
    // init statements
    //    if (std::string fullName{ firstName + ' ' + lastName }; fullName.length() > 20)
    //    {
    //        std::cout << '"' << fullName << "\"is too long!\n";
    //    }
    //    else
    //    {
    //        std::cout << "Your name is " << fullName << '\n';
    //    }

    // Switch statements
    Color color {color_black};
    switch (color)
    {
        case Color::color_black:
            std::cout << "Black";
            break;
        case Color::color_white:
            std::cout << "White";
            break;
        case Color::color_red:
            std::cout << "Red";
            break;
            //[[fallthrough]];
        case Color::color_green:
            std::cout << "Green";
            break;
        case Color::color_blue:
            std::cout << "Blue";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
    //[[fallthrough]] attribute can be added to indicate that the fall-through is intentional.

    // Goto statements
    //tryAgain:
    //    goto tryAgain;

    // While statements
    int while_counter{ 5 };
    while (while_counter < 10) {
        std::cout << "while_counter: " << while_counter << std::endl;
        ++while_counter;
    }

    // Do wile statements
    do {
        std::cout << "while_counter: " << while_counter << std::endl;
        ++while_counter;
    }
    while (while_counter < 15);

    // For statements
    for (int count{ 0 }; count < 10; ++count)
        std::cout << count << ' ';
    int iii{};
    int jjj{};
    for (iii = 0, jjj = 9; iii < 10; ++iii, --jjj)
        std::cout << iii << ' ' << jjj << '\n';
    // return statement terminates the entire function the loop is within
    // break terminates the loop
    // continue jumps to the end of the loop body for the current iteration
    /** */

    /** ## Arrays */
    //int prime[5]{}; // hold the first 5 prime numbers
    //prime[0] = 2; // The first element has index 0
    //prime[1] = 3;
    //prime[2] = 5;
    //prime[3] = 7;
    //prime[4] = 11; // The last element has index 4 (array length-1)
    int prime[5]{ 2, 3, 5, 7, 11 }; // use initializer list to initialize the fixed array
    //int prime[]{ 2, 3, 5, 7, 11 }; // works as well
    //std::cout << "The array has: " << std::size(prime) << " elements\n"; // C++17
    //sizeof() gives the array length multiplied by element size

    // Multidimensional arrays
    int num_rows{3};
    int num_cols{5};
    int multi_dim_array[3][5] // cannot use num_rows or num_cols --> see dynamic memory allocation
            {
                    { 1, 2, 3, 4, 5 }, // row 0
                    { 6, 7, 8, 9, 10 }, // row 1
                    { 11, 12, 13, 14, 15 } // row 2
            };
    for (int row{ 0 }; row < num_rows; ++row) // step through the rows in the array
    {
        for (int col{ 0 }; col < num_cols; ++col) // step through each element in the row
        {
            std::cout << multi_dim_array[row][col];
        }
    }

    // foreach loop
    for (auto &element: prime)
    {
        std::cout <<  element << std::endl;
    }
    /** */

    return 0; // 0, EXIT_SUCCESS, EXIT_FAILURE
}