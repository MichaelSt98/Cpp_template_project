//
// Created by Michael Staneker on 10.12.20.
//

#include "TemplateClass.h"

#include <iostream>

int main()
{
    Array<int> intArray(12);
    Array<double> doubleArray(12);

    for (int count{ 0 }; count < intArray.getLength(); ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
        std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

    intArray.print();
    doubleArray.print();

    // declare an integer array with room for 12 integers
    StaticArray<int, 12> staticintArray;

    // Fill it up in order, then print it backwards
    for (int count=0; count < 12; ++count)
        staticintArray[count] = count;

    for (int count=11; count >= 0; --count)
        std::cout << staticintArray[count] << " ";
    std::cout << '\n';

    // declare a double buffer with room for 4 doubles
    StaticArray<double, 4> staticdoubleArray;

    for (int count=0; count < 4; ++count)
        staticdoubleArray[count] = 4.4 + 0.1*count;

    for (int count=0; count < 4; ++count)
        std::cout << staticdoubleArray[count] << ' ';

    return 0;
}

