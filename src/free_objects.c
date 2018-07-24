#include <stdlib.h>
#include "grid.h"
#include "read.h"
#include "free.h"

void		*free_objects(char *str, t_grid_line *line, t_read_cue *r_cue)
{
	free(str);
	free_list(line);
	free(r_cue);
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
