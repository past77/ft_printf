/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fn1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:08:33 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 16:08:40 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr(const char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_putchar (char c)
{
	write(1, &c, 1);
	return (1);
}


int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
}

char	*ft_itoa(int n)
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
