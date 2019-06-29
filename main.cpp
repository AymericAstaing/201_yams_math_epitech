#include <string.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include "include/YamsCheater.hpp"
#include "include/Utils.hpp"

bool arguments_are_correct(char **argv) {
    for (int i = 1; argv[i + 1] != NULL; i++) {
        if (strlen(argv[i]) != 1 || argv[i][0] < 48 || argv[i][0] > 54) {
            std::cout << INVALID_ARGS << std::endl;
            return (false);
        }
    }
    return (true);
}

int is_help_requiered(char *arg) {
    if (strcmp(HELP_FLAG, arg) != 0) {
        std::cout << NOT_ENOUGH_ARGS << std::endl;
        return (EXIT_FAIL);
    }
    std::ifstream f(HELP_FILE);
    if (f.is_open())
        std::cout << f.rdbuf() << std::endl;
    return (true);

}

int main(int argc, char **argv) {
    if (argc == 2)
        return (is_help_requiered(argv[1]));
    if (argc != 7) {
        std::cout << NOT_ENOUGH_ARGS << std::endl;
        return (EXIT_FAIL);
    }
    if (!arguments_are_correct(argv))
        return (EXIT_FAIL);
    YamsCheater *yam = new YamsCheater();
    if (yam->parse_input(argv) == EXIT_FAIL || !yam->start_calculate()) {
        delete(yam);
        return (EXIT_FAIL);
    }
    delete(yam);
    return (EXIT_SUCCESS);
}
