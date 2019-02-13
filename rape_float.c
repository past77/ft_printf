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

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

static long double		do_float(t_struc *form)
{
	long 	double val;

	if (form->L == 1)
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

char	*ft_exeption(double n)
{
	unsigned long long *mass;

	mass = (unsigned long long *)&n;
	//if (*mass >> 63 & 1)
		//return (ft_strdup("-0"));
	if (!n)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

char			*prn_prec_flt(char *prec, int p, long double *val, int i)
{
	char		*str;
	char		*tmp;
	double		dou;

	dou = 0.5;
	str = ft_strnew(1);
	while (i++ < p)
		dou *= 0.1;
	*val += val ? dou : 0;
	if (*val >= 1 && p == 6)
		prec = ft_strdup("000000");
	else if (*val < 1)
	{
		i = 0;
		while (i++ < p)
		{
			*val *= 10;
			*str = (int)*val + '0';
			tmp = prec;
			 prec = ft_strjoin(tmp, str);
			//free (tmp);
			*val -= (int)*val;
		}
	}
	return (prec);
}
t_struc			*rape_prec_flt(t_struc *form, char *buf, char *prec)
{
	char		*nb;

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


t_struc			*check_pres_flt(t_struc *form, long double val)
{
	long double	nb;
	char		*prec;
	int			p;
	char		*buf;
	int			i;

	i = 0;
	prec = ft_strnew(1);
	//if (!val)
	//nb = (double)val;
	nb = val;
	val = val < 0 ? -val : val;
	 val -= (long)val;
	p = form->press >= 0 ? form->press : 6;
	prec = prn_prec_flt(prec, p, &val, i);
	//if (nb > 1 && 2 > nb)
		//nb++;
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

t_struc		*sings_flt(t_struc *form, long double val, int key)
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
		if (val > 0 &&  form->space == ' ')
			form->ret_nb += write(1, " ", 1);
		form->ret_nb += write(1, form->help, ft_strlen(form->help));
	}
	return (form);
}

t_struc		*prn_width_flt(t_struc *form)
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
			form->ret_nb += ((!form->zero) ? write(1, " ", 1) : write(1, "0", 1));
	}
	return (form);
}

t_struc		*make_chaos(t_struc *form, long double val)
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
	free (form->help);
	return (form);
}
