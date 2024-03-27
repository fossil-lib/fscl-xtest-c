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
    xbool cutback;
    xbool verbose;
    xbool dry_run;
    xbool only_test;
    xbool only_fish;
    xbool only_mark;
    xbool debug;
    xbool color;
    xbool shuffle;
    xbool reverse;
    xbool ci;
    xbool repeat;
    uint8_t iter_repeat;
} xparser;

// Global xparser variable
xparser xcli;

static uint8_t ASSUME_MAX    = 5;
static uint8_t ASSUME_ISSUES = 0;

// Static control panel for assert/expect and marks
static uint8_t XTEST_PASS_SCAN = xtrue;
static uint8_t XIGNORE_TEST_CASE = xfalse;
static uint8_t XERRORS_TEST_CASE = xfalse;

static uint8_t MAX_REPEATS = 100;
static uint8_t MIN_REPEATS = 1;

// Running tests in a queue
void xtest_run_queue(xengine* engine);

//
// local types
//
static uint64_t start_time;

#if defined(_WIN32)
static double frequency; // Variable to store the frequency for Windows
#endif

// ==============================================================================
// Xtest internal console stream logic
// ==============================================================================

// to make strdup work on multable platforms and be C23, C18 compatabliity
// a custom strdup has been written to soul purpose of using strdup.
static xstring xstrdup(const xstring str) {
    if (str == xnullptr) {
        return xnullptr;
    }
    size_t len = strlen(str) + 1;
    xstring copy = (xstring )malloc(len);
    if (copy != xnullptr) {
        memcpy(copy, str, len);
    }
    return copy;
}

xstring current_datetime(void) {
    time_t rawtime;
    struct tm* timeinfo;
    static char datetime[20];  // Buffer to hold the formatted date and time

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", timeinfo);

    return datetime;
}

