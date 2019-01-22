/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fn3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:14:48 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 16:15:04 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_atoi(const char *str)
{
	int				i;
	long long int	minus;
	long long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
	&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
	&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		res = (res * 10) + (long long int)str[i++] - '0';
	}
	return (res * minus);
}

size_t		len_of_nbr(intmax_t nb)
{
	size_t i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}