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
#include "fossil/xtest.h"
#include <stdarg.h>

typedef struct {
    bool cutback;
    bool verbose;
    bool dry_run;
    bool only_test;
    bool only_fish;
    bool only_mark;
    bool debug;
    bool color;
    bool ci;
    bool repeat;
    uint8_t iter_repeat;
} xparser;

// Global xparser variable
xparser xcli;

static uint8_t ASSUME_MAX    = 5;
static uint8_t ASSUME_ISSUES = 0;

// Static control panel for assert/expect and marks
static uint8_t XTEST_PASS_SCAN = true;
static uint8_t XIGNORE_TEST_CASE = false;
static uint8_t XERRORS_TEST_CASE = false;

static uint8_t MAX_REPEATS = 100;
static uint8_t MIN_REPEATS = 1;


//
// local types
//
typedef char *xstring;
static uint64_t start_time;
#if defined(_WIN32)
static double frequency; // Variable to store the frequency for Windows
#endif

// ==============================================================================
// Xtest internal console stream logic
// ==============================================================================

// to make strdup work on multable platforms and be C23, C18 compatabliity
// a custom strdup has been written to soul purpose of using strdup.
static char *xstrdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    size_t len = strlen(str) + 1;
    char *copy = (char *)malloc(len);
    if (copy != NULL) {
        memcpy(copy, str, len);
    }
    return copy;
}


static char *replace_underscore(char *str) {
    char *result = xstrdup(str);
    char *ptr = result;

    while (*ptr) {
        if (*ptr == '_') {
            *ptr = ' ';
        }
        ptr++;
    }
    return result;
}

// printf has its use cases but to handle multable general purpose features without
// forgetting to change a printf this would servse as the internal prinf with color
// and potintal for additnal output releated functionality.
static void xconsole_out(const char *color_name, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    if (xcli.color) {
        char *color_code = "";
        
        if (strcmp(color_name, "red") == 0) {
            color_code = "\033[1;31m";
        } else if (strcmp(color_name, "green") == 0) {
            color_code = "\033[1;32m";
        } else if (strcmp(color_name, "blue") == 0) {
            color_code = "\033[1;34m";
        } else if (strcmp(color_name, "orange") == 0) {
            color_code = "\033[1;33m";
        } else if (strcmp(color_name, "yellow") == 0) {
            color_code = "\033[1;33m";
        } else if (strcmp(color_name, "purple") == 0) {
            color_code = "\033[1;35m";
        } else if (strcmp(color_name, "magenta") == 0) {
            color_code = "\033[0;35m";
        } else if (strcmp(color_name, "cyan") == 0) {
            color_code = "\033[0;36m";
        }

        printf("%s", color_code);
        vprintf(format, args);
        printf("\033[0m"); // Reset color
    } else {
        vprintf(format, args);
    }

    va_end(args);
}

// Function to generate a random humorous comment about an empty test runner
// becuse way not add a little sillyness.
const char *empty_runner_comment() {
    const char *comments[] = {
        "Looks like the test runner is on a coffee break!",
        "The test runner is feeling a bit empty today, like my coffee cup.",
        "The test runner is as empty as a developer's coffee mug on Monday morning.",
        "Did someone forget to load the tests? The runner seems quite empty!",
        "The test runner is as empty as a promise to write documentation.",
        "The test runner is emptier than a developer's promise to refactor code.",
        "The test runner seems to be on a diet - it's looking quite empty!",
        "Did the tests escape? The runner seems unusually empty!",
        "The test runner is as empty as a JavaScript developer's promises.",
        "The test runner seems as empty as my enthusiasm for Monday mornings.",
        "The test runner is emptier than a meeting agenda without a clear purpose.",
        "The test runner is looking as empty as a developer's patience with legacy code.",
        "The test runner is as empty as a database without any data.",
        "The test runner seems to be in stealth mode - it's quite empty!",
        "The test runner is emptier than a startup's promise of equity.",
        "The test runner is as empty as a meeting room during a free lunch seminar.",
        "The test runner is looking as empty as a developer's snack stash on Friday afternoon.",
        "The test runner seems to be as empty as a Git repository with no commits.",
        "The test runner is emptier than a developer's memory after a long debugging session.",
        "The test runner is looking as empty as a developer's inbox after vacation.",
        "The test runner is as empty as a conference room during a fire drill."
    };

    int num_comments = sizeof(comments) / sizeof(comments[0]);

    srand(time(NULL));

    // Generate a random index
    int random_index = rand() % num_comments;

    return comments[random_index];
}

