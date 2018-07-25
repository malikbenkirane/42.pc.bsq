/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:50:42 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:53:59 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_lines.h"

void		update_grid_line(char *cur, t_grid_desc *grid_desc,
		t_grid_line *line)
{
	int len;

	len = 0;
	while (*cur && *cur != '\n')
	{
		if (*cur == grid_desc->empty_c)
			line->grid_line[len] = 1;
		else
			line->grid_line[len] = 0;
		cur++;
		len++;
	}
}

t_grid_line	*init_grid_line(void)
{
	t_grid_line *grid_line;

	grid_line = (t_grid_line *)malloc(sizeof(t_grid_line));
	return (grid_line);
}

t_dyn_int	*get_opt_line(t_grid *grid, t_dyn_int posy)
{
	t_grid_line	*opt_line;

	opt_line = grid->first_line;
	while (posy-- && opt_line)
		opt_line = opt_line->next_line;
	if (opt_line && opt_line->grid_line)
		return (opt_line->grid_line);
	return (NULL);
}

t_dyn_int	get_opt_size(t_grid *grid, t_dyn_int posx, t_dyn_int posy)
{
	t_dyn_int	*opt_line;

	if ((opt_line = get_opt_line(grid, posy)) == NULL)
		return (0);
	return (opt_line[posx]);
}

void		set_opt_size(t_grid *grid, t_dyn_int posx,
		t_dyn_int posy, t_dyn_int val)
{
	t_dyn_int	*opt_line;

	if ((opt_line = get_opt_line(grid, posy)) == NULL)
		return ;
	opt_line[posx] = val;
}
