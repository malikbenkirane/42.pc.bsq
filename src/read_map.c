/*
** TODO think if it's necessary to use int type to count
** the biggest square size.
**
** e.g. tiny / short (1 or 2 bytes could suffy)
**
** get exit calls to the right exit status specification
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "grid.h"
#include "constants.h"
#include "ft.h"

t_grid 			*read_map(int fildes)
{
	t_grid_desc	*grid_desc;
	/*
	** XXX
	** - malloc and return ref
	** must exit if error
	*/
	if ((grid_desc = read_description(fildes)) == NULL)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	return (NULL);
}

/*
** read_map_first_line(t_grid_desc *, 
**
