//
// Created by Michael Staneker on 03.12.20.
//

#include <iostream>

#include <array> // C++ built in fixed arrays in a safer and more usable form
#include <vector> // makes working with dynamic arrays safer and easier
#include <string> //TODO: section about std::string
/**
 * # Introduction to the standard library
 *
 * The Standard library contains a collection of classes that provide templated containers,
 * algorithms, and iterators. If you need a common class or algorithm, odds are the standard
 * library has it. The upside is that you can take advantage of these classes without having
 * to write and debug the classes yourself, and the standard library does a good job providing
 * reasonably efficient versions of these classes. The downside is that the standard library is
 * complex, and can be a little intimidating since everything is templated.
 *
 * ## STL containers
 *
 * There are three basic container categories:
 *
 * * **Sequence containers** maintaining the ordering of elements within the container
 *      * std::vector: dynamic array capable of growing, fast insertion and removing at the end
 *      * std::deque: double-ended queue class, implemented as a dynamic array that can grow from both ends
 *      * std::array
 *      * std::list
 *      * std::forward_list
 *      * std::basic_string
 * * **Associative containers** automatically sorting the inputs when those inputs are inserted into the container
 *      * set: storing unique elements
 *      * mulitset: duplicate elements allowed
 *      * map (or associative array): each element is a pair, called a key/value pair, key must be unique
 *      * multimap (or dictionary): map allowing duplicate keys
 * * **Container adapters**: are special predefined containers that are adapted to specific uses
 *      * stack: elements operate in a LIFO (Last In, First Out)
 *      * queue: elements operate in a FIFO (First In, First Out)
 *      * priority queue: elements are kept sorted (via operator<)
 *
 * ## STL iterators
 *
 * * **Operator* ** Dereferencing the iterator returns the element that the iterator is currently pointing at
 * * **Operator++** Moves the iterator to the next element in the container.
 * * Most iterators also provide Operator-- to move to the previous element.
 * * Operator== and Operator!= -- Basic comparison operators to determine if two iterators
 *   point to the same element. To compare the values that two iterators are pointing at,
 *   dereference the iterators first, and then use a comparison operator.
 * * Operator= -- Assign the iterator to a new position (typically the start or end of the container’s elements).
 *   To assign the value of the element the iterator is pointing at, dereference the iterator first,
 *   then use the assign operator.
 *
 * Each container includes four basic member functions for use with **Operator=:**
 * * *begin()* returns an iterator representing the beginning of the elements in the container.
 * *end()* returns an iterator representing the element just past the end of the elements.
 * *cbegin()* returns a const (read-only) iterator representing the beginning of the elements in the container.
 * *cend()* returns a const (read-only) iterator representing the element just past the end of the elements.
 *
 * All containers provide (at least) two types of iterators:
 * * **container::iterator** provides a read/write iterator
 * * **container::const_iterator** provides a read-only iterator
 *
 * ## Formatting output
 *
 * See [ostream](https://www.learncpp.com/cpp-tutorial/183-output-with-ostream-and-ios/)
 *
 * ## File IO
 *
 * See [Basic file IO](https://www.learncpp.com/cpp-tutorial/186-basic-file-io/)
 *
 *
 *
 */

int main() {
    /** ## std::array */
    //std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initializer list
    std::array<int, 5> my_array{9, 7, 5, 3, 1}; // list initialization
    my_array[0] = 10; // standard accessing
    my_array.at(1) = 8; // other possibility
    std::cout << "size of my_array: " << my_array.size() << std::endl;
    /** */

    /** ## std::vector */
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


    /** ## std::string*/

    /** */


    /**
     * ## Algorithms
     *
     * * **Inspectors** are used to view (not modify) data in container (including searching and counting)
     * * **Mutators** are used to modify data in a container (including sorting and shuffling)
     * * **Facilitators** are used to generate a result based on values of the data members
     */



    /**
     *
     */

    return 0;
}