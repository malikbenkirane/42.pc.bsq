#ifndef FREE_H
# define FREE_H

# include "read.h"

void		*free_objects(t_grid_line *line, t_read_cue *r_cue);
void		free_list(t_grid_line *line);
void		free_read_cue(t_read_cue *r_cue);

#endif
