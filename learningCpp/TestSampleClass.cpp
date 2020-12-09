//
// Created by Michael Staneker on 09.12.20.
//

#include "SampleClass.h"
#include "Timer.h"
#include <iostream>

int main() {

    Timer t;

    // call default constructor
    //SampleClass sample_class;

    // call constructor with arguments
    // copy direct initialization
    //SampleClass sample_class = SampleClass(5, 10); //equivalent to
    // copy list initialization
    //SampleClass sample_class = SampleClass{5, 10}; //equivalent to
    // direct initialization
    //SampleClass sample_class(5, 10); // equivalent to
    // list initialization
    SampleClass sample_class{5, 10};

    SampleClass copy_sample_class(sample_class);

    // call with default value for member_b
    //SampleClass sample_class{5};

    // call with three arguments (ex. for delegating constructors)
    //SampleClass sample_class{5, 10, 15};

    std::cout << "sample_class.member_a = " << sample_class.get_member_a() << std::endl;
    std::cout << "sample_class.member_b = " << sample_class.get_member_b() << std::endl;

    sample_class.set_member_a(2);
    sample_class.set_member_b(4);

    std::cout << "sample_class.member_a = " << sample_class.get_member_a() << std::endl;
    std::cout << "sample_class.member_b = " << sample_class.get_member_b() << std::endl;

    // allocate a SampleClass dynamically
    SampleClass *dyn_sample_class { new SampleClass{ 1, 6}};
    std::cout << "dyn_sample_class.member_a = " << dyn_sample_class->get_member_a() << std::endl;
    std::cout << "dyn_sample_class.member_b = " << dyn_sample_class->get_member_b() << std::endl;
    //delete dyn_sample_class;

    // set static counter
    std::cout << "(static) counter = " << SampleClass::static_member_variable << std::endl;
    std::cout << "(static) counter = " << sample_class.static_member_variable << std::endl;

    SampleClass::static_member_function();
    sample_class.static_member_function();

    friend_function(sample_class);

    SampleClass s_1 {2, 2};
    SampleClass s_2 {4, 5};
    SampleClass s_3 = s_1 + s_2;

    std::cout << "s_3: " << s_3 << std::endl;

    std::cout << "s_3(10): " << s_3(10) << std::endl;

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}
