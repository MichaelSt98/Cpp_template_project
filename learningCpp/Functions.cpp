//
// Created by Michael Staneker on 08.12.20.
//

#include "Functions.h"

#include <iostream>

void pass_by_value(int x) {
    std::cout << "func: pass_by_value(int x)" << std::endl;
    std::cout << "x = " << x << std::endl;
}

void pass_by_reference(int &x) {
    std::cout << "func: pass_by_reference(int &x)" << std::endl;
    std::cout << "x += 1" << std::endl;
    x = x + 1;
}

void pass_by_address(int *ptr) {
    std::cout << "func: pass_by_address(int *ptr)" << std::endl;
    std::cout << "ptr = 4" << std::endl;
    *ptr = 4;
}

int return_by_value() {
    std::cout << "func: return_by_value()" << std::endl;
    int value{ 2 };
    return value; // a copy of value will be returned
} // value desroyed here

int& return_by_reference() {
    std::cout << "func: return_by_reference()" << std::endl;
    int value{ 2 };
    return value; // return a refernce to value
}

int* return_by_address() {
    std::cout << "func: return_by_address()" << std::endl;
    int value{ 2 };
    return &value; // return value by address
} // value destroyed here

int overload_add(int a, int b) {
    std::cout << "overload_add(int a, int b)" << std::endl;
    return a + b;
}

int overload_add(int a, int b, int c) {
    std::cout << "overload_add(int a, int b, int c)" << std::endl;
    return a + b + c;
}

void func_default_arg(int x, int y) {
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1);

    std::cout << "pop " << count << '\n';
}


int main() {

    int x = 5;
    pass_by_value(x);

    pass_by_reference(x);
    std::cout << "after passed by reference: x = " << x << std::endl;

    pass_by_address(&x);
    std::cout << "after passed by address x = " << x << std::endl;

    int value = return_by_value();
    std::cout << "return by value: value = " << value << std::endl;

    int *value_ptr = return_by_address();
    std::cout << "return by address: " << std::endl;
    std::cout << " value_ptr = " << value_ptr << std::endl;
    std::cout << "*value_ptr = " << *value_ptr << std::endl;

    int value_ref = return_by_reference();
    std::cout << "return by reference: value = " << value_ref << std::endl;

    int a = 1;
    int b = 2;
    int c = 3;

    int result_1 = overload_add(a, b);
    std::cout << "result_1 = " << result_1 << std::endl;
    int result_2 = overload_add(a, b, c);
    std::cout << "result_2 = " << result_2 << std::endl;

    std::cout << "func_default_arg(int x, int y=10) with x = 2" << std::endl;
    func_default_arg(2);
    std::cout << "func_default_arg(int x, int y=10) with x = 2 and y = 5" << std::endl;
    func_default_arg(2, 5);

    /**
     * calling a function through a function pointer
     */

    void (*fcnPtr)(int, int){ &func_default_arg }; // Initialize fcnPtr
    std::cout << "call function through function pointer: " << std::endl;
    fcnPtr(5, 5); // call function

    /**
     * calling a recursive function
     */
    std::cout << "Calling a recursive function" << std::endl;
    countDown(5);

    return 0;
}
