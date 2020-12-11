//
// Created by Michael Staneker on 10.12.20.
//

#include "Inheritance.h"

Base::Base(int id, int var_private, int var_protected, int var_public)
        : m_id{ id }, m_private{ var_private }, m_protected{ var_protected },
          m_public{ var_public }
{
    std::cout << "Base constructor called ..." << std::endl;
}

int Base::getId() const {
    return m_id;
}

int Base::getPrivate() const {
    std::cout << "getPrivate() from Base" << std::endl;
    return m_private;
}

void Base::print() {
    std::cout << "Print from Base class!" << std::endl;
}



Derived::Derived(double cost, int id, int var_private, int var_protected, int var_public)
        : Base{ id, var_private, var_protected, var_public }, // Call Base(int) constructor with value id!
          m_cost{ cost }
{
    std::cout << "Derived constructor called ..." << std::endl;
}

double Derived::getCost() const {
    return m_cost;
}

double Derived::getProtected() const {
    return m_protected;
}

double Derived::getPrivate() const {
    std::cout << "getPrivate() from Derived" << std::endl;
    return Base::getPrivate();
}

void Derived::print() {
    std::cout << "Print from Derived class!" << std::endl;
}