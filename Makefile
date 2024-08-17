# Source files
SRCS = pipex.c err_handler.c get_path.c init_handler.c parsing.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = pipex_bonus.c parsing_bonus.c err_handler_bonus.c init_handler_bonus.c get_path_bonus.c fd_ctl_bonus.c \
 here_doc_bonus.c init_struct_bonus.c handle_job_bonus.c command_parsing_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS =

LIBFT = make -C libft
PRINTF = make -C libft/printf

NAME = pipex

BONUS = pipex_bonus

all: $(NAME)

libs:
	$(LIBFT)
	$(PRINTF)

$(NAME): $(OBJS) libs 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Llibft/printf -lftprintf

bonus: $(OBJS_BONUS) libs 
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) -Llibft -lft -Llibft/printf -lftprintf

%.o: %.c pipex.h pipex_bonus.h
	echo "Building $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	echo "Removing all object files..."
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(LIBFT) clean
	$(PRINTF) clean

fclean: clean
	@echo "Removing executable and libs..."
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(LIBFT) fclean
	$(PRINTF) fclean

re: fclean all

.PHONY: clean

.SILENT:
