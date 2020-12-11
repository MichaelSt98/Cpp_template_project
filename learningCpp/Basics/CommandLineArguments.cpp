//
// Created by Michael Staneker on 09.12.20.
//

#include <iostream>

/**
 * # Command line arguments
 *
 * In order to pass command line arguments to the program use
 * * ```int main(int argc, char *argv[])```
 * * ```int main(int argc, char** argv)```
 * both are treated identically!
 *
 * * **argc** is an integer parameter containing a count of the number of arguments passed to the program,
 *   whereas **argc** is always at least 1, since the first argument is always the name of the program itself
 * * **argv** is where the actual arguments are stored (within an array of C-style strings)
 *
 * */

int main(int argc, char *argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    // handle numeric values
    //std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]
    //int myint{};
    //if (!(convert >> myint)) // do the conversion
    //    myint = 0; // if conversion fails, set myint to a default value
    //std::cout << "Got integer: " << myint << '\n';

    return 0;
}
