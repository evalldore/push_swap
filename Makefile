NAME		:= push_swap
SRCS		:= main.c operations.c push.c reverse.c rotate.c swap.c sort.c index.c
INCDIR		:= include/
BINDIR		:= bin/
SRCDIR		:= src/
OBJS		:= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CFLAGS		:= -Wall -Wextra -Werror -g
RM			:= rm -f
LIBFT		:= ./lib/libft
LIBS		:= $(LIBFT)/libft.a
HEADERS		:= -I ./include -I $(LIBFT)/include
CC			:= gcc

all : libft $(NAME)

visualizer :
	./push_swap_visualizer/build/bin/visualizer

libft:
	@$(MAKE) -C $(LIBFT)

$(BINDIR)%.o : $(SRCDIR)%.c
	@$(CC) -c $(CFLAGS) -o $@ $^ $(HEADERS)

$(NAME) : $(BINDIR) $(OBJS)
	@echo PUSH_SWAP: Compiling!
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS)

$(BINDIR) :
	@mkdir $(BINDIR)

clean:
	@echo PUSH_SWAP: Deleting binaries.
	@rm -r $(BINDIR)
	@$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@echo PUSH_SWAP: Deleting program.
	@rm -f $(NAME)

re : fclean all