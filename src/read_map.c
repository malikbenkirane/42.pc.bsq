#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "error.h"
#include "grid.h"
#include "constants.h"
#include "grid.h"
#include "grid_lines.h"
#include "free.h"
#include "ft.h"
#include "read.h"

char			*ft_realloc(char *current, char *to_add)
{
	char	*str;
	int		current_len;
	int		i;
	int		j;

	current_len = ft_strlen(current);
	if (!(str = (char*)malloc(sizeof(char) * (current_len + ft_strlen(to_add) + 1))))
		return (NULL);
	i = 0;
	while (current[i])
	{
		str[i] = current[i];
		i++;
	}
	j = 0;
	while (to_add[j])
	{
		str[i + j] = to_add[j];
		j++;
	}
	str[i + j] = '\0';
	free(current);
	return (str);
}

/*
** TODO TESTME t_grid *read_map(int fildes)
*/
t_read_cue	*read_map(int fildes)
{
	t_grid_desc	*grid_desc;
	t_grid		*grid;
	t_read_cue	*read_cue;

	if ((grid_desc = read_description(fildes)) == NULL)
		exit_with_map_error();
	if ((grid = (t_grid *)malloc(sizeof(t_grid))) == NULL)
	{
		free(grid_desc);
		return (NULL);
	}
	if ((read_cue = read_file(fildes, grid_desc, grid)) == NULL)
		exit_with_map_error();
	read_cue->cue_line = grid->first_line;
	free(read_cue->buffer);
	return (read_cue);
}

t_read_cue		*read_file(int fildes, t_grid_desc *grid_desc, t_grid *grid)
{
	t_read_cue	*r_cue;

	if ((r_cue = (t_read_cue *)malloc(sizeof(t_read_cue))) == NULL)
		return (NULL);
	if ((r_cue->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
		return (free_objects(NULL, NULL, r_cue));
	if ((grid->first_line = init_grid_line()) == NULL)
		return (free_objects(r_cue->buffer, NULL, NULL));
	r_cue->cue_line = grid->first_line;
	r_cue->fildes = fildes;
	if (read_file_lines(grid_desc, grid, r_cue) == NULL)
		return (free_objects(r_cue->buffer, grid->first_line, r_cue));
	if (*(r_cue->cue) != '\0')
		return (free_objects(r_cue->head, grid->first_line, NULL));
	if (map_count_lines(r_cue->head) != grid_desc->nline)
		return (free_objects(r_cue->head, grid->first_line, NULL));
	free(r_cue->buffer);
	return (r_cue);
}


void 			*read_file_lines(t_grid_desc *grid_desc, t_grid *grid, t_read_cue *r_cue)
{
	int			size;

	while ((size = read(r_cue->fildes, r_cue->buffer, BUFFER_SIZE)) > 0)
	{
		r_cue->buffer[size] = '\0';
		r_cue->cue = ft_realloc(r_cue->cue, r_cue->buffer);
		while (size > 0 && !iseol(r_cue->buffer))
		{
			size = read(r_cue->fildes, r_cue->buffer, BUFFER_SIZE);
			r_cue->buffer[size] = '\0';
			r_cue->cue = ft_realloc(r_cue->cue, r_cue->buffer);
			r_cue->head = r_cue->cue;
		}
		if (size == 0 && !iseol(r_cue->buffer))
			return (free_objects(r_cue->head, grid->first_line, NULL));
		if (!read_map_line(&(r_cue->cue), grid_desc, r_cue->cue_line))
			return (free_objects(r_cue->head, grid->first_line, NULL));
		if ((grid->first_line->next_line = init_grid_line()) == NULL)
			return (free_objects(r_cue->head, grid->first_line, NULL));
		r_cue->cue_line = grid->first_line->next_line;
	}
	return ((void *)1);
}

t_dyn_int		map_count_lines(char *tmp)
{
	t_dyn_int nline;

	nline = 0;
	while (*tmp)
		if (*tmp++ == '\n')
			nline++;
	return (nline);
}
