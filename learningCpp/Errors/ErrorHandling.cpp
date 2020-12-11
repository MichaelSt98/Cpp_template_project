//
// Created by Michael Staneker on 09.12.20.
//

#include "ErrorHandling.h"

#include <iostream>

int returning_error_code() {
    return -1;
}

void write_error_message() {
    std::cerr << "This is an error message!" << std::endl;
}

void exit_program() {
    std::cout << "exiting with error number 2 to OS" << std::endl;
    std::exit(2);
}

void assert_example(int x) {
    std::cout << "assert() example" << std::endl;
    std::cout << "x = " << x << std::endl;
    //terminates if assert evaluates to true
    assert(x > 0);
}

int main() {

    int error_code = returning_error_code();
    std::cout << "error code received from returning_error_code: " << error_code << std::endl;

    write_error_message();

    // assert() evaluates to false if x <= 0
    assert_example(1);

    //exit_program();
    //std::cout << "This shouldn't be printed!!!" << std::endl;

    return 0;

}