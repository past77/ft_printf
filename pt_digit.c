/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:22:45 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/12 18:22:46 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		do_number(t_struc *form)
{
	intmax_t num;

	if (form->hh == 1)
		num = (char)va_arg(form->ap, int);
	else if (form->h == 1)
		num = (short)va_arg(form->ap, int);
	else if (form->ll == 1)
		num = va_arg(form->ap, long long);
	else if (form->l == 1)
		num = va_arg(form->ap, long);
	else if (form->j == 1)
		num = va_arg(form->ap, uintmax_t);
	else if (form->z == 1)
		num = va_arg(form->ap, size_t);
	else
		num = (int)va_arg(form->ap, int);
	return (num);
}

t_struc		*choose_index(t_struc *form, intmax_t num)
{
	if (form->plus == '+' && form->width == 0 && form->minus != '-')
		ft_write_dig_pl(form, num);
	else if (form->minus == '-' && form->width > 0 && form->plus != '+' && form->space != ' ')
		ft_write_minus(form, num); 
	else if (form->plus == '+' && form->minus == '-' && form->width > 0)
		ft_write_common(form, num);
	else if (form->plus == '+' && form->zero == '0' && form->width > 0)
		ft_write_zero(form, num);
	else if (form->space == ' ' && form->zero == '0' && form->width > 0 && form->minus != '-')
		ft_write_space_zero(form, num);
	else if (form->space == ' ' && form->minus == '-' && form->width > 0)
		ft_write_space_minus(form, num);
	else if (form->width > 0 && form->plus == '+')
		ft_write_pluswidth(form, num);
	else if (form->width > 0 && form->zero == '0' && form->plus != '+')
		ft_write_owidth(form, num);
	else if (form->width > 0) 
		ft_write_width(form, num);
	else
		ft_write_other(form, num);
	return (form);
}

t_struc		*work_w_press(t_struc *form, intmax_t num)
{

	if ((form->press == 0 && form->width == 0) || (form->press == 0 && form->width != 0))
		ft_ret(form, num);
	else if(form->width >= 0)
		pt_precision(form, num);
	return (form);
}

t_struc		*pt_digit(t_struc *form)
{
	intmax_t num;
	
	num = do_number(form);
	if (form->press >= 0)
		work_w_press(form, num);
	else
		choose_index(form, num);
	return(form);
}






































