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

void			check_pres_flt(t_struc *form, long double val)
{
	long double	nb;
	char		*prec;
	int			p;
	char		*buf;

	prec = ft_strnew(1);
	nb = val;
	val = val < 0 ? -val : val;
	// val -= (long)val;
	p = form->press >= 0 ? form->press : 6;
	prec = prn_prec_flt(prec, p, &val);
	//if (nb > 1 && 2 > nb)
		//nb++;
	buf = (!nb) ? ft_exeptiontoa(nb) : ft_longtoa(nb);
	if (form->prec == 0 && form->hash == '#')
		form->format = ft_strjoin(buf, ".");
		//free(buf);
	else
		rape_prec_flt(form, buf, prec);
}

void		sings_flt(t_struc *form, long double val)
{
	if (val > 0 && form->plus == '+')
		form->ret_nb += write(1, "+", 1);
	if (val > 0 &&  form->space == ' ')
		form->ret_nb += write(1, " ", 1);
	form->ret_nb += write(1, form->format, ft_strlen(form->format));
}

void		make_chaos(t_struc *form, long double val)
{
	pres_float(form, val);
	if (firm->minus == '-')
	{
		sings_flt(form, val);
		prn_width_flt(form);
	}
	else
	{
		prn_width_flt(form);
		sings_flt(flt, val);
	}
	free (form->format);
}
