//
// Created by Michael Staneker on 10.12.20.
//

#include "Inheritance.h"

#include <iostream>

int main()
{
    Derived derived{ 1.3, 5, 1, 2, 3};
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';
    //std::cout << "private: " << derived.m_private << '\n';
    std::cout << "private: " << derived.getPrivate() << '\n';
    std::cout << "protected: " << derived.getProtected() << '\n';
    std::cout << "public: " << derived.m_public << '\n';

    Base &rBase{ derived };
    derived.print();


    return 0;
}
