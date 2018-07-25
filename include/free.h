/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:10:49 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 20:11:10 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "read.h"

void		*free_objects(t_grid_line *line, t_read_cue *r_cue);
void		free_list(t_grid_line *line);
void		free_read_cue(t_read_cue *r_cue);

#endif
