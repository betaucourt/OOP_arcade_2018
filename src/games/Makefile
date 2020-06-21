##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 16:41:28 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:11:09 2017 Gauthier Cler
##

all:
		mkdir -p ./../../games
		@make -C snake
		@make -C solarfox

clean:
		@make clean -C snake
		@make clean -C solarfox

fclean:
		@make fclean -C snake
		@make fclean -C solarfox
		rm -rf games

re:		fclean all
