#include <stdlib.h>

void		*free_objects(char *str, t_grid_line *line, t_read_cue *r_cue)
{
	free_list(line);
	free(r_cue);
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
