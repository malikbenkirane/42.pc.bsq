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

char				*is_valid_description(short *length, int fildes);
char				*read_file(int fildes, t_grid *grid)
char				*ft_realloc(char *current, char *to_add)
t_grid				*read_map(int fildes)
t_grid_desc			*read_description(int fildes);

#endif
