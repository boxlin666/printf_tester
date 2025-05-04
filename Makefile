NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putptr.c \
	   ft_putnbr.c \
	   ft_putunbr.c \
	   ft_puthex.c \
	   ft_puthex_upper.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:

.PHONY: all clean fclean re bonus