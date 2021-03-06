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

char			*ft_ltoa(long n)
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

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	new_n;

	len = len_of_nbr(n);
	new_n = n;
	if (n < 0)
	{
		new_n = -n;
		len++;
	}
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	str[--len] = new_n % 10 + '0';
	while (new_n /= 10)
		str[--len] = new_n % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
