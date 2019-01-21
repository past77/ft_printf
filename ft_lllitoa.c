/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:40:51 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/14 15:40:54 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rape_decimal(intmax_t num, char *str, int *i)
{
	char *values = "0123456789";

	if (num > 9 || num < -9)
		rape_decimal(num / 10, str, i);
	str[(*i)++] = values[num < 0 ? -(num % 10) : (num % 10)];
}

char	*ft_llongitoa(intmax_t num)
{
	int 	i;
	char	*str;

	i = 0;
	str = (char*)malloc(32);
	if (!str)
		return (NULL);
	rape_decimal(num, str, &i);
	str[i] = '\0';
	return (str);
} 

/*char	*ft_llongitoa_base(uintmax value, int base)
{

}
*/

/*
size_t		len_of_nbr(int nb)
{
	size_t i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

char	*ft_itoa(intmax_t n)
{
	size_t			len;
	char			*str;
	intmax_t	new_n;

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
*/
