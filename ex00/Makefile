CC = g++ 

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = DivideAndRule.cpp

NAME = Divide

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all