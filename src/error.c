/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:44:45 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:47:45 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "error.h"

void	exit_with_map_error(void)
{
	ft_putstr("map error\n");
	exit(1);
}
