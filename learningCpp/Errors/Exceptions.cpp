//
// Created by Michael Staneker on 10.12.20.
//

#include "Exceptions.h"


ArrayException::ArrayException(std::string_view error)
        : m_error{error}
{
}



int IntArray::getLength() const {
    return 3;
}

int& IntArray::operator[](const int index)
{
    if (index < 0 || index >= getLength())
        throw ArrayException("Invalid index");

    return m_data[index];
}


double SQRT::mySqrt(double x) {
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return sqrt(x);
}