// Function to generate a random tip for unit testing released tasks
// as this would servse as a handy feature and be helpful for teaching
// new developers how they can write good test cases.
const char *helpful_tester_tip() {
    const char *tips[] = {
        "Always write meaningful test names.",
        "Test both positive and negative cases.",
        "Use mocking for external dependencies.",
        "Run tests frequently during development.",
        "Ensure tests are isolated and independent.",
        "Avoid hardcoding values in test cases.",
        "Focus on testing the functionality, not the implementation.",
        "Regularly update and maintain test cases.",
        "Use code coverage tools to identify untested code.",
        "Test edge cases and boundary conditions.",
        "Keep unit tests fast and repeatable.",
        "Use setup and teardown methods when necessary.",
        "Automate the execution of tests.",
        "Review and refactor tests regularly.",
        "Write tests for both happy paths and error paths.",
        "Test for performance and scalability where applicable.",
        "Use assertions effectively to verify outcomes.",
        "Consider using property-based testing for complex logic.",
        "Document the purpose and expected behavior of each test.",
        "Collaborate with the development team to identify test cases.",
        "Prioritize and focus on critical and high-risk areas.",
        "Write tests early in the development process.",
        "Use version control for test code and test data.",
        "Ensure that tests can run in different environments.",
        "Consider the maintainability and readability of test code."
    };

    int num_tips = sizeof(tips) / sizeof(tips[0]);

    srand(time(NULL));

    // Generate a random index
    int random_index = rand() % num_tips;

    return tips[random_index];
}


// ==============================================================================
// Output functions
// ==============================================================================

// Formats and displays information about the start/end of a test case.
static void output_end_start(xtest *test_case, xengine* engine) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "[...start...]\n");
        xconsole_out("cyan", ".\t> TITLE: - %s\n", replace_underscore(test_case->name));
        xconsole_out("cyan", ".\t> INDEX: - %.2i\n", engine->stats.total_count + 1);
        xconsole_out("cyan", ".\t> CLASS: - %s\n", (test_case->config.is_fish)? "Fish AI" : (test_case->config.is_mark)? "Benchmark" : "Test Case");
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("blue", "> name: - %s\n", replace_underscore(test_case->name));
        xconsole_out("blue", "> type: - %s\n", (test_case->config.is_fish)? "fish" : (test_case->config.is_mark)? "mark" : "test");
    }

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
} // end of func

static void output_end_test(xtest *test_case, xengine* engine) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    int64_t minutes      = (int64_t)(test_case->timer.elapsed / (60 * 1000));
    int64_t seconds      = (int64_t)((test_case->timer.elapsed - minutes * 60 * 1000) / 1000);
    int64_t millis       = (int64_t)(test_case->timer.elapsed - minutes * 60 * 1000 - seconds * 1000);
    int64_t microseconds = (int64_t)(((test_case->timer.elapsed - seconds)    * 1000) - millis * 1000);

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("cyan", ".\t> TIME: - %d minutes, %d seconds, %d milliseconds, %d microseconds\n", minutes, seconds, millis, microseconds);
        xconsole_out("cyan", ".\t> SKIP: - %s\n", test_case->config.ignored ? "yes" : "no");
        xconsole_out("blue", "[...end...]\n");
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("cyan", "> timestamp: - %d:%d:%d:%d\n", minutes, seconds, millis, microseconds);
        xconsole_out("blue", "> ignore   : - %s\n", test_case->config.ignored ? "yes" : "no");
    }

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
} // end of func

// Output for XUnit Test Case Report.
static void output_summary_format(xengine *runner) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    runner->timer.end = clock();
    // Calculate elapsed time and store it in the test case
    runner->timer.elapsed = ((double)(runner->timer.end - runner->timer.start)  / CLOCKS_PER_SEC) * 1000.0;
    int64_t minutes      = (int64_t)(runner->timer.elapsed / (60 * 1000));
    int64_t seconds      = (int64_t)((runner->timer.elapsed - minutes * 60 * 1000) / 1000);
    int64_t millis       = (int64_t)(runner->timer.elapsed - minutes * 60  * 1000 - seconds * 1000);
    int64_t microseconds = (int64_t)(((runner->timer.elapsed - seconds)    * 1000) - millis * 1000);

    xconsole_out("blue", "[Test Summary: Fossil Test] %d minutes, %d seconds, %d milliseconds, %d microseconds\n", minutes, seconds, millis, microseconds);
    xconsole_out("blue", "***************************:\n");

    xconsole_out("magenta", "> - All Passed  : - %.2i\n",    runner->stats.passed_count);
    xconsole_out("magenta", "> - All Failed  : - %.2i\n",    runner->stats.failed_count);
    xconsole_out("magenta", "> - All Skipped : - %.2i\n",    runner->stats.ignored_count);
    xconsole_out("magenta", "> - All Error   : - %.2i\n",    runner->stats.error_count);
    xconsole_out("magenta", "> - Benchmark   : - %.2i\n",    runner->stats.mark_count);
    xconsole_out("magenta", "> - Jellyfish AI: - %.2i\n",   runner->stats.fish_count);
    xconsole_out("yellow",  "> - Total Cases : - %.2i\n", runner->stats.total_count);

    xconsole_out("blue", "***************************:\n");

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
} // end of func

