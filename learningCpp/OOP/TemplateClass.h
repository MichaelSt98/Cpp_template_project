//
// Created by Michael Staneker on 10.12.20.
//

/**
 * # Class templates
 *
 * In order to create classes for different data types use **template classes**.
 *
 * ## Specialization
 *
 * ### Function specialization
 *
 * It is possible to overwrite (individual) member function for
 *
 * * different data types
 * * pointer (types)
 * * ...
 *
 * ### Class specialization
 *
 * It is possible to overwrite an entire template class for specific data types.
 *
 * See [class specialization](https://www.learncpp.com/cpp-tutorial/136-class-template-specialization/)
 * for reference.
 *
 */

#ifndef CPP_TEMPLATE_PROJECT_TEMPLATECLASS_H
#define CPP_TEMPLATE_PROJECT_TEMPLATECLASS_H

#include <iostream>
#include <cassert>

template <class T>
class Array
{
private:
    int m_length{};
    T *m_data{};
public:

    Array(int length);

    Array(const Array&) = delete;

    Array& operator=(const Array&) = delete;

    ~Array();

    void Erase();

    T& operator[](int index);

    int getLength() const;

    void print();

};


template <class T, int size> // size is the non-type parameter
class StaticArray
{
private:
    // The non-type parameter controls the size of the array
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index);
};

#include "TemplateClass.inl"

#endif //CPP_TEMPLATE_PROJECT_TEMPLATECLASS_H
