NAME = libpipex.a
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c \
	error_msgs.c \
	error_msgs2.c \
	children.c \
	free_cmds.c \
	write_error.c \
	execute_command.c \
	env_path.c \
	ls_command.c \

OBJ = $(SRCS:.c=.o)
LIBFT = -Llibft -lft
FPRINT = -Lft_printf -lftprintf
RM = rm -f
EXE = pipex

all: $(EXE)

run: all
	./pipex file.txt "grep TEST" "grep 123" outfile

$(EXE): $(NAME)
	make -C libft
	make -C ft_printf
	cc $(NAME) $(FPRINT) $(LIBFT) -o $(EXE)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: $(OBJ)
	$(RM) $(OBJ)

fclean: clean
	make -C ft_printf fclean
	make -C libft fclean
	$(RM) $(NAME) $(EXE)

re: fclean all