void output_assert_format(const char *message, const char* file, int line, const char* func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("red", " .\n\t> In File: %s .\n\t> At Line: %d .\n\t> In Function: %s\n", file, line, replace_underscore(func));
        xconsole_out("red", " .\n\t> Assertion failed: %s\n", message);
    } else if (!xcli.verbose && !xcli.cutback) {
        xconsole_out("red", "     =====     =====     =====\n");
        xconsole_out("red", "\nAssertion failed: %s\n", message);
        xconsole_out("red", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "[F]");
    }
    XTEST_PASS_SCAN = false;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_assume_format(const char *message, const char* file, int line, const char* func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("red", " .\n\t> In File: %s .\n\t> At Line: %d .\n\t> In Function: %s\n", file, line, replace_underscore(func));
        xconsole_out("red", " .\n\t> Assumtion failed: %s\n", message);
    } else if (!xcli.verbose && !xcli.cutback) {
        xconsole_out("red", "     =====     =====     =====\n");
        xconsole_out("red", "\nAssumtion failed: %s\n", message);
        xconsole_out("red", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "[F]");
    }
    ASSUME_ISSUES++;
    XTEST_PASS_SCAN = false;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_expect_format(const char *message, const char* file, int line, const char* func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("red", " .\n\t> In File: %s .\n\t> At Line: %d .\n\t> In Function: %s\n", file, line, replace_underscore(func));
        xconsole_out("red", " .\n\t> Assertion failed: %s\n", message);
    } else if (!xcli.verbose && !xcli.cutback) {
        xconsole_out("red", "     =====     =====     =====\n");
        xconsole_out("red", "\n failed: %s\n", message);
        xconsole_out("red", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "[F]");
    }
    XTEST_PASS_SCAN = false;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_xerrors_format(const char* reason, const char* file, int line, const char* func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("red", " .\n\t> File: %s .\n\t> Line: %d .\n\t> Function: %s\n", file, line, func);
        xconsole_out("red", " .\n\t> Test error: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "Test error: %s\n", reason);
        xconsole_out("red", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "[E]");
    }
    XERRORS_TEST_CASE = true;

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_xignore_format(const char* reason, const char* file, int line, const char* func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("yellow", " .\n\t> File: %s .\n\t> Line: %d .\n\t> Function: %s\n", file, line, func);
        xconsole_out("yellow", " .\n\t> Test skipped: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("yellow", "Test skipped: %s\n", reason);
        xconsole_out("yellow", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("yellow", "[S]");
    }
    XIGNORE_TEST_CASE = true;

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_benchmark_format(uint64_t elapsed, double max) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "[...benchmark...]\n");
        xconsole_out("red", ".\t> Elapsed time (%f time)\n", elapsed);
        xconsole_out("red", ".\t> Exceeds limit (%f time)\n", max);
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "benchmark failed: elapsed time (%f time) exceeds limit (%f time)\n", elapsed, max);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("red", "[F]");
    }
    XTEST_PASS_SCAN = false;

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

// ==============================================================================
// Xtest internal argument parser logic
// ==============================================================================

// Prints usage instructions, including custom options, for a command-line program.
static void xparser_print_usage(void) {
    xconsole_out("green",  "USAGE: Xcli [options]\n");
    xconsole_out("green", "Options:\n");
    xconsole_out("gray", "  -h, --help    Display this help message\n");
    xconsole_out("gray", "  -v, --version Display program version\n");
    xconsole_out("gray", "  --only-test   Run only test cases\n");
    xconsole_out("gray", "  --only-fish   Run only AI training cases\n");
    xconsole_out("gray", "  --only-mark   Run only benchmark cases\n");
    xconsole_out("gray", "  --cutback     Enable cutback mode\n");
    xconsole_out("gray", "  --verbose     Enable verbose mode\n");
    xconsole_out("gray", "  --repeat N    Repeat the test N times (requires a numeric argument)\n");
} // end of func

// Function to check if a specific option is present
static bool xparser_has_option(int argc, char *argv[], const char *option) {
    for (int32_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], option) == 0) {
            return true;
        }
    }
    return false;
}

