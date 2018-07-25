/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:55:05 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:55:33 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "free.h"
#include "read.h"
#include "constants.h"

t_read_cue		*init_read_cue(void)
{
	t_read_cue *r_cue;

	r_cue = (t_read_cue *)malloc(sizeof(t_read_cue));
	if (r_cue == NULL)
		return (NULL);
	r_cue->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	r_cue->head = (char *)malloc(sizeof(char));
	if (r_cue->head == NULL)
	{
		free_read_cue(r_cue);
		return (NULL);
	}
	*(r_cue->head) = '\0';
	r_cue->cline = 0;
	return (r_cue);
}
