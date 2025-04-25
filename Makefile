NAME	= libftprintf.a

# 编译器 & 编译选项
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# ft_printf 的源文件
SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
		  ft_putunbr.c ft_puthex.c ft_puthex_upper.c ft_putptr.c

OBJS	= $(SRCS:.c=.o)

TEST_NAME	= test_ft_printf
TEST_SRC	= test_ft_printf.c
CRITERION_FLAGS = -lcriterion

# libft 路径
LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

# 默认目标
all: $(LIBFT_LIB) $(NAME)

# 构建 libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# 构建 ft_printf 的 .a 库（包含 ft_printf 的目标文件和 libft）
$(NAME): $(OBJS)
	cp $(LIBFT_LIB) $(NAME)
	$(MAKE) -C $(LIBFT_DIR)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_SRC) $(NAME) $(CRITERION_FLAGS)
	./$(TEST_NAME)

re: fclean all
.PHONY: all clean fclean re