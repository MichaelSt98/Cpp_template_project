//
// Created by Michael Staneker on 10.12.20.
//
/**
 * # Exceptions
 *
 * Exceptions in C++ are implemented using three keywords that work in conjunction with each other:
 * * throw
 * * try
 * * catch
 *
 * Exception handling is best used when all of the following are true:
 * * the error being handled is likely to occur only infrequently.
 * * the error is serious and execution could not continue otherwise.
 * * the error cannot be handled at the place where it occurs.
 * * there isn’t a good alternative way to return an error code back to the caller.
 *
 * ## Throwing exceptions
 *
 * A throw statement is used to signal that an exception or error case has occurred, e.g.:
 *
 * ```C++
 * throw -1; // throw a literal integer value
 * throw ENUM_INVALID_INDEX; // throw an enum value
 * throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
 * throw dX; // throw a double variable that was previously defined
 * throw MyException("Fatal Error"); // Throw an object of class MyException
 * ```
 *
 * ## Try blocks
 *
 * **Try blocks** act as observers, looking for any exceptions that are thrown within the block, e.g.:
 *
 * ```C++
 * try
 * {
 * // Statements that may throw exceptions you want to handle go here
 * throw -1; // here's a trivial throw statement
 * }
 * ```
 *
 * ## Handling exceptions
 *
 * Actually handling exceptions is the job of the catch block(s).
 * The catch keyword is used to define a block of code (called a catch block)
 * that handles exceptions for a single data type, e.g.:
 *
 * ```C++
 * catch (int x)
 * {
 * // Handle an exception of type int here
 * std::cerr << "We caught an int exception with value" << x << '\n';
 * }
 * ```
 *
 * ## Throwing exceptions outside a try-block
 *
 * ...
 *
 * ## Catch all handler
 *
 * To catch uncaught exceptions, not regarding the type of exception:
 *
 * ```C++
 * catch (...) // catch-all handler
 * {
 *     std::cout << "We caught an exception of an undetermined type\n";
 * }
 * ```
 *
 * ## Exception classes
 *
 * ...
 *
 * ## std::exception
 *
 * Many of the classes and operators in the standard library throw exception classes on failure.
 * For example, operator new can throw std::bad_alloc if it is unable to allocate enough memory.
 * A failed dynamic_cast will throw std::bad_cast. And so on. As of C++17, there are 25 different
 * exception classes that can be thrown, with more being added in each subsequent language standard.
 *
 * **It is possible to extend std::exception, by inheriting.**
 *
 * ## Rethrowing
 *
 * When rethrowing the same exception, use the *throw* keyword by itself.
 *
 * ## noexcept
 *
 * See [exception specifier](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/).
 *
 * It is possible to declare functions non-throwing using the **noexcept** specifier.
 *
 */

#ifndef CPP_TEMPLATE_PROJECT_EXCEPTIONS_H
#define CPP_TEMPLATE_PROJECT_EXCEPTIONS_H

#include <cmath>
#include <exception> // for std::exception
#include <iostream>
#include <string>
#include <string_view>

class ArrayException : public std::exception
{
private:
    std::string m_error{};

public:
    ArrayException(std::string_view error);
    // return the std::string as a const C-style string
    const char* what() const noexcept override {
        return m_error.c_str();
    }
};

class IntArray
{
private:

    int m_data[3]; // assume array is length 3 for simplicity
public:

    IntArray() {}

    int getLength() const;

    int& operator[](const int index);

};

class SQRT {
public:
    static double mySqrt(double x);
};


class Exceptions {

};


#endif //CPP_TEMPLATE_PROJECT_EXCEPTIONS_H
