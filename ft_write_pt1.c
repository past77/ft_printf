/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pt1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:04:45 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 17:04:48 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_write_u(t_struc *form, intmax_t num)
{
	if (num < 0)
		num *= -1;
	if (num > 9)
		ft_write_dig(form, num / 10);
	form->ret_nb += ft_putchar((num % 10) + '0');
}

void	ft_write_dig(t_struc *form, intmax_t num)
{

	if (num < 0)
	{
		form->ret_nb += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_write_dig(form, num / 10);
	form->ret_nb += ft_putchar((num % 10) + '0');
}

void	ft_write_dig_pl(t_struc *form, intmax_t num)
{
	if (num >= 0)
		form->ret_nb += ft_putchar('+');
	else if (num < 0)
	{
		form->ret_nb += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_write_dig(form, num / 10);
	form->ret_nb += ft_putchar((num % 10) + '0');
}
/*
void	*ft_memalloc(size_t size)
{
	char	*mal;

	mal = malloc(size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, size);
	return (mal);
}
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	if (!n || (!s1 && !s2))
		return (0);
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (int)n)
		i++;
	if (i == (int)n)
		return (s3[i - 1] - s4[i - 1]);
	return (s3[i] - s4[i]);
}
