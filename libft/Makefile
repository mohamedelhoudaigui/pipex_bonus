SRCS			=	ft_bzero.c ft_calloc.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
 					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
					 ft_strnstr.c ft_strtrim.c ft_substr.c get_next_line.c get_next_line_utils.c
OBJS			= $(SRCS:.c=.o)

CC				= cc

RM				= rm -f

CFLAGS			= -c -g -I.

NAME			= libft.a

all:			$(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c libft.h get_next_line.h
	@echo "Building $<..."
	$(CC) $(CFLAGS) $<

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:	clean

.SILENT: