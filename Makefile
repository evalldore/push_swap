NAME		:= push_swap
SRCS		:= main.c operations.c
INCDIR		:= include/
BINDIR		:= bin/
SRCDIR		:= src/
OBJS		:= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f
LIBFT		:= ./lib/libft
LIBS		:= $(LIBFT)/libft.a
HEADERS		:= -I ./include -I $(LIBFT)/include
CC			:= gcc

all : libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

$(BINDIR)%.o : $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) -o $@ $^ $(HEADERS)

$(NAME) : $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS)

$(BINDIR) :
	mkdir $(BINDIR)

clean:
	@rm -r $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)

re : fclean all