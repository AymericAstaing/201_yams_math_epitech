#include <iostream>
#include <math.h>
#include <string.h>
#include "../include/Utils.hpp"
#include "../include/Calculations.hpp"
#include "../include/YamsCheater.hpp"

YamsCheater::YamsCheater() {

}

YamsCheater::~YamsCheater() {
    delete[] dices;
}

int YamsCheater::current_identical(int *combinaison, int number) {
    int nbr = 0;

    for (int i = 0; i < 5; i++) {
        if (combinaison[i] == number)
            nbr++;
    }
    return (nbr);
}

bool YamsCheater::valid_list(std::map<int, bool> *list, int number) {
    for (auto& x: *list) {
        if (number == x.first && x.second == false) {
            (*list).at(x.first) = true;
            return (true);
        }
    }
    return (false);
}

float YamsCheater::get_identical_dice_proba(int *combinaison, int identical_dices, int number) {
    int obj = identical_dices;
    int max = 5;
    int ok = current_identical(combinaison, number);
    int ko = max - ok;
    int min = obj - ok;
    float total = 0;

    if (min <= 0)
        return (1);
    for (int i = min; i <= ko; i++)
        total += Calculations::get_binomial_proba(ko, i);
    return (total / pow(6, ko));
}

float YamsCheater::get_straight_proba(int *combinaison, int serie_type) {
    std::map<int, bool> list;
    int okNbr = 0;
    int koNbr = 0;

    if (serie_type == 5)
        list = {{1, false}, {2, false}, {3, false}, {4, false}, {5, false}};
    else
        list = {{2, false}, {3, false}, {4, false}, {5, false}, {6, false}};
    
    for (int i = 0; i < 5; i++) {
        if (valid_list(&list, combinaison[i]) == true)
            okNbr++;
        else
            koNbr++;
    }
    if (koNbr == 0)
        return (1);
    return (Calculations::factorial(koNbr) / pow(6, koNbr));
}

float YamsCheater::get_full_dice_proba(int *combinaison, int triple_value, int pair_value) {
    int okA = current_identical(combinaison, triple_value);
    int okB = current_identical(combinaison, pair_value);
    int koA = 3 - okA;
    int koB = 2 - okB;
    int totalKo = koA + koB;
    int utmost = 0;

    if (koA <= 0 || koB <= 0) {
        utmost = UTMOST(koA, koB);
        return (Calculations::get_binomial_proba(utmost, utmost) / pow(6, utmost));
    }
    if (koA == 0 && koB == 0)
        return (1);
    return ((Calculations::get_binomial_coeff(totalKo, koA) * Calculations::get_binomial_coeff(totalKo - koA, koB)) / pow(6, totalKo));
}

bool YamsCheater::start_calculate() {
    if (instructions.compare("pair") == 0 && INTO_DICE(_a)) { 
        printf("chances to get a %i pair: %.2f%%\n", _a, get_identical_dice_proba(this->dices, 2, _a) * 100);
        return (true);
    }
    if (instructions.compare("three") == 0 && INTO_DICE(_a)) {
        printf("chances to get a %i three-of-a-kind: %.2f%%\n", _a, get_identical_dice_proba(this->dices, 3, _a) * 100);
        return (true);
    } 
    if (instructions.compare("four") == 0 && INTO_DICE(_a)) { 
        printf("chances to get a %i four-of-a-kind: %.2f%%\n", _a, get_identical_dice_proba(this->dices, 4, _a) * 100);
        return (true);
    } 
    if (instructions.compare("yams") == 0 && INTO_DICE(_a)) { 
        printf("chances to get a %i yams: %.2f%%\n", _a, get_identical_dice_proba(this->dices, 5, _a) * 100);
        return (true);
    }
    if (instructions.compare("full") == 0 && INTO_DICE(_a) && INTO_DICE(_b) && _a != _b) { 
         printf("chances to get a %i full of %i: %.2f%%\n", _a, _b, get_full_dice_proba(this->dices, _a, _b) * 100);
        return (true);
    }
    if (instructions.compare("straight") == 0 && (_a == 5 || _a == 6)) { 
        printf("chances to get a %i straight: %.2f%%\n", _a, get_straight_proba(this->dices, _a) * 100);
        return (true);
    }
    std::cout << INVALID_INSTRUCTION << std::endl;
    return (false);
}

int YamsCheater::check_instruction(std::string digits) {
    int digits_lenght = digits.length();
    if (this->instructions.compare("full") != 0) {
        if (digits_lenght != 1)
            return (1);
    } else if (digits_lenght != 3) {
        return (1);
    } 
    return (0);
}

int YamsCheater::parse_instruction(char *str) {
    std::string full_instruction_str(str);
    this->instructions = full_instruction_str.substr(0, full_instruction_str.find("_"));
    full_instruction_str = full_instruction_str.substr(full_instruction_str.find("_") + 1);
    this->_a = std::atoi(full_instruction_str.c_str());
    if (full_instruction_str.find("_") == 1)
        this->_b = std::atoi((full_instruction_str.substr(full_instruction_str.find("_") + 1).c_str()));
    if (check_instruction(full_instruction_str) == 1) {
        std::cout << INVALID_ARGS << std::endl;
        return (EXIT_FAIL);
    }
    return (EXIT_SUCCESS);
}

int YamsCheater::parse_input(char **argv) {
    this->dices = new int[5];
    for (int i = 0; i < 5; i++)
        this->dices[i] = atoi(argv[i + 1]);
    if (parse_instruction(argv[6]) == EXIT_FAIL)
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}
