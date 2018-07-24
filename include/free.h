#ifndef FREE_H
# define FREE_H

# include "read.h"

void		*free_objects(char *str, t_grid_line *line, t_read_cue *r_cue);
void		free_list(t_grid_line *line);

#endif
