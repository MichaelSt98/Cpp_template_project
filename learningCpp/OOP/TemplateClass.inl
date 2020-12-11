//
// Created by Michael Staneker on 10.12.20.
//

#include "TemplateClass.h"

template <class T>
Array<T>::Array(int length)
{
    assert(length > 0);
    m_data = new T[length]{};
    m_length = length;
}

template <class T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <class T>
void Array<T>::Erase()
{
    delete[] m_data;
    // We need to make sure we set m_data to 0 here, otherwise it will
    // be left pointing at deallocated memory!
    m_data = nullptr;
    m_length = 0;
}

template <class T>
T& Array<T>::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

template <class T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
    return m_length;
}

template <class T>
void Array<T>::print() {
    std::cout << "General print() function..." << std::endl;
}

template <>
void Array<int>::print() {
    std::cout << "INT print() function..." << std::endl;
}

template <>
void Array<double>::print() {
    std::cout << "DOUBLE print() function..." << std::endl;
}


template <class T, int size>
T& StaticArray<T, size>::operator[](int index)
{
    return m_array[index];
}

// Showing how a function for a class with a non-type parameter is defined outside of the class
template <class T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}