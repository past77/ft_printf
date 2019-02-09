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

static void		rape_ldigit(uintmax_t num, char *str, int *i, int base)
{
	char		*lval;

	lval = "0123456789ABCDEF";
	if (num >= (uintmax_t)base)
		rape_ldigit(num / base, str, i, base);
	str[(*i)++] = lval[num % base];
}

static void		rape_digit(uintmax_t num, char *str, int *i, int base)
{
	char		*val;

	val = "0123456789abcdef";
	if (num >= (uintmax_t)base)
		rape_digit(num / base, str, i, base);
	str[(*i)++] = val[num % base];
}

char			*ft_lit_base(intmax_t num, int base, t_struc *form)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(32)))
		return (NULL);
	if (base > 16 || base < 2)
		return (NULL);
	if (form->s_flag == 'x' || form->s_flag == 'p')
		rape_digit(num, str, &i, base);
	else
		rape_ldigit(num, str, &i, base);
	str[i] = '\0';
	return (str);
}
