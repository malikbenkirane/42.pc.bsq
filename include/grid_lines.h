#ifndef GRID_LINES_H
# define GRID_LINES_H

#include "grid.h"

t_grid_line		*init_grid_line();
void			update_grid_line(char *cur, t_grid_desc *grid_desc, t_grid_line *line);

t_dyn_int		get_opt_size(t_grid *grid, t_dyn_int posx, t_dyn_int posy);
void			set_opt_size(t_grid *grid, t_dyn_int posx, t_dyn_int posy, t_dyn_int val);

#endif
