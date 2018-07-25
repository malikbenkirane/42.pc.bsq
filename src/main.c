/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:54:20 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:54:56 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		main(int argc, char **argv)
{
	t_grid	*grid;
	int		index;

	if (argc == 1)
	{
		read_map(stdin->_file);
		/*
		** TODO change ft_pustr loop with one write call
		*/
		ft_putstr(solve_map(grid));
	}
	index = 1;
	while (index < argc)
	{
		grid = read_map(open(argv[index++]));
		/*
		** TODO change ft_pustr loop with one write call
		*/
		ft_putstr(solve_map(grid));
	}
}
