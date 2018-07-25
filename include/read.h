#ifndef READ_H
# define READ_H

#include "grid.h"

typedef	struct	s_read_cue
{
	int			fildes;
	t_dyn_int	cline;
	char		*head;
	char		*cue;
	char		*buffer;
	t_grid_line	*cue_line;
}				t_read_cue;


t_bool			iseol(char *str);
t_dyn_int		map_count_lines(char *tmp);
t_read_cue		*read_map(int fildes, t_grid_desc **grid_desc, t_grid **grid);
t_read_cue		*read_file(int fildes, t_grid_desc *grid_desc, t_grid *grid);
void 			*read_file_lines(t_grid_desc *grid_desc, t_grid *grid, t_read_cue *r_cue);
t_bool			read_map_line(char **str, t_grid_desc *grid_desc, t_grid_line *line);
t_read_cue		*init_read_cue();

void			*ft_realloc(t_read_cue *r_cue);
t_grid_desc		*read_description(int fildes);

#endif
