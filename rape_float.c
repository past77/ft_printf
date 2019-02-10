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
	long	double val;

	if (form->L == 1)
		val = va_arg(form->ap, long double);
	else
		val = va_arg(form->ap, double);
	return (val);
}

t_struc					*pr_float(t_struc *form)
{
	long double val;

	val = do_float(form);
	if (val != val)
	{
		form->ret_nb += write(1, "nan", 3);
		return (0);
	}
	else if (var * 2 == var && var != 0)
	{
		form->ret_nb += write(1, "inf", 3);
		return (0);
	}
	make_chaos(form, val);
	return(form);
}

void		make_chaos(t_struc *form, long double val)
{

}
