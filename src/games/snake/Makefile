##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/pacman/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 09:25:42 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 03:18:27 2017 Anas Buyumad
##

NAME=		./../../../games/lib_arcade_nibbler.so

SRCS=		./snake.cpp\
			../Entity.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS+=	-W -Wall -Wextra \
			-I./ \
			-std=c++11

CXX=		g++ -fPIC

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS) -shared

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
