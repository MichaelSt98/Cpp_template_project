//
// Created by Michael Staneker on 09.12.20.
//

#include <iostream>

#ifndef CPP_TEMPLATE_PROJECT_SAMPLECLASS_H
#define CPP_TEMPLATE_PROJECT_SAMPLECLASS_H

/**
 * # Classes - OOP
 *
 * **Use structs for data-only objects and classes otherwise!**
 *
 * ## Properties
 *
 * * member variables are private per default
 *      * public in case of structs
 * * if no constructor is given, a default constructor is created
 * * getter should either return by value or reference
 * * const class objects can only call const member functions
 *
 * ## Friend functions and classes
 *
 * See [Friend functions and classes](https://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/)
 * for reference!
 *
 * Classes keep your data private and encapsulated. However, in some situations you need to have classes and functions
 * outside of those classes that need to work closely together.
 *
 * For doing this, without exposing the function use the **friend** identifier.
 *
 * It is possible to have
 * * friend functions
 * * friend member functions
 * * friend classes
 * * ...
 *
 */


class SampleClass {
private:
    int member_a{ 0 };
    int member_b{ 0 };
public:
    //static variables are shared by all objects/instants of the class
    static int static_member_variable;
    // getter
    int get_member_a();
    int get_member_b();
    // setter
    void set_member_a(int a);
    void set_member_b(int b);

    void set_members_using_this(int member_a, int member_b);

    // const member function that cannot change member variables
    // can be overwritten with a non const function
    void const_member_function() const;

    // default constructor
    SampleClass();
    // constructor with arguments
    SampleClass(int a, int b = 0);

    //example for delegating constructors
    SampleClass(int a, int b, int c);

    // Copy constructor
    // prevent copies by making the copy constructor private
    SampleClass(const SampleClass &sample_class);

    ~SampleClass();

    static void static_member_function();

    friend void friend_function(SampleClass &sample_class);

    friend SampleClass operator+(const SampleClass &s_1, const SampleClass &s_2);
    friend std::ostream& operator<< (std::ostream &out, const SampleClass &sample_class);

    int operator() (int i);

    // it is possible to have nested types within classes
    enum FruitType {
        APPLE,
        BANANA,
        CHERRY
    };
};



#endif //CPP_TEMPLATE_PROJECT_SAMPLECLASS_H
