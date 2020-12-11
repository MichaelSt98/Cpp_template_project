//
// Created by Michael Staneker on 09.12.20.
//

#include "SampleClass.h"

SampleClass::SampleClass() {
    std::cout << "Default constructor was called ..." << std::endl;
    member_a = 0;
    member_b = 0;
}

int SampleClass::static_member_variable = 5;

//SampleClass::SampleClass(int a, int b) {
//    std::cout << "Constructor: SampleClass(" << a << ", " << b << ") ..." << std::endl;
//    member_a = a;
//    member_b = b;
//}
// equivalent implementation using an initialization list
SampleClass::SampleClass(int a, int b)
: member_a{ a }, member_b{ b }
{
    std::cout << "Constructor: SampleClass(" << a << ", " << b << ") ..." << std::endl;
}

SampleClass::SampleClass(int a, int b, int c): SampleClass{ a, b } {
    std::cout << "Constructor: SampleClass(" << a << ", " << b << ", " << c << ") ..." << std::endl;
}

//Destructor
SampleClass::~SampleClass() {
    std::cout << "Destructor was called" << std::endl;
}

SampleClass::SampleClass(const SampleClass &sample_class) :
        member_a(sample_class.member_a), member_b(sample_class.member_b)
{
    std::cout << "Copy constructor called\n"; // just to prove it works
}

int SampleClass::get_member_a() {
    return member_a;
}

int SampleClass::get_member_b() {
    return member_b;
}

void SampleClass::set_member_a(int a) {
    std::cout << "set member_a to: " << a << std::endl;
    member_a = a;
}

void SampleClass::set_member_b(int b) {
    std::cout << "set member_b to: " << b << std::endl;
    member_b = b;
}

void SampleClass::set_members_using_this(int member_a, int member_b) {
    this->member_a = member_a;
    this->member_b = member_b;
}

void SampleClass::const_member_function() const {
    std::cout << "This is a const member function!" << std::endl;
}

void SampleClass::static_member_function() {
    std::cout << "This is a static member function" << std::endl;
}

void friend_function(SampleClass &sample_class) {
    std::cout << "This is a friend function" << std::endl;
    std::cout << "Accessing private member member_a: " << sample_class.member_a << std::endl;
}

SampleClass operator+(const SampleClass &s_1, const SampleClass &s_2) {
    std::cout << "overloaded operator+ for SampleClass!" << std::endl;
    return SampleClass(s_1.member_a + s_2.member_a, s_1.member_b + s_2.member_b);
}

std::ostream& operator<< (std::ostream &out, const SampleClass &sample_class) {

    out << std::endl
        << "member_a = " << sample_class.member_a << std::endl
        << "member_b = " << sample_class.member_b << std::endl;

    return out;
}

int SampleClass::operator()(int i) {
    return (member_a += i);
}
