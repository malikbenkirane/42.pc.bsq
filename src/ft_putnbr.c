/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrizac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:49:47 by mtrizac           #+#    #+#             */
/*   Updated: 2018/07/25 19:49:57 by mtrizac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft.h"

void	ft_putnbr(int number)
{
	if (number == INT_MIN)
	{
		ft_putchar('-');
		ft_putnbr(number / 10);
		ft_putchar(-(number % 10) + '0');
	}
	if (number < 0)
	{
		number *= -1;
		ft_putchar('-');
	}
	if (number > 9)
		ft_putnbr(number / 10);
	ft_putchar(number % 10 + '0');
}
