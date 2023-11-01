/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:06 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/10/27 17:56:09 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//bea did this function differently, using a function to find the length of the
//int, one for absolute value, itoa and finally putnbr, but my version should
//work too. 
#include "ft_printf.h"

int	absolute_value(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_intlen(long int n)
{
	int	len;

	if (n <= 0)
	{
		n = -n;
		len = 1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa(nb);
	counter += ft_putstr(str);
	free (str);
	return (counter);
}
