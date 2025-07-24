# THIS FILE IS FOR LINUX (UBUNTU)

NAME := philosphers

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

# Directory structure
MAIN_DIR := main
SRC_DIR := src
OBJ_DIR := obj
LIBFT := libft/libft.a
LIBFT_OBJ := libft/obj

# Source files
MAIN_FILE := main.c
SRC_FILES := 

# Add directory prefixes
MAIN_SRCS := $(addprefix $(MAIN_DIR)/, $(MAIN_FILE))
SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRCS := $(MAIN_SRCS) $(SRCS)

# Object files
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(LIBFT_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) valgrind_log.txt

re: fclean all

# Valgrind rule that logs entire interactive session to a file
valgrind:
	@echo "Philosophers initializing on valgrind mode..."
	script -q -c "valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philosphers" valgrind_log.txt

.PHONY: all clean fclean re valgrind
