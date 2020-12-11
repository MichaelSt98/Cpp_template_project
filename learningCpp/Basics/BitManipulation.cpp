//
// Created by Michael Staneker on 01.12.20.
//

/**
 * # Basic Bit Manipulation
 *
 * C++ supports bit manipulation using the standard bit operators.
 */

#include <bitset>

int main() {

    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    /** ## Bitwise operators
     * ```cpp
     * x << y // left shift
     * x >> y // right shift
     * ~x // bitwise NOT
     * x & y // bitwise AND
     * x | y // bitwise OR
     * x ^ y // bitwise XOR
     * x <<= < // left shift assignment
     * x >>= y // right shift assignment
     * x |= y // bitwise OR assignment
     * x &= y // bitwise AND assignment
     * x ^= y // bitwise XOR assignment
     * ```
     */

    /** ## Bit masks
     * \code
     * */
    // since C++14
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7
    // C++11 or earlier
    //    constexpr std::uint_fast8_t mask0{ 0x1 }; // hex for 0000 0001
    //    constexpr std::uint_fast8_t mask1{ 0x2 }; // hex for 0000 0010
    //    constexpr std::uint_fast8_t mask2{ 0x4 }; // hex for 0000 0100
    //    constexpr std::uint_fast8_t mask3{ 0x8 }; // hex for 0000 1000
    //    constexpr std::uint_fast8_t mask4{ 0x10 }; // hex for 0001 0000
    //    constexpr std::uint_fast8_t mask5{ 0x20 }; // hex for 0010 0000
    //    constexpr std::uint_fast8_t mask6{ 0x40 }; // hex for 0100 0000
    //    constexpr std::uint_fast8_t mask7{ 0x80 }; // hex for 1000 0000
    //    // or
    //    constexpr std::uint_fast8_t mask0{ 1 << 0 }; // 0000 0001
    //    constexpr std::uint_fast8_t mask1{ 1 << 1 }; // 0000 0010
    //    constexpr std::uint_fast8_t mask2{ 1 << 2 }; // 0000 0100
    //    constexpr std::uint_fast8_t mask3{ 1 << 3 }; // 0000 1000
    //    constexpr std::uint_fast8_t mask4{ 1 << 4 }; // 0001 0000
    //    constexpr std::uint_fast8_t mask5{ 1 << 5 }; // 0010 0000
    //    constexpr std::uint_fast8_t mask6{ 1 << 6 }; // 0100 0000
    //    constexpr std::uint_fast8_t mask7{ 1 << 7 }; // 1000 0000
    /**
     * \endcode
     * */

    return 0;
}

