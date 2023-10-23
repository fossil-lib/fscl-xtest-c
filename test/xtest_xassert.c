/*  ----------------------------------------------------------------------------
    File: xtest_xassert.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xtest.h>
#include <trilobite/xassert.h>

#include <stdint.h>
#include <wchar.h>

//
// TEST CASES
//
XTEST_CASE(xassert_run_of_int) {
    int x = 42;
    int y = 20;

    // Test cases
    XASSERT_INT_EQUAL(x, 42);                // Should pass
    XASSERT_INT_EQUAL(y, 20);                // Should pass
    XASSERT_INT_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT_LESS(y, x);                 // Should pass
    XASSERT_INT_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int8) {
    int8_t x = 42;
    int8_t y = 20;

    // Test cases
    XASSERT_INT8_EQUAL(x, 42);                // Should pass
    XASSERT_INT8_EQUAL(y, 20);                // Should pass
    XASSERT_INT8_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT8_LESS(y, x);                 // Should pass
    XASSERT_INT8_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT8_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int16) {
    int16_t x = 42;
    int16_t y = 20;

    // Test cases
    XASSERT_INT16_EQUAL(x, 42);                // Should pass
    XASSERT_INT16_EQUAL(y, 20);                // Should pass
    XASSERT_INT16_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT16_LESS(y, x);                 // Should pass
    XASSERT_INT16_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT16_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int32) {
    int32_t x = 42;
    int32_t y = 20;

    // Test cases
    XASSERT_INT32_EQUAL(x, 42);                // Should pass
    XASSERT_INT32_EQUAL(y, 20);                // Should pass
    XASSERT_INT32_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT32_LESS(y, x);                 // Should pass
    XASSERT_INT32_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT32_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int64) {
    int64_t x = 42;
    int64_t y = 20;

    // Test cases
    XASSERT_INT64_EQUAL(x, 42);                // Should pass
    XASSERT_INT64_EQUAL(y, 20);                // Should pass
    XASSERT_INT64_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT64_LESS(y, x);                 // Should pass
    XASSERT_INT64_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT64_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_uint) {
    unsigned int x = 42;
    unsigned int y = 20;

    // Test cases
    XASSERT_UINT_EQUAL(x, 42);                // Should pass
    XASSERT_UINT_EQUAL(y, 20);                // Should pass
    XASSERT_UINT_NOT_EQUAL(x, y);            // Should pass
    XASSERT_UINT_LESS(y, x);                 // Should pass
    XASSERT_UINT_LESS_EQUAL(y, x);           // Should pass
    XASSERT_UINT_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_uint8) {
    uint8_t x = 42;
    uint8_t y = 20;

    // Test cases
    XASSERT_UINT8_EQUAL(x, 42);                // Should pass
    XASSERT_UINT8_EQUAL(y, 20);                // Should pass
    XASSERT_UINT8_NOT_EQUAL(x, y);            // Should pass
    XASSERT_UINT8_LESS(y, x);                 // Should pass
    XASSERT_UINT8_LESS_EQUAL(y, x);           // Should pass
    XASSERT_UINT8_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_uint16) {
    uint16_t x = 42;
    uint16_t y = 20;

    // Test cases
    XASSERT_UINT16_EQUAL(x, 42);                // Should pass
    XASSERT_UINT16_EQUAL(y, 20);                // Should pass
    XASSERT_UINT16_NOT_EQUAL(x, y);            // Should pass
    XASSERT_UINT16_LESS(y, x);                 // Should pass
    XASSERT_UINT16_LESS_EQUAL(y, x);           // Should pass
    XASSERT_UINT16_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_uint32) {
    uint32_t x = 42;
    uint32_t y = 20;

    // Test cases
    XASSERT_UINT32_EQUAL(x, 42);                // Should pass
    XASSERT_UINT32_EQUAL(y, 20);                // Should pass
    XASSERT_UINT32_NOT_EQUAL(x, y);            // Should pass
    XASSERT_UINT32_LESS(y, x);                 // Should pass
    XASSERT_UINT32_LESS_EQUAL(y, x);           // Should pass
    XASSERT_UINT32_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_uint64) {
    uint64_t x = 42;
    uint64_t y = 20;

    // Test cases
    XASSERT_UINT64_EQUAL(x, 42);                // Should pass
    XASSERT_UINT64_EQUAL(y, 20);                // Should pass
    XASSERT_UINT64_NOT_EQUAL(x, y);            // Should pass
    XASSERT_UINT64_LESS(y, x);                 // Should pass
    XASSERT_UINT64_LESS_EQUAL(y, x);           // Should pass
    XASSERT_UINT64_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_hex) {
    int hex_value1 = 0x42;
    int hex_value2 = 0x20;

    // Test cases
    XASSERT_HEX_EQUAL(hex_value1, 0x42);                // Should pass
    XASSERT_HEX_EQUAL(hex_value2, 0x20);                // Should pass
    XASSERT_HEX_NOT_EQUAL(hex_value1, hex_value2);      // Should pass
    XASSERT_HEX_LESS(hex_value2, hex_value1);           // Should pass
    XASSERT_HEX_LESS_EQUAL(hex_value2, hex_value1);     // Should pass
    XASSERT_HEX_GREATER(hex_value1, hex_value2);        // Should pass
} // end case

XTEST_CASE(xassert_run_of_hex8) {
    // Test cases for 8-bit hexadecimal
    uint8_t hex8_value1 = 0x42;
    uint8_t hex8_value2 = 0x20;
    XASSERT_HEX8_EQUAL(hex8_value1, 0x42);                // Should pass
    XASSERT_HEX8_EQUAL(hex8_value2, 0x20);                // Should pass
    XASSERT_HEX8_NOT_EQUAL(hex8_value1, hex8_value2);      // Should pass
    XASSERT_HEX8_LESS(hex8_value2, hex8_value1);           // Should pass
    XASSERT_HEX8_LESS_EQUAL(hex8_value2, hex8_value1);     // Should pass
    XASSERT_HEX8_GREATER(hex8_value1, hex8_value2);        // Should pass
} // end case

XTEST_CASE(xassert_run_of_hex16) {
    // Test cases for 16-bit hexadecimal
    uint16_t hex16_value1 = 0xABCD;
    uint16_t hex16_value2 = 0x1234;
    XASSERT_HEX16_EQUAL(hex16_value1, 0xABCD);                // Should pass
    XASSERT_HEX16_EQUAL(hex16_value2, 0x1234);                // Should pass
    XASSERT_HEX16_NOT_EQUAL(hex16_value1, hex16_value2);      // Should pass
    XASSERT_HEX16_LESS(hex16_value2, hex16_value1);           // Should pass
    XASSERT_HEX16_LESS_EQUAL(hex16_value2, hex16_value1);     // Should pass
    XASSERT_HEX16_GREATER(hex16_value1, hex16_value2);        // Should pass
} // end case

XTEST_CASE(xassert_run_of_hex32) {
    uint32_t hex32_value1 = 0x12345678;
    uint32_t hex32_value2 = 0x87654321;
    XASSERT_HEX32_EQUAL(hex32_value1, 0x12345678);                // Should pass
    XASSERT_HEX32_EQUAL(hex32_value2, 0x87654321);                // Should pass
    XASSERT_HEX32_NOT_EQUAL(hex32_value1, hex32_value2);          // Should pass
    XASSERT_HEX32_LESS(hex32_value1, hex32_value2);               // Should pass
    XASSERT_HEX32_LESS_EQUAL(hex32_value1, hex32_value2);         // Should pass
    XASSERT_HEX32_GREATER(hex32_value2, hex32_value1);            // Should pass
} // end case

XTEST_CASE(xassert_run_of_hex64) {
    // Test cases for 64-bit hexadecimal
    uint64_t hex64_value1 = 0x0123456789ABCDEF;
    uint64_t hex64_value2 = 0xFEDCBA9876543210;
    XASSERT_HEX64_EQUAL(hex64_value1, 0x0123456789ABCDEF);                // Should pass
    XASSERT_HEX64_EQUAL(hex64_value2, 0xFEDCBA9876543210);                // Should pass
    XASSERT_HEX64_NOT_EQUAL(hex64_value1, hex64_value2);                  // Should pass
    XASSERT_HEX64_LESS(hex64_value1, hex64_value2);                      // Should pass
    XASSERT_HEX64_LESS_EQUAL(hex64_value1, hex64_value2);                // Should pass
    XASSERT_HEX64_GREATER(hex64_value2, hex64_value1);                   // Should pass
} // end case

XTEST_CASE(xassert_run_of_bit) {
    // Test cases for bitwise operations
    int value1 = 0b11011011;  // Binary literal
    int value2 = 0b10101010;  // Binary literal
    int bitIndex = 3;

    // Bitwise equality checks
    XASSERT_BIT_EQUAL(value1, value1);        // Should pass
    XASSERT_BIT_EQUAL(value2, value2);        // Should pass

    // Bitwise inequality checks
    XASSERT_BIT_NOT_EQUAL(value1, value2);    // Should pass

    // Bitwise less-than checks
    XASSERT_BIT_LESS(value2, value1);         // Should pass

    // Bitwise greater-than checks
    XASSERT_BIT_GREATER(value1, value2);      // Should pass

    // Bitwise less-than-or-equal checks
    XASSERT_BIT_LESS_EQUAL(value2, value1);   // Should pass
    XASSERT_BIT_LESS_EQUAL(value1, value1);   // Should pass

    // Bitwise greater-than-or-equal checks
    XASSERT_BIT_GREATER_EQUAL(value1, value2);// Should pass
    XASSERT_BIT_GREATER_EQUAL(value1, value1);// Should pass

    // Bit is not high checks
    // XASSERT_BIT_NOT_HIGH(value1, bitIndex);   // Should pass

    // Bit is high checks
    XASSERT_BIT_HIGH(value2, bitIndex);       // Should pass

    // Bit is not low checks
    XASSERT_BIT_NOT_LOW(value1, bitIndex);    // Should pass

    // Bit is low checks
    // XASSERT_BIT_LOW(value2, bitIndex);        // Should pass
} // end case

XTEST_CASE(xassert_run_of_bits) {
    // Test cases for bitwise operations
    int value1 = 0b101010; // Binary literal
    int value2 = 0b110011; // Binary literal
    int mask = 0b111111;  // Binary literal

    XASSERT_BITS_NOT_HIGH(value1, mask);                      // Should pass
    // XASSERT_BITS_LOW(value2, mask);                           // Should pass
    XASSERT_BITS_NOT_EQUAL(value1, value2, mask);              // Should pass
    // XASSERT_BITS_LESS(value2, value1, mask);                   // Should pass
    XASSERT_BITS_GREATER(value2, value1, mask);                // Should pass
    // XASSERT_BITS_LESS_EQUAL(value2, value1, mask);             // Should pass
    XASSERT_BITS_GREATER_EQUAL(value2, value1, mask);          // Should pass
} // end case

XTEST_CASE(xassert_run_of_oct) {
    // Test cases for octal values
    int oct_value1 = 01234;  // Octal literal
    int oct_value2 = 04567;  // Octal literal
    XASSERT_OCT_EQUAL(oct_value1, 01234);                // Should pass
    XASSERT_OCT_EQUAL(oct_value2, 04567);                // Should pass
    XASSERT_OCT_NOT_EQUAL(oct_value1, oct_value2);        // Should pass
    XASSERT_OCT_LESS(oct_value1, oct_value2);            // Should pass
    XASSERT_OCT_LESS_EQUAL(oct_value1, oct_value2);      // Should pass
    XASSERT_OCT_GREATER(oct_value2, oct_value1);         // Should pass
} // end case



XTEST_CASE(xassert_run_of_float) {
    // Test cases for floating-point assertions
    double value1 = 3.14;
    double value2 = 2.71;
    double epsilon = 0.01;

    // Floating-point equality checks
    XASSERT_FLOAT_EQUAL(value1, value1, epsilon);        // Should pass
    XASSERT_FLOAT_EQUAL(value2, value2, epsilon);        // Should pass

    // Floating-point inequality checks
    // XASSERT_FLOAT_NOT_EQUAL(value1, value2, epsilon);    // Should pass

    // Floating-point less-than checks
    XASSERT_FLOAT_LESS(value2, value1);                  // Should pass

    // Floating-point greater-than checks
    XASSERT_FLOAT_GREATER(value1, value2);               // Should pass

    // Floating-point less-than-or-equal checks
    XASSERT_FLOAT_LESS_EQUAL(value2, value1);            // Should pass
    XASSERT_FLOAT_LESS_EQUAL(value1, value1);            // Should pass

    // Floating-point greater-than-or-equal checks
    XASSERT_FLOAT_GREATER_EQUAL(value1, value2);         // Should pass
    XASSERT_FLOAT_GREATER_EQUAL(value1, value1);         // Should pass
} // end case

XTEST_CASE(xassert_run_of_float_only) {
    // Test cases for floating-point special values
    double inf = 1.0 / 0.0;
    double neg_inf = -1.0 / 0.0;
    double nan = 0.0 / 0.0;

    // Test cases for positive infinity
    XASSERT_FLOAT_IS_INF(inf);                   // Should pass

    // Test cases for negative infinity
    XASSERT_FLOAT_IS_NEG_INF(neg_inf);           // Should pass

    // Test cases for NaN
    XASSERT_FLOAT_IS_NAN(nan);                   // Should pass

    // Test cases for finite values
    double finite_value = 42.0;
    XASSERT_FLOAT_IS_NOT_INF(finite_value);      // Should pass
    XASSERT_FLOAT_IS_FINITE(finite_value);       // Should pass
    XASSERT_FLOAT_IS_NOT_NAN(finite_value);      // Should pass
} // end case


XTEST_CASE(xassert_run_of_double) {
    // Test cases for double-precision values
    double epsilon = 1e-6;

    double value1 = 42.0;
    double value2 = 42.0 + epsilon / 2.0;
    double value3 = 42.0 - epsilon * 2.0;

    // Test cases for equality within epsilon
    XASSERT_DOUBLE_EQUAL(value1, value2, epsilon);  // Should pass
    
    // Test cases for inequality within epsilon
    // XASSERT_DOUBLE_NOT_EQUAL(value1, value3, epsilon);  // Should pass

    // Test cases for less than
    XASSERT_DOUBLE_LESS(value3, value1);  // Should pass
    
    // Test cases for greater than
    XASSERT_DOUBLE_GREATER(value2, value1);  // Should pass
    
    // Test cases for greater than or equal
    XASSERT_DOUBLE_GREATER_EQUAL(value1, value1);  // Should pass
    XASSERT_DOUBLE_GREATER_EQUAL(value2, value1);  // Should pass
    
    // Test cases for less than or equal
    XASSERT_DOUBLE_LESS_EQUAL(value1, value1);  // Should pass
    XASSERT_DOUBLE_LESS_EQUAL(value1, value2);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_double_only) {
    double inf = 1.0 / 0.0;
    double neg_inf = -1.0 / 0.0;
    double finite = 42.0;
    double nan = 0.0 / 0.0;

    // Test cases for double-precision value properties
    XASSERT_DOUBLE_IS_NOT_INF(finite);  // Should pass
    XASSERT_DOUBLE_IS_INF(inf);         // Should pass
    XASSERT_DOUBLE_IS_NOT_NEG_INF(finite);  // Should pass
    XASSERT_DOUBLE_IS_NEG_INF(neg_inf);  // Should pass
    XASSERT_DOUBLE_IS_NOT_NAN(finite);   // Should pass
    XASSERT_DOUBLE_IS_NAN(nan);          // Should pass
} // end case

XTEST_CASE(xassert_run_of_nullptr) {
    int* valid_ptr = NULL;
    int* invalid_ptr = (int*)0x12345678;

    // Test cases for pointer properties
    XASSERT_PTR_NULL(valid_ptr);  // Should pass
    XASSERT_PTR_EMPTY(valid_ptr);  // Should pass
    XASSERT_PTR_NOT_NULL(invalid_ptr);  // Should pass
    XASSERT_PTR_INVALID(invalid_ptr);  // Should pass
    XASSERT_PTR_NOT_EMPTY(invalid_ptr);  // Should pass
    XASSERT_PTR_INVALID_MEMORY_ACCESS(invalid_ptr);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_pointer) {
    int arr[5] = {1, 2, 3, 4, 5};
    int* valid_ptr = arr;
    int* invalid_ptr = (int*)0x12345678;

    // Test cases for pointer properties
    XASSERT_PTR_ARRAY_BOUNDS(valid_ptr, 2, 5);  // Should pass
    XASSERT_PTR_EQUAL(valid_ptr, arr);  // Should pass
    XASSERT_PTR_NOT_EQUAL(valid_ptr, invalid_ptr);  // Should pass
    // XASSERT_PTR_GREATER(valid_ptr, invalid_ptr);  // Should pass
    XASSERT_PTR_GREATER_EQUAL(valid_ptr, valid_ptr);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_string) {
    const char* str1 = "Hello";
    const char* str2 = "World";
    const char* str3 = "Hello";

    // Test cases for string comparisons and length
    XASSERT_STRING_EQUAL(str1, "Hello");  // Should pass
    XASSERT_STRING_NOT_EQUAL(str1, str2);  // Should pass
    XASSERT_STRING_EQUAL(str1, str3);  // Should pass
    
    XASSERT_STRING_LENGTH(str1, 5);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_char) {
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'A';
    char ch4 = 'Z';

    // Test cases for character comparisons
    XASSERT_CHAR_EQUAL(ch1, 'A');  // Should pass
    XASSERT_CHAR_NOT_EQUAL(ch1, ch2);  // Should pass
    XASSERT_CHAR_EQUAL(ch1, ch3);  // Should pass
    XASSERT_CHAR_NOT_EQUAL(ch1, ch4);  // Should fail (characters are equal)

    XASSERT_CHAR_LESS(ch1, ch2);  // Should pass
    XASSERT_CHAR_GREATER(ch2, ch1);  // Should pass
    XASSERT_CHAR_LESS_EQUAL(ch1, ch3);  // Should pass
    XASSERT_CHAR_GREATER_EQUAL(ch4, ch1);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_wchar) {
    wchar_t wchar1 = L'A';
    wchar_t wchar2 = L'B';
    wchar_t wchar3 = L'A';
    wchar_t wchar4 = L'Z';

    // Test cases for wide character comparisons
    XASSERT_WCHAR_EQUAL(wchar1, L'A');  // Should pass
    XASSERT_WCHAR_NOT_EQUAL(wchar1, wchar2);  // Should pass
    XASSERT_WCHAR_EQUAL(wchar1, wchar3);  // Should pass
    XASSERT_WCHAR_NOT_EQUAL(wchar1, wchar4);  // Should fail (wide characters are equal)

    XASSERT_WCHAR_LESS(wchar1, wchar2);  // Should pass
    XASSERT_WCHAR_GREATER(wchar2, wchar1);  // Should pass
    XASSERT_WCHAR_LESS_EQUAL(wchar1, wchar3);  // Should pass
    XASSERT_WCHAR_GREATER_EQUAL(wchar4, wchar1);  // Should pass
} // end case


XTEST_CASE(xassert_run_of_boolean) {
    int value1 = 5;
    int value2 = 10;

    // Test cases for boolean assertion macros
    XASSERT_BOOL_EQUAL(value1 == value2, 0);     // Should pass (0 == 0)
    XASSERT_BOOL_NOT_EQUAL(value1 == value2, 1); // Should pass (0 != 1)
    XASSERT_BOOL_LESS(value1, value2);           // Should pass (5 < 10)
    XASSERT_BOOL_GREATER(value2, value1);        // Should pass (10 > 5)
    XASSERT_BOOL_UNLESS(value1 < value2);        // Should pass (false condition)
    XASSERT_BOOL_TRUE(value1 == value1);         // Should pass (true condition)
    XASSERT_BOOL_FALSE(value1 > value2);         // Should pass (false condition)
    XASSERT_BOOL_MSG(value1 > value2, "Value1 should be greater than Value2"); // Should pass with a custom message
} // end case


XTEST_CASE(xassert_run_of_within_int) {
    // Test cases for integer comparisons within tolerance
    int int1 = 10;
    int int2 = 12;
    int int3 = 10;
    int int4 = 20;

    XASSERT_INT_WITHIN(int1, 10, 1);  // Should pass
    XASSERT_INT8_WITHIN(int2, 12, 2);  // Should pass
    XASSERT_INT16_WITHIN(int3, 10, 1);  // Should pass
    XASSERT_INT32_WITHIN(int4, 20, 5);  // Should pass
    XASSERT_INT64_WITHIN(int1, 10, 0);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_uint) {
    // Test cases for unsigned integer comparisons within tolerance
    unsigned int uint1 = 10;
    unsigned int uint2 = 12;
    unsigned int uint3 = 10;
    unsigned int uint4 = 20;

    XASSERT_UINT_WITHIN(uint1, 10, 1);  // Should pass
    XASSERT_UINT8_WITHIN(uint2, 12, 2);  // Should pass
    XASSERT_UINT16_WITHIN(uint3, 10, 1);  // Should pass
    XASSERT_UINT32_WITHIN(uint4, 20, 5);  // Should pass
    XASSERT_UINT64_WITHIN(uint1, 10, 0);  // Should pass
} // end case


XTEST_CASE(xassert_run_of_within_hex) {
    // Test cases for hexadecimal comparisons within tolerance
    unsigned int hex1 = 0x10;
    unsigned int hex2 = 0x20;
    unsigned int hex3 = 0x10;
    unsigned int hex4 = 0x30;

    XASSERT_HEX_WITHIN(hex1, 0x10, 0x1);   // Should pass
    XASSERT_HEX8_WITHIN(hex2, 0x20, 0x2);  // Should pass
    XASSERT_HEX16_WITHIN(hex3, 0x10, 0x1); // Should pass
    XASSERT_HEX32_WITHIN(hex4, 0x30, 0x5); // Should pass
    XASSERT_HEX64_WITHIN(hex1, 0x10, 0x0);  // Should pass

} // end case

XTEST_CASE(xassert_run_of_within_oct) {
    // Test cases for octal comparisons within tolerance
    int oct1 = 012;
    int oct2 = 075;

    XASSERT_OCT_WITHIN(oct1, 012, 02);       // Should pass
    XASSERT_OCT_WITHIN(oct2, 075, 04);       // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_bit) {
    // Test cases for binary comparisons within tolerance
    int bin1 = 0b110;
    int bin2 = 0b1010;

    XASSERT_BIN_WITHIN(bin1, 0b110, 0b10);   // Should pass
    XASSERT_BIN_WITHIN(bin2, 0b1010, 0b100); // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_float) {
    // Test cases for float and double comparisons within tolerance
    float float1 = 1.23;
    float float2 = 4.56;

    XASSERT_FLOAT_WITHIN(float1, 1.23, 0.01);   // Should pass
    XASSERT_FLOAT_WITHIN(float2, 4.56, 0.1);    // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_double) {
    // Test cases for float and double comparisons within tolerance
    double double1 = 1.234567;
    double double2 = 4.567890;

    XASSERT_DOUBLE_WITHIN(double1, 1.234567, 0.0001);  // Should pass
    XASSERT_DOUBLE_WITHIN(double2, 4.567890, 0.001);  // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_wchar) {
    // Test cases for char and wchar_t comparisons within range
    wchar_t wchar1 = L'0';
    wchar_t wchar2 = L'9';

    XASSERT_WCHAR_WITHIN(wchar1, L'0', L'9'); // Should pass
    XASSERT_WCHAR_WITHIN(wchar2, L'0', L'9'); // Should pass
} // end case

XTEST_CASE(xassert_run_of_within_char) {
    // Test cases for char and wchar_t comparisons within range
    char char1 = 'A';
    char char2 = 'Z';

    XASSERT_CHAR_WITHIN(char1, 'A', 'Z');     // Should pass
    XASSERT_CHAR_WITHIN(char2, 'A', 'Z');     // Should pass
} // end case

XTEST_CASE(xassert_run_of_files) {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        XTEST_IGNORE("File not found in test directory");
    } // end if

    char buffer[1024];
    size_t size = sizeof(buffer);

    // Test cases for file-related assertions
    XASSERT_FILE_OPEN(file);              // Should pass
    XASSERT_FILE_READ(file, buffer, size); // Should pass (assuming the file has enough data)
    XASSERT_FILE_SEEK(file, 0, SEEK_SET);  // Should pass
    XASSERT_FILE_TELL(file);              // Should pass
    XASSERT_FILE_EOF(file);               // Should pass (assuming not at the end of the file)

    fclose(file);
} // end case

XTEST_CASE(xassert_run_of_arrays) {
    // Test cases for array-related assertions
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index1 = 2;

    XASSERT_ARRAY_INVALID_SIZE(size);                    // Should pass
    XASSERT_ARRAY_INDEX_OUT_OF_BOUNDS(index1, size);     // Should pass
    XASSERT_ARRAY_NULL_POINTER(arr);                     // Should pass
    XASSERT_ARRAY_INVALID_OPERATION(size > 0);           // Should pass
} // end case


//
// LOCAL TEST GROUP
//
void xassert_test_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(xassert_run_of_int, runner);
    XTEST_RUN_UNIT(xassert_run_of_int8, runner);
    XTEST_RUN_UNIT(xassert_run_of_int16, runner);
    XTEST_RUN_UNIT(xassert_run_of_int32, runner);
    XTEST_RUN_UNIT(xassert_run_of_int64, runner);
    XTEST_RUN_UNIT(xassert_run_of_uint, runner);
    XTEST_RUN_UNIT(xassert_run_of_uint8, runner);
    XTEST_RUN_UNIT(xassert_run_of_uint16, runner);
    XTEST_RUN_UNIT(xassert_run_of_uint32, runner);
    XTEST_RUN_UNIT(xassert_run_of_uint64, runner);
    XTEST_RUN_UNIT(xassert_run_of_hex, runner);
    XTEST_RUN_UNIT(xassert_run_of_hex8, runner);
    XTEST_RUN_UNIT(xassert_run_of_hex16, runner);
    XTEST_RUN_UNIT(xassert_run_of_hex32, runner);
    XTEST_RUN_UNIT(xassert_run_of_hex64, runner);

    XTEST_RUN_UNIT(xassert_run_of_bit, runner);
    XTEST_RUN_UNIT(xassert_run_of_bits, runner);
    XTEST_RUN_UNIT(xassert_run_of_oct, runner);
    XTEST_RUN_UNIT(xassert_run_of_float, runner);
    XTEST_RUN_UNIT(xassert_run_of_float_only, runner);
    XTEST_RUN_UNIT(xassert_run_of_double, runner);
    XTEST_RUN_UNIT(xassert_run_of_double_only, runner);
    XTEST_RUN_UNIT(xassert_run_of_nullptr, runner);
    XTEST_RUN_UNIT(xassert_run_of_pointer, runner);

    XTEST_RUN_UNIT(xassert_run_of_char, runner);
    XTEST_RUN_UNIT(xassert_run_of_wchar, runner);
    XTEST_RUN_UNIT(xassert_run_of_string, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_int, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_uint, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_hex, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_oct, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_bit, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_float, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_double, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_wchar, runner);
    XTEST_RUN_UNIT(xassert_run_of_within_char, runner);

    XTEST_RUN_UNIT(xassert_run_of_boolean, runner);
    XTEST_RUN_UNIT(xassert_run_of_files, runner);
    XTEST_RUN_UNIT(xassert_run_of_arrays, runner);
} // end of group
