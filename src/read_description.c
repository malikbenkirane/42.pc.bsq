#include "grid.h"

/*
** (int) readpint:
** returns the number represented by the null-terminated string *str*
** updates *number* with the integer representation of *str*
*/

short			readpint(char *str, unsigned int *number)
{
	short		length;

	if (*str == '\0')
		return (0);
	*number = 0;
	length = 0;
	while (ISNUMBER(*str))
	{
		*number += *str - '0';
		str++;
		if (ISNUMBER(*str))
			*number *= 10;
		length++;
	}
	if (*str != '\0')
		return (0);
	return (length);
}

t_grid_desc		*read_description(int fildes)
{
	t_grid_desc	*grid_desc;
	short		total_length;
	short		number_length;
	char		*buf;

	if ((buf = is_valid_description(&total_length, fildes)) == NULL)
		return (NULL);
	if (!(grid_desc = (t_grid_desc *)malloc(sizeof(grid_desc))))
		return (NULL);
	grid_desc->fill_c = buf[total_length - 1];
	grid_desc->trap_c = buf[total_length - 2];
	grid_desc->empty_c = buf[total_length - 3];
	buf[total_length - 3] = '\0';
	if (!IS_3_DIFF(grid_desc->fill_c, grid_desc->trap_c, grid_desc->empty_c))
		return (NULL);
	if (!(number_length = readpint(buf, &(grid_desc->nline))))
		return (NULL);
	if (number_length + 3 != total_length)
		return (NULL);
	return (grid_desc);
}

char			*is_valid_description(short *length, int fildes)
{	
	char	*buf;
	short	n;

	if ((buf = (char *)malloc(sizeof(char) * (DESC_MAX_LEN + 1))) == NULL)
		return (NULL);
	if (read(fildes, buf, 1) <= 0) 
		return (NULL);
	if (!ISNUMBER(*buf))
		return (NULL);
	n = 1;
	while (n < DESC_MAX_LEN &&
			read(fildes, buf + n, 1) == 1 &&
			!ISNEWLINE(buf[n]))
		n++;
	if (!ISNEWLINE(buf[n]))
		return (NULL);
	*length = n;
	return (buf);
}
