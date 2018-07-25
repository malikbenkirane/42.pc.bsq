#include "constants.h"
#include "read.h"
#include "grid_lines.h"

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
t_bool			read_map_line(char **str,
		t_grid_desc *grid_desc, t_grid_line *line)
{
	t_dyn_int len;
	char *cur;

	cur = *str;
	len = 0;
	while(*cur && *cur != '\n')
	{
		if (*cur != grid_desc->empty_c && *cur != grid_desc->trap_c)
			return (FALSE);
		len++;
		cur++;
	}
	if (len == 0)
		return (FALSE);
	if (grid_desc->ncol == 0)
		grid_desc->ncol = len;
	else if (len != grid_desc->ncol)
		return (FALSE);
	line->grid_line = (t_dyn_int *)malloc(sizeof(t_dyn_int) * len);
	update_grid_line(*str, grid_desc, line);
	*str = *str + len + 1;
	return (TRUE);
}
