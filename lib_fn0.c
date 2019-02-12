/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fn0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:00:18 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/12 20:00:20 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		llen_of_nbr(long n)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = n;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (n < 0)
		len++;
	return (len);
}

char			*ft_longtoa(long n)
{
	long	tmp;
	int		len;
	char	*str;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = llen_of_nbr(tmp);
	if (tmp < 0)
		tmp = -tmp;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (tmp)
	{
		str[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_exeptiontoa(double n)
{
	unsigned long long *mass;

	mass = (unsigned long long *)&n;
	if (*mass >> 63 & 1)
		return (ft_strdup("-0"));
	if (!n)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

