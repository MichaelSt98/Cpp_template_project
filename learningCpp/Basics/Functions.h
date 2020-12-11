//
// Created by Michael Staneker on 08.12.20.
//

#include <array>
#include <iostream>

#ifndef CPP_TEMPLATE_PROJECT_FUNCTIONS_H
#define CPP_TEMPLATE_PROJECT_FUNCTIONS_H

/**
 * \file Functions.h
 * # Function parameters and arguments
 *
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
 *
 *
 * ## Pass by reference
 *
 * To **pass** a variable **by reference**, simply declare the function parameters as references.
 * When the function is called the function parameter becomes a reference to the argument being called with, so
 * that any changes made to the reference are passed through to the argument!
 *
 * Since functions can have only one return value, references or rather reference function parameters
 * can be used to return multiple values.
 *
 * ### read-only pass by reference
 *
 * If it is undesirable to change an argument, make it read-only by passing it as **const reference**, so that
 * an error occurs if the function tries to change the argument.
 *
 * That's useful, since
 * * It enlists the compilers help in ensuring values that shouldn’t be changed aren’t changed (the compiler will throw an error if you try, like in the above example).
 * * It tells the programmer that the function won’t change the value of the argument. This can help with debugging.
 * * You can’t pass a const argument to a non-const reference parameter. Using const parameters ensures you can pass both non-const and const arguments to the function.
 * * Const references can accept any type of argument, including non-const l-values, const l-values, and r-values.
 *
 * ### Pros
 *
 * * References allow a function to change the value of the argument, which is sometimes useful. Otherwise, const references can be used to guarantee the function won’t change the argument.
 * * Because a copy of the argument is not made, pass by reference is fast, even when used with large structs or classes.
 * * References can be used to return multiple values from a function (via out parameters).
 * * References must be initialized, so there’s no worry about null values.
 *
 * ### Cons
 *
 * * Because a non-const reference cannot be initialized with a const l-value or an r-value (e.g. a literal or an expression),
 *   arguments to non-const reference parameters must be normal variables.
 * * It can be hard to tell whether an argument passed by non-const reference is meant to be input, output, or both.
 *   Judicious use of const and a naming suffix for out variables can help.
 * * It’s impossible to tell from the function call whether the argument may change. An argument passed by value and passed
 *   by reference looks the same. We can only tell whether an argument is passed by value or reference by looking at the function declaration.
 *   This can lead to situations where the programmer does not realize a function will change the value of the argument.
 *
 * ### When to use
 *
 * * When passing structs or classes (const if read-only is wanted)
 * * When the function needs to modify an argument
 * * When the type information of a fixed array is required
 *
 *
 * ## Pass by address
 *
 * There is one more way to pass variables to functions, and that is by address.
 * **Passing an argument by address** involves passing the address of the argument variable rather than the
 * argument variable itself. Because the argument is an address, the function parameter must be a pointer.
 * The function can then dereference the pointer to access or change the value being pointed to.
 *
 * **Remember that fixed arrays decay into pointers when passed to a function**, therefore the
 * length of the array has to be passed separately.
 *
 * Addresses are actually passed by value, so by changing the function parameter itself, the original pointer
 * argument will not be changed.
 *
 * To change the address an argument points to, just pass the addresses by reference.
 *
 * ### read-only pass by address
 *
 * If it is undesirable to change an argument, make it read-only by passing it as **const pointer**, so that
 * an error occurs if the function tries to change the argument.
 *
 * ### Pros
 *
 * * Pass by address allows a function to change the value of the argument, which is sometimes useful.
 *   Otherwise, const can be used to guarantee the function won’t change the argument.
 *   (However, if you want to do this with a non-pointer, you should use pass by reference instead).
 * * Because a copy of the argument is not made, it is fast, even when used with large structs or classes.
 * * We can return multiple values from a function via out parameters.
 *
 * ### Cons
 *
 * * Because literals (excepting C-style string literals) and expressions do not have addresses,
 *   pointer arguments must be normal variables.
 * * All values must be checked to see whether they are null. Trying to dereference a null value will result
 *   in a crash. It is easy to forget to do this.
 * * Because dereferencing a pointer is slower than accessing a value directly, accessing arguments passed by address
 *   is slower than accessing arguments passed by value.
 *
 * ### When to use
 *
 * * When passing built-in arrays (if you’re okay with the fact that they’ll decay into a pointer).
 * * When passing a pointer and nullptr is a valid argument logically.
 *
 * ### When not to use
 *
 * * When passing a pointer and nullptr is not a valid argument logically (use pass by reference).
 * * When passing structs or classes (use pass by reference).
 * * When passing fundamental types (use pass by value).
 *
 *
 * ## Returning values by value, reference and address
 *
 * This is quite similar to passing arguments to functions. In fact, returning values from a function to its caller
 * by value, address or reference **works almost exactly the same way as passing arguments to a function, with the same
 * upsides and downsides**.
 *
 * **Attention**: Since local variables in a function go out of scope and are destroyed, this needs to be considered!
 *
 * ### Return by value
 *
 * To use, when
 * * returning variables that were declared inside the function
 * * returning function arguments that were passed by value
 *
 * **Not** to use, when
 * * returning a built-in array or pointer (use return by address instead!)
 * * returning a large struct or class (use return by reference instead!)
 *
 * ### Return by address
 *
 * Not possible for literals or expressions (no address)!
 *
 * To use, when
 * * returning dynamically allocated memory and there is no type to handle the allocation
 * * returning function arguments that were passed by address
 *
 * **Not** to use, when
 * * returning variables declared inside the function or parameters passed by value (use return by value instead!)
 * * returning a large struct or class that was passed by reference (use return by refernce instead!)
 *
 * ## Return by reference
 *
 * Not possible for literals or expressions (no address)!
 *
 * To use, when
 * * returning a reference parameter
 * * returning a member of an object that was passed into the function by reference or address
 * * returning a large struct or class that will not be destroyed at the end of the function
 *
 * **Not** to use, when
 * * returning variables declared inside the function or parameters passed by value (use return by value instead!)
 * * returning a built-in array or pointer value (use return by address)
 *
 * ## Returning multiple values
 *
 * To return multiple values
 * * a struct (or in principle a class)
 * * std::tuple
 * can be used!
 *
 * # Function overloading
 *
 * **Function overloading is a feature of C++ that allows us to create multiple functions
 * with the same name, so long as they have different parameters.**
 *
 * **Attention:** Function return types are not considered distinct!
 *
 *
 * # Default arguments
 *
 * A default argument is a default value provided for a function parameter.
 * If the user does not supply an explicit argument for a parameter with a default argument,
 * the default value will be used. If the user does supply an argument for the parameter,
 * the user-supplied argument is used.
 * Because the user can choose whether to supply a specific argument value, or use the default,
 * a parameter with a default value provided is often called an optional parameter.
 *
 * # Function pointers
 *
 * **Function pointers** point to functions!
 *
 * * non-const function pointer: int (*fcnPtr)()
 * * const function pointer: int (*const fcnPtr)()
 * * use type aliases to make function pointers *prettier*: using ValidateFunction = bool(*)(int, int)
 * * using std::function (from e.g. <functional>): std::function<bool(int, int)> fcn
 *
 * Using function pointers, functions can be passed to other functions as arguments.
 *
 * # The stack and the heap
 *
 * The memory a program uses is divided into:
 *
 * * The code segment (also called a text segment), where the compiled program sits in memory. The code segment is typically read-only.
 * * The bss segment (also called the uninitialized data segment), where zero-initialized global and static variables are stored.
 * * The data segment (also called the initialized data segment), where initialized global and static variables are stored.
 * * The heap, where dynamically allocated variables are allocated from.
 * * The call stack, where function parameters, local variables, and other function-related information are stored.
 *
 * ## Heap
 *
 * The heap segment (also known as the “free store”) keeps track of memory used for dynamic memory allocation
 * (when using *new* and *delete*).
 *
 * ## Stack
 *
 * The call stack (usually referred to as “the stack”) has a much more interesting role to play.
 * The call stack keeps track of all the active functions (those that have been called but have not yet terminated)
 * from the start of the program to the current point of execution, and handles allocation of all function
 * parameters and local variables.
 *
 *
 * # Recursion
 *
 * Recursive functions are functions that call themselves.
 *
 *
 * # Variable number of parameters - Ellipsis
 *
 * All parameters a function will take must be known in advance (even if they have default values).
 * However, there are certain cases where it can be useful to be able to pass a variable number of
 * parameters to a function. C++ provides a special specifier known as ellipsis *...*.
 *
 * **Avoid using ellipsis, for many reasons ... !**
 *
 *
 * # Lambdas - anonymous functions
 *
 * See [Lambdas](https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/) for reference!
 *
 * A **lambda expression** (also *lambda* or *closure*) allows to define an anonymous function inside another function.
 *
 * The syntax is:
 * ```C++
 * [ captureClause ] ( parameters ) -> returnType
 * {
 *     statements;
 * }
 * ```
 * Consequently a trivial lambda looks like: ```[]() {}```.
 *
 * In actuality, lambdas aren’t functions (which is part of how they avoid
 * the limitation of C++ not supporting nested functions). They’re a special kind of object called a **functor**.
 * **Functors** are objects that contain an overloaded operator() that make them callable like a function.
 *
 * **Use auto when initializing variables with lambdas, and std::function
 * if you can’t initialize the variable with the lambda.**
 *
 * # Function templates
 *
 */

// \fn void pass_by_value(int)

/**
 * \brief Function passing argument by value
 */
void pass_by_value(int x);

/**
 * \brief Function passing argument by reference
 */
void pass_by_reference(int &x);

/**
 * \brief Function passing argument by address
 */
void pass_by_address(int *x);


/**
 * \brief Function returning value by value
 */
int return_by_value();

/**
 * \brief Function returning value by reference
 */
int& return_by_reference();

/**
 * \brief Function returning value by address
 */
int* return_by_address();

/**
 * \brief Function adding two values
 */
int overload_add(int a, int b);

/**
 * \brief (Overloaded) Function adding three values
 */
int overload_add(int a, int b, int c);


/**
 * \brief Function with default argument (optional parameter)
 */
void func_default_arg(int x, int y=10);

/**
 * \brief A simple recursive function.
 */
void countDown(int count);

/**
 * \brief A simple function using ellipsis.
 */
void ellipsis_example(int count, ...);

/**
 * \brief A simple lambda function
 */
void lambda_example(std::array<std::string_view, 4> arr);

/**
 * \brief A simple template function.
 */
template <typename T> T max(T x, T y);




#endif //CPP_TEMPLATE_PROJECT_FUNCTIONS_H