static xstring replace_underscore(const xstring str) {
    xstring result = xstrdup(str);
    xstring ptr = result;

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
static void xconsole_out(const xstring color_name, const xstring format, ...) {
    va_list args;
    va_start(args, format);
    
    if (xcli.color) {
        xstring color_code = "";
        
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
const xstring empty_runner_comment() {
    const xstring comments[] = {
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

    srand(time(xnullptr));

    // Generate a random index
    int random_index = rand() % num_comments;

    return comments[random_index];
}

// Function to generate a random tip for unit testing released tasks
// as this would servse as a handy feature and be helpful for teaching
// new developers how they can write good test cases.
const xstring helpful_tester_tip() {
    const xstring tips[] = {
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

    srand(time(xnullptr));

    // Generate a random index
    int random_index = rand() % num_tips;

    return tips[random_index];
}


// ==============================================================================
// Output functions
// ==============================================================================

// Formats and displays information about the start/end of a test case.
static void output_start_test(xtest *test_case, xengine* engine) {
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

    int64_t minutes      = (int64_t)(test_case->timer.elapsed / (60 * CLOCKS_PER_SEC));
    int64_t seconds      = (int64_t)((test_case->timer.elapsed / CLOCKS_PER_SEC) % 60);
    int64_t millis       = (int64_t)(((test_case->timer.elapsed % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC);
    int64_t microseconds = (int64_t)(((test_case->timer.elapsed % CLOCKS_PER_SEC) * 1000000) / CLOCKS_PER_SEC);

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("cyan", ".\t> TIME: - %lld minutes, %lld seconds, %lld milliseconds, %lld microseconds\n", minutes, seconds, millis, microseconds);
        xconsole_out("cyan", ".\t> SKIP: - %s\n", test_case->config.ignored ? "yes" : "no");
        xconsole_out("blue", "[...end...]\n");
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("cyan", "> timestamp: - %lld:%lld:%lld:%lld\n", minutes, seconds, millis, microseconds);
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
    runner->timer.elapsed = runner->timer.end - runner->timer.start;

    int64_t minutes      = (int64_t)(runner->timer.elapsed / (60 * CLOCKS_PER_SEC));
    int64_t seconds      = (int64_t)((runner->timer.elapsed / CLOCKS_PER_SEC) % 60);
    int64_t millis       = (int64_t)(((runner->timer.elapsed % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC);
    int64_t microseconds = (int64_t)(((runner->timer.elapsed % CLOCKS_PER_SEC) * 1000000) / CLOCKS_PER_SEC);

    xconsole_out("blue", "[Test Summary: Fossil Test]: %lld minutes, %lld seconds, %lld milliseconds, %lld microseconds\n", minutes, seconds, millis, microseconds);
    xconsole_out("blue", "***************************: %s\n", current_datetime());

    if (runner->stats.total_count > 0) {
        xconsole_out("cyan", "> - All Passed  : - %.2i\n",    runner->stats.passed_count);
        xconsole_out("cyan", "> - All Failed  : - %.2i\n",    runner->stats.failed_count);
        xconsole_out("cyan", "> - All Skipped : - %.2i\n",    runner->stats.ignored_count);
        xconsole_out("cyan", "> - All Error   : - %.2i\n",    runner->stats.error_count);
        xconsole_out("cyan", "> - Benchmark   : - %.2i\n",    runner->stats.mark_count);
        xconsole_out("cyan", "> - Jellyfish AI: - %.2i\n",   runner->stats.fish_count);
        xconsole_out("orange",  "> - Total Cases : - %.2i\n", runner->stats.total_count);
    } else {
        xconsole_out("cyan", "\n\n\n%s\n\n\n\n\n", empty_runner_comment());
    }

    xconsole_out("blue", "***************************:\n");

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
} // end of func

void output_assert_format(const xstring message, const xstring file, int line, const xstring func) {
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
    XTEST_PASS_SCAN = xfalse;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_assume_format(const xstring message, const xstring file, int line, const xstring func) {
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
    XTEST_PASS_SCAN = xfalse;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_expect_format(const xstring message, const xstring file, int line, const xstring func) {
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
    XTEST_PASS_SCAN = xfalse;
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_xerrors_format(const xstring reason, const xstring file, int line, const xstring func) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    if (xcli.verbose && !xcli.cutback) {
        xconsole_out("blue", "***************************:\n");
        xconsole_out("orange", " .\n\t> File: %s .\n\t> Line: %d .\n\t> Function: %s\n", file, line, func);
        xconsole_out("orange", " .\n\t> Test error: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xconsole_out("orange", "Test error: %s\n", reason);
        xconsole_out("orange", "File: %s, Line: %d, Function: %s\n", file, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xconsole_out("orange", "[F]");
    }
    XERRORS_TEST_CASE = xtrue;

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

void output_xignore_format(const xstring reason, const xstring file, int line, const xstring func) {
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
    XIGNORE_TEST_CASE = xtrue;

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
    XTEST_PASS_SCAN = xfalse;

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
}

// Prints usage instructions, including custom options, for a command-line program.
static void output_usage_format(void) {
    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator in: %s\n", __func__); 
    }

    xconsole_out("blue", "Usage: xcli [options] %s\n", current_datetime());
    xconsole_out("blue", "Options:\n");
    xconsole_out("cyan", "\t-h, --help   : Display this help message                             :\n");
    xconsole_out("cyan", "\t-v, --version: Display program version                               :\n");
    xconsole_out("cyan", "\t-t, --tip    : Display a helpful tip                                 :\n");
    xconsole_out("cyan", "\t--cutback    : Enable cutback 50%% of output                         :\n");
    xconsole_out("cyan", "\t--verbose    : Enable verbose mode for extra information             :\n");
    xconsole_out("cyan", "\t--shuffle    : Enable shuffle test cases in queue                    :\n");
    xconsole_out("cyan", "\t--reverse    : Enable reverse test cases in queue                    :\n");
    xconsole_out("cyan", "\t--human      : Enable human format mode                              :\n");
    xconsole_out("cyan", "\t--color      : Enable colored output                                 :\n");
    xconsole_out("cyan", "\t--ci         : Enable CI pipeline optimizer to save time             :\n");
    xconsole_out("cyan", "\t--only-test  : Run only test cases                                   :\n");
    xconsole_out("cyan", "\t--only-fish  : Run only AI training cases                            :\n");
    xconsole_out("cyan", "\t--only-mark  : Run only benchmark cases                              :\n");
    xconsole_out("cyan", "\t--repeat N   : Repeat the test N times (requires a numeric argument) :\n");
    xconsole_out("cyan", "\t--debug      : Enable debug mode\n");

    if (xcli.debug) {
        xconsole_out("purple", "DEBUG: operator leaving: %s\n", __func__); 
    }
} // end of func

// ==============================================================================
// Xtest internal argument parser logic
// ==============================================================================

// Initialize queue
xqueue* xqueue_create() {
    xqueue* queue = (xqueue*)malloc(sizeof(xqueue));
    if (!queue) {
        return xnullptr;
    }
    queue->front = xnullptr;
    queue->rear = xnullptr;
    return queue;
}

// Check if queue is empty
xbool xqueue_is_empty(xqueue* queue) {
    return queue->front == xnullptr;
}

// xqueue_enqueue an xtest node
void xqueue_enqueue(xqueue* queue, xtest* test) {
    test->next = xnullptr;
    if (xqueue_is_empty(queue)) {
        queue->front = test;
        queue->rear = test;
    } else {
        queue->rear->next = test;
        queue->rear = test;
    }
}

// xqueue_dequeue an xtest node
xtest* xqueue_dequeue(xqueue* queue) {
    if (xqueue_is_empty(queue)) {
        return xnullptr;
    }
    xtest* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == xnullptr) {
        queue->rear = xnullptr;
    }
    temp->next = xnullptr;
    return temp;
}

// Shuffle the queue
void xqueue_shuffle(xqueue* queue) {
    srand(time(NULL));  // Seed the random number generator

    for (xtest* current = queue->front; current != xnullptr; current = current->next) {
        int j = rand() % (queue->rear - queue->front + 1);

        // Swap elements at i and j
        xtest* temp = current;
        current = queue->front;
        for (int i = 0; i < j && current != xnullptr; i++) {
            current = current->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        if (j == 0) {
            queue->front = temp->next;
        } else if (j == queue->rear - queue->front) {
            queue->rear = temp->prev;
        }
        temp->prev = xnullptr;
        temp->next = xnullptr;
        if (queue->front == xnullptr || queue->rear == xnullptr) {
            queue->front = temp;
            queue->rear = temp;
        } else {
            temp->next = queue->front;
            queue->front->prev = temp;
            queue->front = temp;
        }
    }
}

// Reverse the queue
void xqueue_reverse(xqueue* queue) {
    xtest* current = queue->front;
    while (current != xnullptr) {
        xtest* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }

    // Swap front and rear pointers
    xtest* temp = queue->front;
    queue->front = queue->rear;
    queue->rear = temp;
}

// Erase the queue
void xqueue_erase(xqueue* queue) {
    while (!xqueue_is_empty(queue)) {
        xtest* current_test = xqueue_dequeue(queue);
        if (current_test != xnullptr) {
            free(current_test); // Free memory allocated for dequeued test case
        }
    }
}

// ==============================================================================
// Xtest internal argument parser logic
// ==============================================================================

// Function to check if a specific option is present
static xbool xparser_has_option(int argc, xstring argv[], const xstring option) {
    for (int32_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], option) == 0) {
            return xtrue;
        }
    }
    return xfalse;
}

// Original xparser_parse_args function
static void xparser_parse_args(int argc, xstring argv[]) {
    xcli.cutback   = xfalse;
    xcli.verbose   = xfalse;
    xcli.dry_run   = xfalse;
    xcli.repeat    = xfalse;
    xcli.debug     = xfalse;
    xcli.color     = xfalse;
    xcli.only_test = xfalse;
    xcli.only_mark = xfalse;
    xcli.shuffle   = xfalse;
    xcli.reverse   = xfalse;
    xcli.ci        = xfalse;

    for (int32_t i = 1; i < argc; i++) {
        if (xparser_has_option(argc, argv, "--dry-run")) {
            xcli.dry_run = xtrue;
        } else if (xparser_has_option(argc, argv, "--cutback")) {
            xcli.cutback = xtrue;
            xcli.verbose = xfalse;
        } else if (xparser_has_option(argc, argv, "--verbose")) {
            xcli.ci = xtrue;
        }else if (xparser_has_option(argc, argv, "--debug")) {
            xcli.debug = xtrue;
        } else if (xparser_has_option(argc, argv, "--color")) {
            xcli.color = xtrue;
        } else if (xparser_has_option(argc, argv, "--shuffle")) {
            xcli.shuffle = xtrue;
        } else if (xparser_has_option(argc, argv, "--reverse")) {
            xcli.reverse = xtrue;
        } else if (xparser_has_option(argc, argv, "--human")) {
            xcli.color = xtrue;
            xcli.verbose = xtrue;
        } else if (xparser_has_option(argc, argv, "--ci")) {
            xcli.ci = xtrue;
        } else if (xparser_has_option(argc, argv, "--only-test")) {
            xcli.only_test = xtrue;
            xcli.only_fish = xfalse;
            xcli.only_mark = xfalse;
        } else if (xparser_has_option(argc, argv, "--only-fish")) {
            xcli.only_fish = xtrue;
            xcli.only_mark = xfalse;
            xcli.only_test = xfalse;
        } else if (xparser_has_option(argc, argv, "--only-mark")) {
            xcli.only_mark = xtrue;
            xcli.only_fish = xfalse;
            xcli.only_test = xfalse;
        } else if (xparser_has_option(argc, argv, "--version") || xparser_has_option(argc, argv, "-v")) {
            xconsole_out("blue", "2.0.1\n");
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--tip") || xparser_has_option(argc, argv, "-t")) {
            xconsole_out("blue", "%s\n", helpful_tester_tip());
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--help") || xparser_has_option(argc, argv, "-h")) {
            output_usage_format();
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--repeat")) {
            xcli.repeat = xtrue;
            if (++i < argc) {
                int iter_repeat = atoi(argv[i]);
                if (iter_repeat >= MIN_REPEATS && iter_repeat <= MAX_REPEATS) {
                    xcli.iter_repeat = iter_repeat;
                } else {
                    xconsole_out("red", "Error: --repeat value must be between 1 and 100.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                xconsole_out("red", "Error: --repeat option requires a numeric argument.\n");
                exit(EXIT_FAILURE);
            }
        }

        // Check if the program is running in CI mode
        if (xcli.ci) {
            xcli.verbose = xfalse;
            xcli.cutback = xtrue;
            xcli.shuffle = xtrue;
            xcli.color = xfalse;
            xcli.debug = xfalse;
        }
    }
} // end of func

// ==============================================================================
// Xtest create and erase
// ==============================================================================

// Initializes an xengine and processes command-line arguments.
xengine xtest_create(int argc, xstring *argv) {
    xengine runner;
    xparser_parse_args(argc, argv);

    runner.stats = (xstats){0, 0, 0, 0, 0, 0, 0, 0};
    runner.timer = (xtime){0, 0, 0};
    runner.queue = xqueue_create();

    if (xcli.dry_run) { // Check if it's a dry run
        xconsole_out("blue", "Simulating config step...\n");
    }
    runner.timer.start = clock();
    return runner;
} // end of func

// Finalizes the execution of a Trilobite XUnit runner and displays test results.
int xtest_erase(xengine *runner) {
    if (xcli.shuffle) {
        xqueue_shuffle(runner->queue);
    }

    if (xcli.reverse) {
        xqueue_reverse(runner->queue);
    }

    xtest_run_queue(runner);

    if (xcli.dry_run) {
        xconsole_out("blue", "Simulating test results...\n");
    } else {
        output_summary_format(runner);
    }
    xqueue_erase(runner->queue); // Erase the queue
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
    for (uint8_t iter = 0; iter < xcli.iter_repeat; iter++) {
        if (fixture && fixture->setup) {
            fixture->setup();
        }

        test_case->test_function();

        if (fixture && fixture->teardown) {
            fixture->teardown();
        }
    }
} // end of func

// Common functionality for running a test case.
static void xtest_run_test(xengine* engine, xtest* test_case, xfixture* fixture) {
    output_start_test(test_case, engine);

    if (!xcli.dry_run && !XIGNORE_TEST_CASE) {
        xtest_run(test_case, fixture);

    } else if (!xcli.dry_run && XIGNORE_TEST_CASE) {
        test_case->config.ignored = XIGNORE_TEST_CASE;
        XIGNORE_TEST_CASE = xfalse;

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
    test_case->config.ignored   = xfalse;
    test_case->fixture.setup    = xnullptr;
    test_case->fixture.teardown = xnullptr;

    xqueue_enqueue(engine->queue, test_case);
} // end of func

void xtest_run_as_fixture(xengine* engine, xtest* test_case, xfixture* fixture) {
    test_case->config.ignored   = xfalse;
    test_case->fixture.setup    = fixture->setup;
    test_case->fixture.teardown = fixture->teardown;

    xqueue_enqueue(engine->queue, test_case);
} // end of func

// Run all test cases in the queue
void xtest_run_queue(xengine* engine) {
    while (!xqueue_is_empty(engine->queue)) {
        xtest* current_test = xqueue_dequeue(engine->queue);
        if (current_test != xnullptr) {
            xtest_run_test(engine, current_test, xnullptr);
        }
    }
}

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
}

static void assume_duration_minutes(double expected, double actual) {
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / (double)CLOCKS_PER_SEC / 60.0;
    if (elapsed_time < expected) {
        output_benchmark_format(expected, actual);
    }
}

static void assume_duration_seconds(double expected, double actual) {
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / (double)CLOCKS_PER_SEC;
    if (elapsed_time < expected) {
        output_benchmark_format(expected, actual);
    }
}

static void assume_duration_milliseconds(double expected, double actual) {
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / ((double)CLOCKS_PER_SEC / 1000);
    if (elapsed_time < expected) {
        output_benchmark_format(expected, actual);
    }
}

static void assume_duration_picoseconds(double expected, double actual) {
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / ((double)CLOCKS_PER_SEC / 1000000000);
    if (elapsed_time < expected) {
        output_benchmark_format(expected, actual);
    }
}

void mark_duration(xstring duration_type, double expected, double actual) {
    if (strcmp(duration_type, "minutes") == 0) {
        assume_duration_minutes(expected, actual);
    } else if (strcmp(duration_type, "seconds") == 0) {
        assume_duration_seconds(expected, actual);
    } else if (strcmp(duration_type, "milliseconds") == 0) {
        assume_duration_milliseconds(expected, actual);
    } else if (strcmp(duration_type, "picoseconds") == 0) {
        assume_duration_picoseconds(expected, actual);
    } else {
        xconsole_out("red", "Unknown option: %s\n", duration_type);
    }
}

// ==============================================================================
// Xtest functions for asserts
// ==============================================================================

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xignore(const xstring reason, const xstring file, int line, const xstring func) {
    output_xignore_format(reason, file, line, func);
} // end of func

// Marks a test case as error with a specified reason and prints it to stderr.
void xerrors(const xstring reason, const xstring file, int line, const xstring func) {
    output_xerrors_format(reason, file, line, func);
} // end of func


// Custom assumptions function with optional message.
void xassume(xbool expression, const xstring message, const xstring file, int line, const xstring func) {
    if (ASSUME_ISSUES == ASSUME_MAX) {
        return;
    }
    if (!expression) {
        output_assume_format(message, file, line, func);
    }
} // end of func

// Custom assertion function with optional message.
void xassert(xbool expression, const xstring message, const xstring file, int line, const xstring func) {
    if (!XTEST_PASS_SCAN) {
        return;
    }
    if (!expression) {
        output_assert_format(message, file, line, func);
    }
} // end of func

// Custom expectation function with optional message.
void xexpect(xbool expression, const xstring message, const xstring file, int line, const xstring func) {
    if (!expression) {
        output_expect_format(message, file, line, func);
    }
} // end of func
