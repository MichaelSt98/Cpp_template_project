//
// Created by Michael Staneker on 10.12.20.
//

/**
 * # Inheritance
 *
 * ## Access specifiers
 *
 * There are three access specifiers
 *
 * * **public**: accessible from base and derived class, and from outside
 * * **protected**: accessible from base class and derived class
 * * **private**: accessible from base class
 *
 * ```cpp
 * class Derived: <access specifier> Base
 * {
 * }
 * ```
 *
 * ### Public inheritance
 *
 * * public --> public
 * * protected --> protected
 * * private --> inaccessible
 *
 * ### Protected inheritance
 *
 * * public --> protected
 * * protected --> protected
 * * private --> inaccessible
 *
 * ### Private Inheritance
 *
 * * public --> private
 * * protected --> private
 * * private --> inaccessible
 *
 * ## Multiple inheritance
 *
 * C++ supports **multiple inheritance**, but many problems can occur.
 * Since most of the problems solvable with multiple inheritance can be solved
 * without multiple inheritance, prefer solutions without multiple inheritance.
 *
 * **Avoid multiple inheritance unless alternatives lead to more complexity.**
 *
 * ## Virtual functions and Polymorphism
 *
 * A **virtual function** is a special type of function that, when called,
 * resolves to the most-derived version of the function that exists between the
 * base and derived class. This capability is known as **polymorphism**.
 *
 * **Attention**: Resolving a virtual function call takes longer than resolving a regular one.
 * Furthermore, the compiler also has to allocate an extra pointer for each class object that has
 * one or more virtual functions.
 *
 * When dealing with inheritance, (overwritten) **destructors** should always be virtual!
 *
 * ## Override and final specifiers
 *
 * To help address the issue of functions that are meant to be overrides but aren’t, C++11 introduced
 * the **override** specifier. The override specifier can be applied to any override function by placing
 * the specifier in the same place const would go.
 *
 * There may be cases where you don’t want someone to be able to override a virtual function, or
 * inherit from a class. The **final** specifier can be used to tell the compiler to enforce this. If
 * the user tries to override a function or inherit from a class that has been specified as final,
 * the compiler will give a compile error.
 *
 * ## Pure virtual functions, abstract base classes and interface classes
 *
 * ### Pure virtual functions
 *
 * C++ allows to create a special kind of virtual function called a
 * pure virtual function (or abstract function) that has no body at all! A pure
 * virtual function simply acts as a placeholder that is meant to be redefined by derived classes.
 *
 * **Any class with at least one pure virtual function becomes an abstract base class and cannot be
 * instantiated**
 *
 * ### Abstract base classes
 *
 * **Abstract base classes** can not be instantiated!
 *
 * ### Interface classes
 *
 * An **interface class** has no member variables and only pure virtual (member) functions. Thus,
 * interface classes are pure definitions and have no actual implementations.
 *
 */

#ifndef CPP_TEMPLATE_PROJECT_INHERITANCE_H
#define CPP_TEMPLATE_PROJECT_INHERITANCE_H

#include <string>
#include <iostream>

class Base
{
private:
    int m_id;
    int m_private;
protected:
    int m_protected;
    int getPrivate() const;
public:
    int m_public;

    Base(int id=0, int var_private=0, int var_protected=0, int var_public=0);

    int getId() const;

    virtual void print();
};

class Derived: public Base
{
private:
    double m_cost;

public:
    Derived(double cost=0.0, int id=0, int var_private=0, int var_protected=0, int var_public=0);
    double getCost() const;
    double getProtected() const;
    double getPrivate() const;

    virtual void print();
};

#endif //CPP_TEMPLATE_PROJECT_INHERITANCE_H
