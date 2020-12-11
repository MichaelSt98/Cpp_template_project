//
// Created by Michael Staneker on 10.12.20.
//

#include "Exceptions.h"

#include <iostream>
#include <string>
#include <exception>

int main() {

    try
    {
        // Statements that may throw exceptions you want to handle go here
        throw -1; // here's a trivial example
    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string &str) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << '\n';
    }

    std::cout << "Continuing on our merry way\n";


    double x{ -1 };

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        double d = SQRT::mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }

    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of example
        std::string s;
        s.resize(-1); // will trigger a std::length_error
    }
        // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception &exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    try
    {
        throw std::runtime_error("Bad things happened");
    }
        // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception &exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    IntArray array;

    try
    {
        int value{ array[5] };
    }
    catch (const ArrayException &exception) // derived catch blocks go first
    {
        std::cerr << "An array exception occurred (" << exception.what() << ")\n";
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
    }

    return 0;
}

