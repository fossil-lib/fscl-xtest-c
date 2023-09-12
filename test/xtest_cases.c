/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"

//
// XUNIT TEST CASES
//
XTEST_CASE(xbdd_logic_test) {
    GIVEN("a valid statement is passed") {
        // Set up the context
        bool givenExecuted = true;

        WHEN("a statement is true") {
            // Perform the login action
            bool whenExecuted = true;
            
            THEN("we validate everything was worked") {
                // Check the expected outcome
                bool thenExecuted = true;

                XEXPECT_BOOL_TRUE(givenExecuted);
                XEXPECT_BOOL_TRUE(whenExecuted);
                XEXPECT_BOOL_TRUE(thenExecuted);
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_user_account) {
    GIVEN("a user's account with sufficient balance") {
        // Set up the context
        float accountBalance = 500.0;
        float withdrawalAmount = 200.0;

        WHEN("the user requests a withdrawal of $200") {
            // Perform the withdrawal action
            if (accountBalance >= withdrawalAmount) {
                accountBalance -= withdrawalAmount;
            } // end if
            THEN("the withdrawal amount should be deducted from the account balance") {
                // Check the expected outcome

                // Simulate the scenario
                float compareBalance = 500.0;
                XEXPECT_FLOAT_LESS(accountBalance, compareBalance);
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_empty_cart) {
    GIVEN("a user with an empty shopping cart") {
        // Set up the context
        int cartItemCount = 0;

        WHEN("the user adds a product to the cart") {
            // Perform the action of adding a product

            THEN("the cart item count should increase by 1") {
                // Check the expected outcome
                cartItemCount++;

                XEXPECT_INT_EQUAL(cartItemCount, 1);
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_valid_login) {
    GIVEN("a registered user with valid credentials") {
        // Set up the context
        const char* validUsername = "user123";
        const char* validPassword = "pass456";

        WHEN("the user provides correct username and password") {
            // Perform the action of user login
            const char* inputUsername = "user123";
            const char* inputPassword = "pass456";

            THEN("the login should be successful") {
                // Check the expected outcome
                // Simulate login validation
                XEXPECT_STRING_EQUAL(inputUsername, validUsername);
                XEXPECT_STRING_EQUAL(inputPassword, validPassword);
            }
        }

        WHEN("the user provides incorrect password") {
            // Perform the action of user login
            const char* inputUsername = "user123";
            const char* inputPassword = "wrongpass";

            THEN("the login should fail with an error message") {
                // Check the expected outcome
                // Simulate login validation
                XEXPECT_STRING_EQUAL(inputUsername, validUsername);
                XEXPECT_STRING_NOT_EQUAL(inputPassword, validPassword);
            }
        }
    }
} // end of case

//
// LOCAL TEST GROUP
//
void unit_test_c_group(XUnitRunner *runner) {    
    xtest_run_test_unit(&xbdd_logic_test, &runner->stats);
    xtest_run_test_unit(&xbdd_user_account, &runner->stats);
    xtest_run_test_unit(&xbdd_empty_cart, &runner->stats);
    xtest_run_test_unit(&xbdd_valid_login, &runner->stats);
} // end of group
