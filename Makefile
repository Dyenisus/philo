NAME := philo

CC := cc
CFLAGS := -Wall -Wextra -Werror -pthread -Iinclude
LDFLAGS := -pthread
RM := rm -rf

MAIN_DIR := main
SRC_DIR := src
OBJ_DIR := obj

MAIN_FILE := main.c
SRC_FILES := first_checks.c  forks.c  free.c  ft_atol.c  init.c  monitor.c  \
	parse.c  print.c  routine.c  secondary_checks.c  utils.c

MAIN_SRCS := $(addprefix $(MAIN_DIR)/, $(MAIN_FILE))
SRCS := $(MAIN_SRCS) $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
