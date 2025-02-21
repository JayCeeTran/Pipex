NAME = libpipex.a
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c \
	children.c \
	close_fds.c \
	env_path.c \
	error_msg.c \
	execute_command.c \
	free_cmds.c \
	path_as_command.c \
	space_only_commands.c \
	store_initial_arguments_into_struct.c \
	validate_files.c \
	write_error.c \

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

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C ft_printf fclean
	make -C libft fclean
	$(RM) $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re run
