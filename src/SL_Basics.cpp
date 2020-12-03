//
// Created by Michael Staneker on 03.12.20.
//

#include <iostream>

#include <array> // C++ built in fixed arrays in a safer and more usable form
#include <vector> // makes working with dynamic arrays safer and easier
#include <string> //TODO: section about std::string


int main() {
    /** std::array */
    //std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initializer list
    std::array<int, 5> my_array{9, 7, 5, 3, 1}; // list initialization
    my_array[0] = 10; // standard accessing
    my_array.at(1) = 8; // other possibility
    std::cout << "size of my_array: " << my_array.size() << std::endl;
    /** */

    /** std::vector */
    // dynamic arrays without the need of dynamically allocating memory

    //std::vector<int> vec_array;
    //std::vector<int> vec_array = { 9, 7, 5, 3, 1 }; // use initializer list to initialize array (Before C++11)
    std::vector<int> vec_array { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize array
    vec_array[0] = 10; // standard accessing
    vec_array.at(1) = 8; // other possibility
    std::cout << "size of vec_array: " << vec_array.size() << std::endl;
    // resize
    vec_array.resize(10);
    std::cout << "size of vec_array (after resize): " << vec_array.size() << std::endl;
    /** */


    /** std::string*/

    /** */


    // Algorithms
    //* **Inspectors** are used to view (not modify) data in container (including searching and counting)
    //* **Mutators** are used to modify data in a container (including sorting and shuffling)
    //* **Facilitators** are used to generate a result based on values of the data members

    return 0;
}