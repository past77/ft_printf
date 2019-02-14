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

int					ft_atoi(const char *str)
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

size_t				len_of_nbr(intmax_t nb)
{
	size_t i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		;
	while (s2[++j])
		;
	if (!(r = (char *)ft_memalloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	j = -1;
	while (s2[++j])
		r[i++] = s2[j];
	r[i] = '\0';
	return (r);
}

char				*ft_strcat(char *s1, const char *s2)
{
	int cout;
	int i;

	i = 0;
	cout = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[cout + i] = s2[i];
		i++;
	}
	s1[cout + i] = '\0';
	return (s1);
}

char				*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
