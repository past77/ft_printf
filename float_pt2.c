/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:30:38 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/14 19:30:40 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_exeption(double n)
{
	unsigned long long	*mass;

	mass = (unsigned long long *)&n;
	if (*mass >> 63 & 1)
		return (ft_strdup("-0"));
	if (!n)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

char					*prn_prec_flt(char *pr, int p, long double *val, int i)
{
	char				*str;
	char				*tmp;
	static double		dou = 0.5;

	str = ft_strnew(1);
	while (i++ < p)
		dou *= 0.1;
	*val += val ? dou : 0;
	if (*val >= 1 && p == 6)
		pr = ft_strdup("000000");
	else if (*val < 1)
	{
		i = 0;
		while (i++ < p)
		{
			*val *= 10;
			*str = (int)*val + '0';
			tmp = pr;
			pr = ft_strjoin(tmp, str);
			free(tmp);
			*val -= (int)*val;
		}
	}
	free(str);
	return (pr);
}

t_struc					*rape_prec_flt(t_struc *form, char *buf, char *prec)
{
	char				*nb;

	if (form->press == 0)
		form->help = ft_strdup(buf);
	else
	{
		nb = ft_strjoin(buf, ".");
		form->help = nb;
		form->help = ft_strjoin(nb, prec);
		free(nb);
		free(prec);
	}
	free(buf);
	return (form);
}

t_struc					*check_pres_flt(t_struc *form, long double val)
{
	long double			nb;
	char				*prec;
	int					p;
	char				*buf;
	int					i;

	i = 0;
	prec = ft_strnew(1);
	nb = val;
	val = val < 0 ? -val : val;
	val -= (long)val;
	p = form->press >= 0 ? form->press : 6;
	prec = prn_prec_flt(prec, p, &val, i);
	buf = (!nb) ? ft_exeption(nb) : ft_ltoa(nb);
	if (form->press == 0 && form->hash == '#')
	{
		form->help = ft_strjoin(buf, ".");
		free(buf);
	}
	else
		rape_prec_flt(form, buf, prec);
	return (form);
}
