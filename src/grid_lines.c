#include "grid_lines.h"

void			update_grid_line(char *cur, t_grid_desc *grid_desc, t_grid_line *line)
{
	int len;

	len = 0;
	while(*cur && *cur != '\n')
	{
		if (*cur == grid_desc->empty_c)
			line->grid_line[len] = 1;
		else
			line->grid_line[len] = 0;
		cur++;
		len++;
	}
}


t_grid_line		*init_grid_line()
{
	t_grid_line *grid_line;

	grid_line = (t_grid_line *)malloc(sizeof(t_grid_line));
	return (grid_line);
}
