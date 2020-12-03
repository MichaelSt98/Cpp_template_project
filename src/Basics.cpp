//
// Created by Michael Staneker on 01.12.20.
//

#include <iostream>
#include <cstdint>
#include <chrono>
#include <thread>

/** Global variables */
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

/** include order */
// user-defined headers (alphabetically)
// third-party library headers (alphabetically)
// standard library header (alphabetically)

int main() {

    /** Initialization */
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

    /** Fundamental data types */
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

    /** escape sequences */
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
    /** */

    /** Conditional operator */
    int x_1 = 2;
    int x_2 = 3;
    int max_x = (x_1 > x_2) ? x_1 : x_2;
    /** */

    /** Namespaces */
    // define a namespace
    namespace namespace_1 {
        //nested namespace
        namespace namespace_1_nested {

        }
    }
    // accessible using "::"

    // namespace alias
    // namespace nested_namespace = namespace_1::namespace_1_nested;
    /** */

    /** Static local variables */

    // static local variables are not destroyed when out of scope (in contrast to automatic)
    static int var_1 { 1 };
    // AVOID using static variables unless the variable never needs to be reset
    /** */


    /** Typedefs and type aliases */
    typedef double distance_t; // define distance_t as an alias for type double
    //which is equivalent to: using distance_t = double;
    // The following two statements are equivalent:
    // double howFar; //equivalent to
    distance_t howFar;
    /** */


    /** Type conversion */

    // IMPLICIT type conversion (coercion)
    float f_int { 3 }; // initializing floating point variable with int 3

    // EXPLICIT type conversion
    // static_cast
    int i1 { 10 };
    int i2 { 4 };
    // convert an int to a float so we get floating point division rather than integer division
    float f { static_cast<float>(i1) / i2 };


    /** */



    return 0; // 0, EXIT_SUCCESS, EXIT_FAILURE
}