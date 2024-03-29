/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:56:31 by loamar            #+#    #+#             */
/*   Updated: 2019/10/22 16:59:35 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_get_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	size;
	int				i;
	char			*str;

	nb = (n < 0) ? (unsigned int)(n * -1) : (unsigned int)n;
	size = (n < 0) ? ft_get_size(nb) + 1 : ft_get_size(nb);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	i = size - 1;
	str[size] = '\0';
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = (nb % 10) + '0';
	return (str);
}
