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
