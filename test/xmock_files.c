/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

XTEST_DATA(MockFiles) {
    XMockFile *file;
} dir;

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_file_fixture);

XTEST_SETUP(xmockup_file_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xmockup_file_fixture) {
    xmock_io_fclose(dir.file);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fopen_nonexistent_file) {
    dir.file = xmock_io_fopen("nonexistent.txt", "r");
    XASSERT_PTR_NULL(dir.file);
}

// Test reading data from an empty file
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fread_empty_file) {
    dir.file = xmock_io_fopen("empty.txt", "r");
    XASSERT_PTR_NOT_NULL(dir.file);

    char buffer[100];
    size_t bytesRead = xmock_io_fread(buffer, 1, sizeof(buffer), dir.file);
    XASSERT_INT_EQUAL(0, bytesRead);
}

// Test seeking to a specific position within the file
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fseek_tests) {
    dir.file = xmock_io_fopen("test.txt", "r");
    XASSERT_PTR_NOT_NULL(dir.file);

    char buffer[100];
    size_t bytesRead = xmock_io_fread(buffer, 1, 10, dir.file);
    XASSERT_INT_EQUAL(10, bytesRead);

    xmock_io_fseek(dir.file, 20, SEEK_SET);

    bytesRead = xmock_io_fread(buffer, 1, 10, dir.file);
    XASSERT_INT_EQUAL(10, bytesRead);
}

// Test reading a file larger than the buffer size
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fread_large_file) {
    dir.file = xmock_io_fopen("large.txt", "r");
    XASSERT_PTR_NOT_NULL(dir.file);

    char buffer[100];
    size_t totalBytesRead = 0;
    size_t bytesRead;

    while ((bytesRead = xmock_io_fread(buffer, 1, sizeof(buffer), dir.file)) > 0) {
        totalBytesRead += bytesRead;
    } // end while

    XASSERT_BOOL_UNLESS(totalBytesRead > sizeof(buffer));
}

// Test reading a specific number of bytes
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fread_specific_bytes) {
    dir.file = xmock_io_fopen("test.txt", "r");
    XASSERT_PTR_NOT_NULL(dir.file);

    char buffer[50]; // Read 50 bytes
    size_t bytesRead = xmock_io_fread(buffer, 1, sizeof(buffer), dir.file);
    XASSERT_INT_EQUAL(sizeof(buffer), bytesRead);
}

// Test reading the entire file
XTEST_CASE_FIXTURE(xmockup_file_fixture, xmock_io_fread_entire_file) {
    dir.file = xmock_io_fopen("test.txt", "r");
    XASSERT_PTR_NOT_NULL(dir.file);

    char buffer[100]; // Assuming the file is smaller than this buffer
    size_t bytesRead = xmock_io_fread(buffer, 1, sizeof(buffer), dir.file);
    XASSERT_BOOL_UNLESS(bytesRead > 0);

    // Verify that the entire file has been read
    XASSERT_INT_EQUAL(bytesRead, dir.file->size);
}

//
// XTEST FIXTURE
//
void xmockup_file_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xmock_io_fopen_nonexistent_file, &xmockup_file_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_io_fread_empty_file, &xmockup_file_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_io_fseek_tests, &xmockup_file_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_io_fread_entire_file, &xmockup_file_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_io_fread_large_file, &xmockup_file_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_io_fread_specific_bytes, &xmockup_file_fixture, &runner->stats);
} // end of fixture
