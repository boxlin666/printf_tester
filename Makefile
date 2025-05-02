# Makefile for ft_printf project
# Based on the 42 school ft_printf specification (Version 10.2)

# Name of the library to be created
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files: List all your .c files here based on ft_printf.h
SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putptr.c \
	   ft_putnbr.c \
	   ft_putunbr.c \
	   ft_puthex.c \
	   parse_format.c

# Object files: Automatically generated from source files
OBJS = $(SRCS:.c=.o)

# Libft integration (if you have a libft folder with its own Makefile)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# All rule: Default rule to build the library
all: $(NAME)

# Rule to build the library
$(NAME): $(OBJS) $(LIBFT)
	@ar rcs $@ $(OBJS) $(LIBFT)
	@echo "Library $(NAME) created successfully."

# If libft exists, build it first
$(LIBFT):
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		make -C $(LIBFT_DIR); \
	else \
		echo "Libft not found or not needed."; \
	fi

# Compile .c files to .o files
%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule: Remove object files
clean:
	@rm -f $(OBJS)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		make clean -C $(LIBFT_DIR); \
	fi
	@echo "Object files removed."

# Fclean rule: Remove object files and the library
fclean: clean
	@rm -f $(NAME)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		make fclean -C $(LIBFT_DIR); \
	fi
	@echo "Library removed."

# Re rule: Rebuild everything
re: fclean all

# Bonus rule: Compile bonus files separately
bonus:
	# Add your bonus source files here, e.g., *_bonus.c
	# Example: BONUS_SRCS = ft_bonus.c another_bonus.c
	# Then: $(CC) $(CFLAGS) -c $(BONUS_SRCS)
	# Finally, add them to the library: ar rcs $(NAME) $(BONUS_OBJS)
	@echo "Implement bonus sources in this rule and add to $(NAME)."
	# For now, this is a placeholder. Update it based on your bonus files.

# Phony targets: These are not actual files
.PHONY: all clean fclean re bonus