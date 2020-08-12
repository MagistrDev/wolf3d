NAME = wolf
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
LIBFT = -I./libft -L./libft -lft
LIBS = -lm 
INCLUDES = -I./include -I./include/SDL2
SDL = -L./lib -lmingw32 -lSDL2main -lSDL2
SRCS = main.c 

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	make -C libft/
	$(CC) $(FLAGS) $(SRCS:.c=.o) $(INCLUDES) $(LIBFT) $(SDL) $(LIBS) -o $(NAME)

%.o : %.c
	$(CC) -c $(FLAGS) $< $(INCLUDES) $(LIBFT) $(SDL) $(LIBS) -o $@
libft.a :
	make -C libft/

clean:
	make -C libft clean
	/bin/rm -f $(SRCS:.c=.o)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all