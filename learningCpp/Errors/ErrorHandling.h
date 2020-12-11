//
// Created by Michael Staneker on 09.12.20.
//

#include <cstdlib> //for std::exit
#include <cassert> //for assert()

#ifndef CPP_TEMPLATE_PROJECT_ERRORHANDLING_H
#define CPP_TEMPLATE_PROJECT_ERRORHANDLING_H

/**
 * # Error handling
 *
 * Errors fall into two categories:
 * * **Syntax errors** occurring when a statement is not valid according to the grammar of the C++ language
 * * **Semantic errors** occurring when a statement is syntactically valid, but does not do what the programmer intended
 *
 * ## Assert statements
 *
 * An assert statement is a preprocessor macro that evaluates a conditional expression at runtime.
 * If the conditional expression is true, the assert statement does nothing. If the conditional
 * expression evaluates to false, an error message is displayed and the program is terminated.
 * This error message contains the conditional expression that failed, along with the name of
 * the code file and the line number of the assert.
 *
 * ### assert()
 *
 * Include <cstdlib> for ```assert()```, operating at runtime, which comes with a small performance cost that is
 * incurred each time the assert condition is checked, which can be disabled by defining the **NDEBUG**
 * macro.
 *
 * ### static_assert()
 *
 * Another type of assert is ```static_assert<condition, diagnostic_message>```, designed to operate at compile time.
 *
 * **Attention** There is no chance for cleanup after terminating with exit() or assert()!
 *
 */

int returning_error_code();

void write_error_message();

void exit_program();

void assert_example(int x);

#endif //CPP_TEMPLATE_PROJECT_ERRORHANDLING_H
