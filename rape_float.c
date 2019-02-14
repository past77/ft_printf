/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rape_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:00:55 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/10 15:00:58 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		do_float(t_struc *form)
{
	long				double val;

	if (form->lo == 1)
		val = va_arg(form->ap, long double);
	else
		val = va_arg(form->ap, double);
	return (val);
}

t_struc					*pr_float(t_struc *form)
{
	long	double val;

	val = do_float(form);
	if (val != val)
	{
		form->ret_nb += write(1, "nan", 3);
		return (0);
	}
	else if (val * 2 == val && val != 0)
	{
		form->ret_nb += write(1, "inf", 3);
		return (0);
	}
	make_chaos(form, val);
	return (form);
}

t_struc					*sings_flt(t_struc *form, long double val, int key)
{
	if (key == 1)
	{
		if (form->zero == '0')
			form->ret_nb += write(1, "0", 1);
		else
			form->ret_nb += write(1, " ", 1);
	}
	else
	{
		if (val > 0 && form->plus == '+')
			form->ret_nb += write(1, "+", 1);
		if (val > 0 && form->space == ' ')
			form->ret_nb += write(1, " ", 1);
		form->ret_nb += write(1, form->help, ft_strlen(form->help));
	}
	return (form);
}

t_struc					*prn_width_flt(t_struc *form)
{
	int		i;
	int		len;
	int		pl;
	int		spc;

	i = 0;
	pl = (form->plus == '+') ? 1 : 0;
	spc = (form->space == ' ') ? 1 : 0;
	len = pl + spc + (int)ft_strlen(form->help);
	if (form->press >= 0)
	{
		while (form->width - i++ > len)
			sings_flt(form, 0, 1);
		i = 1;
		while ((int)ft_strlen(form->help) < len - i++)
			form->ret_nb += write(1, "0", 1);
	}
	else
	{
		while (form->width - i++ > len)
			form->ret_nb += ((!form->zero) ?
			write(1, " ", 1) : write(1, "0", 1));
	}
	return (form);
}

t_struc					*make_chaos(t_struc *form, long double val)
{
	check_pres_flt(form, val);
	if (form->minus == '-')
	{
		sings_flt(form, val, 0);
		prn_width_flt(form);
	}
	else
	{
		prn_width_flt(form);
		sings_flt(form, val, 0);
	}
	free(form->help);
	return (form);
}
