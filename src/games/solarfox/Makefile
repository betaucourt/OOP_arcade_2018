##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## solarfox makefile
##

SRC		=	Solarfox.cpp\
			Vessel.cpp\
			../Entity.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	./../../../games/lib_arcade_solarfox.so

CXXFLAGS=	-fPIC -shared -W -Wextra -Wall -I./
CXXDEBUG=	-g

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(CXXFLAGS) $(OBJ)

all:		$(NAME)

debug:
			gcc -o $(NAME) $(CXXDEBUG) $(CXXFLAGS) $(SRC)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all
