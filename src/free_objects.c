/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:48:41 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:48:58 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "grid.h"
#include "read.h"
#include "free.h"

void		*free_objects(t_grid_line *line, t_read_cue *r_cue)
{
	free_list(line);
	free_read_cue(r_cue);
	return (NULL);
}

void		free_list(t_grid_line *line)
{
	if (line == NULL)
	{
		free(line);
		return ;
	}
	free_list(line->next_line);
	free(line);
}

void		free_read_cue(t_read_cue *r_cue)
{
	if (r_cue == NULL)
		return ;
	if (r_cue->buffer)
		free(r_cue->buffer);
	if (r_cue->head)
		free(r_cue->head);
	if (r_cue->cue)
		free(r_cue->cue);
	free(r_cue);
}
