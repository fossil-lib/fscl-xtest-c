/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xtest.h"
#include "trilobite/xerrors.h"

//
// TEST FIXTURE
//
XTEST_FIXTURE(xerrors_test_fixture);

XTEST_SETUP(xerrors_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xerrors_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_file_no_msg) {
    FILE *file = fopen("example.txt", "r");
    char buffer[100];
    const char *data = "This is some data.";
    int size = sizeof(buffer);

    // Use the file-related error macros without a custom message
    XERRORS_FILE_OPEN(file); // Should fail if the file doesn't exist
    XERRORS_FILE_READ(file); // Should fail if unable to read
    XERRORS_FILE_SEEK(file, 0, SEEK_SET); // Should fail if seeking fails
    XERRORS_FILE_WRITE(file); // Should fail if unable to write
    XERRORS_FILE_TELL(file); // Should fail if getting file position fails
    XERRORS_FILE_CLOSE(file); // Should fail if unable to close file
    XERRORS_FILE_EOF(file); // Should fail if end of file is reached
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_file_with_msg) {
    FILE *file = fopen("example.txt", "r");
    char buffer[100];
    const char *data = "This is some data.";
    int size = sizeof(buffer);

    // Use the file-related error macros with custom messages
    XERRORS_FILE_OPEN_MSG(file, "Failed to open file"); // Should fail if the file doesn't exist
    XERRORS_FILE_READ_MSG(file, "Failed to read from file"); // Should fail if unable to read
    XERRORS_FILE_SEEK_MSG(file, 0, SEEK_SET, "Failed to seek within file"); // Should fail if seeking fails
    XERRORS_FILE_WRITE_MSG(file, "Failed to write to file"); // Should fail if unable to write
    XERRORS_FILE_TELL_MSG(file, "Failed to get file position"); // Should fail if getting file position fails
    XERRORS_FILE_CLOSE_MSG(file, "Failed to close file"); // Should fail if unable to close file
    XERRORS_FILE_EOF_MSG(file, "End of file (EOF) reached"); // Should fail if end of file is reached
} // end case

//
// LOCAL TEST GROUP
//
void xerrors_test_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xerrors_file_no_msg,           &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_file_with_msg,           &xerrors_test_fixture, &runner->stats);
} // end of group
