/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:14:20 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 20:14:42 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

typedef struct	s_bsq_solution
{
	t_dyn_int	opt;
	t_dyn_int	argopt;
}				t_bsq_solution;

t_bsq_solution	*solve_bsq(t_grid *grid);
void			solve_map(t_grid *grid, char *map_str, t_grid_desc
		*grid_desc);

t_dyn_int		get_min(t_grid *grid, t_dyn_int i, t_dyn_int j);
t_bsq_solution	*init_bsq_solution();

#endif
