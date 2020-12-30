#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

int main()
{
    // The type is automatically deduced to std::array<int, 7> (Requires C++17).
    // Use the type std::array<int, 7> if your compiler doesn't support C++17.
    std::array<int, 7> data{ 0, 1, 2, 3, 4, 5, 6 };
    std::size_t length{ std::size(data) };

    // while-loop with explicit index
    std::cout << "While loop with explicit index" << std::endl;
    std::size_t index{ 0 };
    while (index != length)
    {
        std::cout << data[index] << ' ';
        ++index;
    }
    std::cout << '\n';

    // for-loop with explicit index
    std::cout << "For loop with explicit index" << std::endl;
    for (index = 0; index < length; ++index)
    {
        std::cout << data[index] << ' ';
    }
    std::cout << '\n';

    // for-loop with pointer (Note: ptr can't be const, because we increment it)
    std::cout << "For loop with pointer" << std::endl;
    for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    // ranged-based for loop
    std::cout << "Range based for loop" << std::endl;
    for (int i : data)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::cout << std::endl;

    /** Iterators */
    // Pointers (simplest kind of Iterators)
    std::cout << "Iterator: Pointer..." << std::endl;
    auto begin{ &data[0] };
    // note that this points to one spot beyond the last element
    auto end{ begin + std::size(data) };

    // for-loop with pointer
    for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
    {
        std::cout << *ptr << ' '; // Indirection to get value of current element
    }
    std::cout << '\n';

    // Standard library iterators
    std::cout << "Standard library iterators..." << std::endl;
    // Ask our array for the begin and end points (via the begin and end member functions).
    begin = { data.begin() };
    end = { data.end() };

    for (auto p{ begin }; p != end; ++p) // ++ to move to next element.
    {
        std::cout << *p << ' '; // Indirection to get value of current element.
    }
    std::cout << '\n';

    //
    std::cout << "or..." << std::endl;

    begin = { std::begin(data) };
    end = { std::end(data) };

    for (auto p{ begin }; p != end; ++p) // ++ to move to next element
    {
        std::cout << *p << ' '; // Indirection to get value of current element
    }
    std::cout << '\n';

    /** */

    return 0;
}