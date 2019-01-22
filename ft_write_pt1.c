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

