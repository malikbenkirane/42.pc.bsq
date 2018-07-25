/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:11:53 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 20:12:18 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include <unistd.h>
# include <stdlib.h>
# include "constants.h"
# include "macros.h"

typedef	struct			s_grid_line
{
	t_dyn_int			*grid_line;
	struct s_grid_line	*next_line;
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
#endif
