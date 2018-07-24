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

char	*ft_realloc(char *current, char *to_add)
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

t_grid 			*read_map(int fildes)
{
	t_grid_desc	*grid_desc;
	char		*map_str;

	/*
	** XXX
	** - malloc and return ref
	** must exit if error
	*/
	if ((grid_desc = read_description(fildes)) == NULL)
		exit_with_map_error();
	if ((map_str = read_file(fildes) == NULL))
		exit_with_map_error();
	/*
	** TODO test read_file re-written
	*/.
	return (NULL);
}

char			*read_file(int fildes, t_grid *grid)
{
	char		*buf;
	int			size;
	char		*str;
	t_grid_desc	*grid_desc;

	if (!(buf = (char*)malloc(sizeof(*buf) * BUFFER_SIZE + 1)))
		return (NULL)
	total_size = 0;
	while ((size = read(fildes, buf, BUFFER_SIZE)))
	{
		while (size > 0 && !iseol(buf))
		{
			size = read(fildes, buf, BUFFER_SIZE);
			buf[size] = '\0';
			str = ft_realloc(str, buf);
		}
		if (size == 0 && !iseol(buf))
			return (NULL);
		if (!read_map_first_line(&str, grid_desc, grid))
			return (NULL);
	}
	(*str)[total_size] = '\0';
	return (str);
}
