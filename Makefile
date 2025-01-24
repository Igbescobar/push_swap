CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iincludes
NAME	= push_swap

SRC_PATH = src
UTILS_PATH = utils
OBJ_PATH = obj

SRCS =  $(wildcard $(SRC_PATH)/*.c) $(wildcard $(UTILS_PATH)/*.c)
CHECK_SRCS = $(wildcard $(UTILS_PATH)/*.c) $(SRC_PATH)/instructions.c checker.c

OBJS = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(SRCS)))
CHECK_OBJS = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(CHECK_SRCS)))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(UTILS_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -f $(NAME)

re: fclean all
