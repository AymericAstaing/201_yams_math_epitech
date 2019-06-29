#ifndef YAMSCHEATER_H_
#define YAMSCHEATER_H_

#include <map>
#include <string>

class YamsCheater {
    public:
                    YamsCheater();
                    ~YamsCheater();
        int         parse_input(char**);
        int         current_identical(int*, int);
        int         parse_instruction(char*);
        float       get_identical_dice_proba(int*, int, int);
        bool        valid_list(std::map<int, bool>*, int);
        float       get_straight_proba(int *, int);
        float       get_full_dice_proba(int *, int, int);
        bool        start_calculate();
        int*        get_dices_values() const { return (dices); };
        int         get_A_value() const { return (_a); };
        int         get_B_value() const { return (_b); };
        int         check_instruction(std::string);
        std::string get_instruction() const { return (instructions); };
    private:
        int*        dices;
        int         _a = -1;
        int         _b = -1;
        std::string instructions;
};

#endif
