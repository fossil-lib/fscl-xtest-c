/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xassume.h"



// Assertion operation
cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right) {
    // Check if the assertion operation is valid
    if (op < CDNA_OPT_EQUAL || op > CDNA_OPT_GREATER_THAN_OR_EQUAL) {
        return CDNA_ASSERT_INVALID_OPERATION;
    }

    // Compare the values based on the assertion operation and type check
    bool result = compare_values(op, left, right);

    // Return the appropriate assertion result
    return result ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
}

// Specific assertion functions
cdna_assert_error assume_not_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_NOT_EQUAL, left, right);
}

cdna_assert_error assume_its_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_EQUAL, left, right);
}

cdna_assert_error assume_its_less(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_LESS_THAN, left, right);
}

cdna_assert_error assume_its_more(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_GREATER_THAN, left, right);
}

cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_LESS_THAN_OR_EQUAL, left, right);
}

cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_GREATER_THAN_OR_EQUAL, left, right);
}
