#include <stdlib.h>

void		*free_objects(char *str, t_grid_line *line)
{
	free_list(line);
	free(str);
	return (NULL);
}

void		free_list(t_grid_line *line)
{
	if (line == NULL)
	{
		free(line);
		return ;
	}
	free_list(line->next_line);
	free(line);
}
