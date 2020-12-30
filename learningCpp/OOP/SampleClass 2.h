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
 * ## Overloading operators
 *
 * [Overloading assignment operator](https://www.learncpp.com/cpp-tutorial/9-14-overloading-the-assignment-operator/)
 *
 * ## Shallow vs. deep copy
 *
 * The default copy mechanism for classes is **memberwise** copy (also called **shallow copy**),
 * which works for simple classes, without dynamically reserved memory, very good.
 *
 * However, a **deep copy** allocates memory for the copy and then copies
 * the actual value, so that the copy lives in distinct memory from the source.
 * This requires to write copy constructors and overloaded assignment operators.
 *
 * * The default copy constructor and default assignment operators do shallow copies,
 *   which is fine for classes that contain no dynamically allocated variables.
 * * Classes with dynamically allocated variables need to have a copy constructor and
 *   assignment operator that do a deep copy.
 * * Favor using classes in the standard library over doing your own memory management.
 *
 * ## Object relations
 *
 * | Property/type                      | Composition   | Aggregation   | Association   | Dependency   |
 * | ---------------------------------- |---------------|---------------|---------------|---------------|
 * | relationship                       | whole/part    | whole/part    | unrelated     | unrelated     |
 * | members belong to multiple classes | No            | Yes           | Yes           | Yes           |
 * | members existence managed by class | Yes           | No            | No            | No            |
 * | directionality                     | Uni           | Uni           | Uni or bi     | Uni           |
 * | relationship verb                  | part-of       | has-a         | uses-a        | depends-on    |
 *
 * ### Composition
 *
 * To qualify as a composition, an object and a part must have the following relationship:
 *
 * * The part (member) is part of the object (class)
 * * The part (member) can only belong to one object (class) at a time
 * * The part (member) has its existence managed by the object (class)
 * * The part (member) does not know about the existence of the object (class)
 *
 * Therefore:
 *
 * * Typically use normal member variables
 * * Can use pointer members if the class handles object allocation/deallocation itself
 * * Responsible for creation/destruction of parts
 *
 *
 * ### Aggregation
 *
 * To qualify as an aggregation, a whole object and its parts must have the following relationship:
 *
 * * The part (member) is part of the object (class)
 * * The part (member) can belong to more than one object (class) at a time
 * * The part (member) does not have its existence managed by the object (class)
 * * The part (member) does not know about the existence of the object (class)
 *
 * Therefore:
 *
 * * Typically use pointer or reference members that point to or reference objects that live outside the
 *   scope of the aggregate class
 * * Not responsible for creating/destroying parts
 *
 *
 * ### Association
 *
 * * To qualify as an association, an object and another object must have the following relationship:
 * * The associated object (member) is otherwise unrelated to the object (class)
 * * The associated object (member) can belong to more than one object (class) at a time
 * * The associated object (member) does not have its existence managed by the object (class)*
 * * The associated object (member) may or may not know about the existence of the object (class)
 *
 *
 * ## Container classes
 *
 * See [Container classes](https://www.learncpp.com/cpp-tutorial/106-container-classes/)
 *
 * Container classes typically implement a fairly standardized minimal set of functionality.
 * Most well-defined containers will include functions that:
 *
 * * Create an empty container (via a constructor)
 * * Insert a new object into the container
 * * Remove an object from the container
 * * Report the number of objects currently in the container
 * * Empty the container of all objects
 * * Provide access to the stored objects
 * * Sort the elements (optional)
 *
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
