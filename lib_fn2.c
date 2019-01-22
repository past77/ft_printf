/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fn2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:08:43 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 16:08:46 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strnew(len);
	if (str == NULL || !s)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char *s1;

	s1 = s;
	ft_memset(s1, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c1;
	char			*b1;
	int				i;

	c1 = (unsigned char)c;
	b1 = b;
	i = 0;
	while (len > 0)
	{
		*b1 = c1;
		b1++;
		len--;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	char	*mal;

	mal = malloc(size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, size);
	return (mal);
}