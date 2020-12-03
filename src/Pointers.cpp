//
// Created by Michael Staneker on 03.12.20.
//

#include <iostream>

/**
 * \section sec1 Introduction to Pointers
 *
 * See [LearnCpp](https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/)
 *
 * Pointers are:
 * * a
 * * b
 * * c
 * */

int main() {

    int x{ 5 };
    std::cout << "    x = " << x << '\n'; // print the value of variable x

    /** \subsection ssec1 Address operator & */
    std::cout << "   &x = " << &x << '\n'; // print the memory address of variable x
    /** */

    /** \subsection ssec2 Indirection operator * */
    std::cout << "*(&x) = " << *(&x) << '\n'; // print the memory address of variable x
    /** */

    /** \subsection Pointers */
    //int *iPtr{}; // a pointer to an integer value
    //double *dPtr{}; // a pointer to a double value
    //int* iPtr2{}; // also valid syntax (acceptable, but not favored)
    //int * iPtr3{}; // also valid syntax (but don't do this, it looks like multiplication)
    //int *iPtr4{}, *iPtr5{}; // declare two pointers to integer variables (not recommended)

    int var{ 5 };
    int *ptr{ &var }; // initialize ptr with address of variable v
    std::cout << "var = " << var << '\n'; // print the address of variable v
    std::cout << "var = " << &var << '\n'; // print the address of variable v
    std::cout << "ptr = " << ptr << '\n'; // print the address that ptr is holding
    std::cout << "*ptr = " << *ptr << '\n';

    //    Pointers are good for:
    //    * dynamic arrays
    //    * dynamically allocate memory
    //    * pass large amount of data to a function (without copying)
    //    * pass a function as a parameter to another function
    //    * achieve polymorphism when dealing with inheritance
    //    * useful for advanced data structures
    /** */

    /** \subsubsection Null pointer */
    //assigning it to the literal 0
    float *null_ptr { 0 };  // ptr is now a null pointer
    float *null_ptr2; // ptr2 is uninitialized
    null_ptr2 = 0; // ptr2 is now a null pointer
    float *null_ptr3 {nullptr}; // C++11
    /** */

    /** \subsubsection Pointers & arrays */
    int array[5]{ 9, 7, 5, 3, 1 };
    std::cout << *array << '\n'; // will print 9
    int *ptr_for_array{ array };
    std::cout << *ptr_for_array << '\n'; // will print 9

    // ARRAYS DECAY INTO POINTERS WHEN PASSED TO FUNCTIONS !!!
    /** */

    /**
     * \subsubsection Pointer arithmetic
     *  \code
     * */
    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array+1 << '\n'; // print memory address of array pointer + 1
    std::cout << array[1] << '\n'; // prints 7
    std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)
    /**
     * \endcode
     * */

    /**
     * \subsubsection Dynamic memory allocation
     * \code
     * */
    //new int; // dynamically allocate an integer (and discard the result)
    int *ptr_dyn{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later
    *ptr_dyn = 7;
    // equivalent: int *ptr_dyn{ new int { 7 }}
    std::cout << "ptr_dyn = " << ptr_dyn << std::endl;
    std::cout << "*ptr_dyn = " << *ptr_dyn << std::endl;

    // delete
    delete ptr_dyn; // return the memory pointed to by ptr to the operating system
    ptr_dyn = 0; // set ptr to be a null pointer (use nullptr instead of 0 in C++11)


    // Dynamically allocating arrays
    int *dyn_array{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11
    // To prevent writing the type twice, we can use auto. This is often done for types with long names.
    //auto *array{ new int[5]{ 9, 7, 5, 3, 1 } };
    delete [] dyn_array;
    /**
     * \endcode
     * */


    /**
     * \subsubsection oid pointers (generic pointer)
     * \code
     * */
    int nValue;
    float fValue;
    struct Something
    {
        int n;
        float f;
    };
    Something sValue;
    void *void_ptr;
    void_ptr = &nValue; // valid
    void_ptr = &fValue; // valid
    void_ptr = &sValue; // valid
    // ATTENTION: indirection is only possible using a cast
    /**
     * \endcode
     * */

    /**
     * \subsubsection Pointers to pointer
     * \code
     * */
    int value_for_pointer = 5;

    int *primary_ptr = &value_for_pointer;
    std::cout << "ptr = " << *primary_ptr << std::endl; // Indirection through pointer to int to get int value

    int **ptrptr = &primary_ptr;
    std::cout << "ptrptr = " << **ptrptr << std::endl; // first indirection to get pointer to int, second indirection to get int value

    int **pointer_array = new int*[10]; // allocate an array of 10 int pointers
    /**
     * \endcode
     * */

    return 0;
}

