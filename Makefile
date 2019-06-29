##
## EPITECH PROJECT, 2018
## 201yams Math Project
## File description:
## Makefile of 201yams
##

CC			=	g++ -std=c++11

NAME		=	201yams

CFLAGS		=	-Wall -Wextra -Werror -g3

SRC			=	main.cpp

SRC			+=	src/YamsCheater.cpp			\
				src/Calculations.cpp

OBJ			=	$(SRC:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

all:				$(NAME)


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:
	fclean re clean
