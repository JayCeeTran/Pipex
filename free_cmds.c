#include "pipex.h"

void	free_split(char **commands)
{
	int i;

	i = 0;
	while(commands[i])
		free(commands[i++]);
	free(commands);
}
