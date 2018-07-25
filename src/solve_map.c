/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:02:20 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 20:04:01 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "grid.h"
#include "solve.h"
#include "grid_lines.h"

void			solve_map(t_grid *grid, char *map_str, t_grid_desc *grid_desc)
{
	t_bsq_solution	*solution;
	t_dyn_int		offset;
	t_dyn_int		counter;
	char			*ptr;

	/*
	** TODO look for calls of solve_map
	** (spot unsecure access to grid or grid_access)
	*/
	grid->width = grid_desc->ncol;
	grid->height = grid_desc->nline;
	if ((solution = solve_bsq(grid)) == NULL)
		return ;
	counter = 0;
	ptr = map_str + solution->argopt;
	while (counter < solution->opt)
	{
		offset = 0;
		while (offset > -(solution->opt))
		{
			ptr[offset] = grid_desc->fill_c;
			offset--;
		}
		ptr = ptr - grid_desc->ncol + 1;
		counter++;
	}
}

t_bsq_solution	*solve_bsq(t_grid *grid)
{
	t_dyn_int		i;
	t_dyn_int		j;
	t_dyn_int		size;
	t_bsq_solution	*solution;

	i = 1;
	j = 1;
	if ((solution = init_bsq_solution()) == NULL)
		return (NULL);
	while (i < grid->width && j <= grid->height)
	{
		i = 0;
		while (++i < grid->width)
		{
			size = get_min(grid, i, j);
			if (size > solution->opt)
			{
				solution->opt = size;
				solution->argopt = j * grid->width + i;
			}
			set_opt_size(grid, i, j, size);
		}
		j++;
	}
	return (solution);
}

t_dyn_int		get_min(t_grid *grid, t_dyn_int i, t_dyn_int j)
{
	t_dyn_int	left;
	t_dyn_int	above;
	t_dyn_int	diag;

	left = get_opt_size(grid, i - 1, j);
	above = get_opt_size(grid, i, j - 1);
	diag = get_opt_size(grid, i - 1, j - 1);
	return (MIN_3(left, above, diag));
}

t_bsq_solution	*init_bsq_solution(void)
{
	t_bsq_solution *solution;

	if ((solution = (t_bsq_solution *)malloc(sizeof(t_bsq_solution))) == NULL)
		return (NULL);
	solution->opt = 0;
	solution->argopt = 0;
	return (solution);
}
