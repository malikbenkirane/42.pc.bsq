#ifndef GRID_H
# define GRID_H

#include <unistd.h>
#include <stdlib.h>
#include "constants.h"
#include "macros.h"

typedef	struct		s_grid
{
	unsigned int	*grid;
	unsigned int	width;
	unsigned int	height;
}					t_grid;

typedef	struct		s_grid_desc
{
	unsigned int	nline;
	unsigned int	ncol;
	char			empty_c;
	char			trap_c;
	char			fill_c;
}					t_grid_desc;

t_grid 				*read_map(int fildes);
t_grid_desc			*read_description(int fildes);
char				*is_valid_description(short *length, int fildes);

#endif