// Original xparser_parse_args function
static void xparser_parse_args(int argc, char *argv[]) {
    xcli.cutback = false;
    xcli.verbose = false;
    xcli.dry_run = false;
    xcli.repeat  = false;
    xcli.debug = false;
    xcli.color = false;
    xcli.only_test = false;
    xcli.only_mark = false;

    for (int32_t i = 1; i < argc; i++) {
        if (xparser_has_option(argc, argv, "--dry-run")) {
            xcli.dry_run = true;
        } else if (xparser_has_option(argc, argv, "--cutback")) {
            xcli.cutback = true;
            xcli.verbose = false;
        } else if (xparser_has_option(argc, argv, "--verbose")) {
            xcli.ci = true;
        }else if (xparser_has_option(argc, argv, "--debug")) {
            xcli.debug = true;
        } else if (xparser_has_option(argc, argv, "--color")) {
            xcli.color = true;
        } else if (xparser_has_option(argc, argv, "--ci")) {
            xcli.verbose = true;
            xcli.cutback = false;
        } else if (xparser_has_option(argc, argv, "--only-test")) {
            xcli.only_test = true;
            xcli.only_fish = false;
            xcli.only_mark = false;
        } else if (xparser_has_option(argc, argv, "--only-fish")) {
            xcli.only_fish = true;
            xcli.only_mark = false;
            xcli.only_test = false;
        } else if (xparser_has_option(argc, argv, "--only-mark")) {
            xcli.only_mark = true;
            xcli.only_fish = false;
            xcli.only_test = false;
        } else if (xparser_has_option(argc, argv, "--version") || xparser_has_option(argc, argv, "-v")) {
            xconsole_out("green", "1.1.1\n");
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--help") || xparser_has_option(argc, argv, "-h")) {
            xparser_print_usage();
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--repeat")) {
            xcli.repeat = true;
            if (++i < argc) {
                int iter_repeat = atoi(argv[i]);
                if (iter_repeat >= MIN_REPEATS && iter_repeat <= MAX_REPEATS) {
                    xcli.iter_repeat = iter_repeat;
                } else {
                    xtest_console_err("Error: --repeat value must be between 1 and 100.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                xtest_console_err("Error: --repeat option requires a numeric argument.\n");
                exit(EXIT_FAILURE);
            }
        }

        // Check if the program is running in CI mode
        if (xcli.ci) {
            xcli.verbose = false;
            xcli.cutback = true;
            xcli.color = false;
            xcli.debug = false;
        }
    }
} // end of func

// ==============================================================================
// Xtest create and erase
// ==============================================================================

// Initializes an xengine and processes command-line arguments.
xengine xtest_create(int argc, char **argv) {
    xengine runner;
    xparser_parse_args(argc, argv);

    runner.stats = (xstats){0, 0, 0, 0, 0, 0, 0, 0};
    runner.timer = (xtime){0, 0, 0};

    if (xcli.dry_run) { // Check if it's a dry run
        xconsole_out("blue", "Simulating config step...\n");
    }
    runner.timer.start = clock();
    return runner;
} // end of func

// Finalizes the execution of a Trilobite XUnit runner and displays test results.
int xtest_erase(xengine *runner) {
    if (xcli.dry_run) {
        xconsole_out("blue", "Simulating test results...\n");
    } else {
        output_summary_format(runner);
    }
    return runner->stats.failed_count;
} // end of func

// ==============================================================================
// Xtest basic utility functions
// ==============================================================================

// Updates the statistics
static void xtest_update_scoreboard(xengine* engine, xtest* test_case) {
    // Check if the test should be ignored
    if (test_case->config.ignored) {
        engine->stats.ignored_count++;
        return;
    }
    if (XERRORS_TEST_CASE) {
        engine->stats.error_count++;
        return;
    }

    // Update the appropriate count based on your logic
    if (!test_case->config.is_mark && !test_case->config.is_fish) {
        engine->stats.test_count++;
    } else if (test_case->config.is_fish && !test_case->config.is_mark) {
        engine->stats.fish_count++;
    } else if (test_case->config.is_mark && !test_case->config.is_fish) {
        engine->stats.mark_count++;
    }

    // Update main score values
    if (!XTEST_PASS_SCAN) {
        engine->stats.failed_count++;
    } else {
        engine->stats.passed_count++;
    }
    engine->stats.total_count++;
} // end of func

// Core steps to run a test case
static void xtest_run(xtest* test_case, xfixture* fixture) {
    test_case->timer.start = clock();

    for (uint8_t iter = 0; iter < xcli.iter_repeat; iter++) {
        if (fixture && fixture->setup) {
            fixture->setup();
        }

        test_case->test_function();

        if (fixture && fixture->teardown) {
            fixture->teardown();
        }
    }

    test_case->timer.end = clock(); // Calculate elapsed time and store it in the test case
    test_case->timer.elapsed = ((double)(test_case->timer.end - test_case->timer.start)  / CLOCKS_PER_SEC) * 1000.0;
} // end of func

// Common functionality for running a test case.
static void xtest_run_test(xengine* engine, xtest* test_case, xfixture* fixture) {
    output_end_start(test_case, engine);

    if (!xcli.dry_run && !XIGNORE_TEST_CASE) {
        xtest_run(test_case, fixture);

    } else if (!xcli.dry_run && XIGNORE_TEST_CASE) {
        test_case->config.ignored = XIGNORE_TEST_CASE;
        XIGNORE_TEST_CASE = false;

    } else if (xcli.dry_run) {
        xconsole_out("blue", "Simulating test case...\n");
        return;
    }

    xtest_update_scoreboard(engine, test_case);
    output_end_test(test_case, engine);
} // end of func

// ==============================================================================
// Xtest essential test runner functions
// ==============================================================================

void xtest_run_as_test(xengine* engine, xtest* test_case) {
    test_case->config.ignored = false;
    xtest_run_test(engine, test_case, NULL);
} // end of func

void xtest_run_as_fixture(xengine* engine, xtest* test_case, xfixture* fixture) {
    test_case->config.ignored = false;
    xtest_run_test(engine, test_case, fixture);
} // end of func

// ==============================================================================
// Xmark functions for benchmarks
// ==============================================================================

void xmark_start_benchmark() {
#if defined(_WIN32)
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    frequency = (double)freq.QuadPart;
    QueryPerformanceCounter((LARGE_INTEGER*)&start_time);
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    start_time = ts.tv_sec * 1e9 + ts.tv_nsec;
#endif
}

uint64_t xmark_stop_benchmark() {
#if defined(_WIN32)
    LARGE_INTEGER end_time;
    QueryPerformanceCounter(&end_time);
    return (uint64_t)((end_time.QuadPart - start_time) * 1e9 / frequency);
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1e9 + ts.tv_nsec) - start_time;
#endif

void xmark_assert_seconds(uint64_t elapsed_time_ns, double max_seconds) {
    if (!XTEST_PASS_SCAN) {
        return;
    }
    double elapsed_seconds = elapsed_time_ns / 1e9;
    if (elapsed_seconds > max_seconds) {
        output_benchmark_format(elapsed_seconds, max_seconds);
    }
}

void xmark_assert_minutes(uint64_t elapsed_time_ns, double max_minutes) {
    if (!XTEST_PASS_SCAN) {
        return;
    }
    double elapsed_minutes = elapsed_time_ns / 60e9;
    if (elapsed_minutes > max_minutes) {
        output_benchmark_format(elapsed_minutes, max_minutes);
    }
}

void xmark_expect_seconds(uint64_t elapsed_time_ns, double max_seconds) {
    double elapsed_seconds = elapsed_time_ns / 1e9;
    XTEST_PASS_SCAN = true;
    if (elapsed_seconds > max_seconds) {
        output_benchmark_format(elapsed_seconds, max_seconds);
    }
}

void xmark_expect_minutes(uint64_t elapsed_time_ns, double max_minutes) {
    double elapsed_minutes = elapsed_time_ns / 60e9;
    XTEST_PASS_SCAN = true;

    if (elapsed_minutes > max_minutes) {
        output_benchmark_format(elapsed_minutes, max_minutes);
    }
}

// ==============================================================================
// Xtest functions for asserts
// ==============================================================================

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xignore(const char* reason, const char* file, int line, const char* func) {
    output_xignore_format(reason, file, line, func);
} // end of func

// Marks a test case as error with a specified reason and prints it to stderr.
void xerrors(const char* reason, const char* file, int line, const char* func) {
    output_xerror_format(reason, file, line, func);
} // end of func


// Custom assumptions function with optional message.
void xassume(bool expression, const char *message, const char* file, int line, const char* func) {
    if (ASSUME_ISSUES == ASSUME_MAX) {
        return;
    }
    if (!expression) {
        output_assume_format(message, file, line, func);
    }
} // end of func

// Custom assertion function with optional message.
void xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!XTEST_PASS_SCAN) {
        return;
    }
    if (!expression) {
        output_assert_format(message, file, line, func);
    }
} // end of func

// Custom expectation function with optional message.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!expression) {
        output_expect_format(message, file, line, func);
    }
} // end of func
