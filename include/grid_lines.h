/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_lines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:12:24 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 20:12:59 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_LINES_H
# define GRID_LINES_H
# include "grid.h"

t_grid_line		*init_grid_line();
void			update_grid_line(char *cur, t_grid_desc *grid_desc,
		t_grid_line *line);

t_dyn_int		get_opt_size(t_grid *grid, t_dyn_int posx, t_dyn_int posy);
void			set_opt_size(t_grid *grid, t_dyn_int posx, t_dyn_int posy,
		t_dyn_int val);
#endif
