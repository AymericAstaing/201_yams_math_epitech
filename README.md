# 201_yams_math_epitech (tech 2 2018/2019)

Compute the probabilities of combinations of independent events

The goal of this project is to code a software that help us cheat at Yams game. 

It will give you the chances to obtain a given combination at the next dice roll, among:

      • a pair (at least 2 dice of the same value)
      • a three-of-a-kind (at least 3 dice of the same value)
      • a four-of-a-kind (at least 4 dice of the same value)
      • a full house (one pair and one three-of-a-kind)
      • a straight (5 dice of sequential value)
      • a yahtzee (5 dice of the same value)
      
      Combinaison parameter will be like the following : pair_A ; three_A ; four_A ; full_A_B ; straight_A ; yams_A
      
The combination is defined by its kind (pair, three-of-a-kind, four-of-a-kind, full-house, straight or yahtzee) and its
value (for a full-house, the value of the three-of-a-kind then the value of the pair, for the straight, the value of the
highest die)

to build:

    make / make re
    
to launch:

USAGE
   
    ./201yams d1 d2 d3 d4 d5 c

DESCRIPTION

    d1 value of the first die (0 if not thrown)
    d2 value of the second die (0 if not thrown)
    d3 value of the third die (0 if not thrown)
    d4 value of the fourth die (0 if not thrown)
    d5 value of the fifth die (0 if not thrown)
    c expected combination
    
Aymeric Astaing - EPITECH PARIS PROMO 2022
