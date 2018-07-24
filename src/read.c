#include "constants.h"
#include "read.h"

t_bool			iseol(char *str)
{
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		return (TRUE);
	return (FALSE);
}

/*
** TODO TESTME
*/
t_bool			read_map_line(char **str, t_grid_desc *grid_desc, t_grid *grid)
{
	unsigned int len;
	char *cur;

	cur = *str;
	len = 0;
	while(*cur && *cur != '\n')
	{
		if (*cur != grid_desc->empty_c ||*cur != grid_desc->trap_c)
			return (FALSE);
		if (*cur == grid_desc->empty_c)
			grid->grid[len] = 1;
		else
			grid->grid[len] = 0;
		cur++;
		len++;
	}
	if (len == 0)
		return (FALSE);
	if (grid_desc->ncol == 0)
		grid_desc->ncol = len;
	else if (len != grid_desc->ncol)
		return (FALSE);
	*str = *str + len + 1;
	return (TRUE);
}
