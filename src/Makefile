##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## solarfox makefile
##

NAME=		./../arcade

SRCS=		main.cpp	\
				core/core.cpp	\
				core/parser/parser.cpp	\
				core/home/home.cpp	\
				games/IGame.cpp		\
				games/Text.cpp
				#core/gameHandler/gameHandler.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra \
			-I./	\
			-std=c++11 -ldl -rdynamic

CXX=		g++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
