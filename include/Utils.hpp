#ifndef UTILS_H_
#define UTILS_H_

#define     HELP_FILE           "help"
#define     HELP_FLAG           "-h"
#define     UTMOST(A, B)        (A < 1 ? B : A)
#define     INTO_DICE(A)        ((A > 0 && A < 7) ? true : false)        
#define     NOT_ENOUGH_ARGS     "Please provide enough arguments (7)."
#define     INVALID_ARGS        "Please provide valid arguments try: ./201yams -h"
#define     INVALID_INSTRUCTION "Please provide valid instruction."
#define     EXIT_FAIL           84
#define     EXIT_SUCCESS        0

#endif