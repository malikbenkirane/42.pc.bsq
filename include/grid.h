#ifndef GRID_H
# define GRID_H

#include <unistd.h>
#include <stdlib.h>
#include "constants.h"
#include "macros.h"

typedef	struct			s_grid_line
{
	t_dyn_int			*grid_line;
	struct s_grid_chain	*next_line;
}						t_grid_line;

typedef	struct			s_grid
{
	t_grid_line			*first_line;
	t_dyn_int			width;
	t_dyn_int			height;
}						t_grid;

typedef	struct			s_grid_desc
{
	t_dyn_int			nline;
	t_dyn_int			ncol;
	char				empty_c;
	char				trap_c;
	char				fill_c;
}						t_grid_desc;

char					*is_valid_description(short *length, int fildes);
char					*read_file(int fildes, t_grid *grid)
char					*ft_realloc(char *current, char *to_add)
t_grid					*read_map(int fildes)
t_grid_desc				*read_description(int fildes);

#endif
