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

uintmax_t		do_unsign_nb(t_struc *form)
{
	uintmax_t	num;

	if (form->hh == 1)
		num = (unsigned char)va_arg(form->ap, unsigned int);
	else if (form->h == 1)
		num = (unsigned short)va_arg(form->ap, unsigned int);
	else if (form->ll == 1)
		num = va_arg(form->ap, unsigned long long);
	else if (form->l == 1)
		num = va_arg(form->ap, unsigned long);
	else if (form->j == 1)
		num = va_arg(form->ap, uintmax_t);
	else if (form->z == 1)
		num = va_arg(form->ap, size_t);
	else
		num = va_arg(form->ap, unsigned int);
	return (num);
}
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
	if (form->s_flag == 'x')
		rape_digit(num, str, &i ,base);
	else
		rape_ldigit(num, str, &i ,base);
	str[i] = '\0';
	return (str);
} 

void			fill_hash(t_struc *form)
{
	char		*buf;
	static char	*hash = NULL;
	int	hs;
	int	lhs;

	hs = (form->s_flag == 'x') ? 1 : 0;
	lhs = (form->s_flag == 'X') ? 1 : 0;
	if (form->s_flag == 'x' || form->s_flag == 'o')
		hash = hs ? ft_strdup("0x") : ft_strdup("0");
	else if (form->s_flag == 'X')
		hash = lhs ? ft_strdup("0X") : ft_strdup("0");
	if (form->zero == '0')
	{
		form->width = (hs == 1 || lhs == 1) ? (form->width - 2) : (form->width - 1);
		fill_width(form);
	}
	if (ft_strncmp(form->help, "0", 1) || (form->s_flag != 'o'))
	{
		buf = form->help;
		form->help = ft_strjoin(hash, buf);
		free(buf);
	}
	free(hash);
}

void			fill_zero(t_struc *form)
{
	size_t		i;
	size_t		presicion;
	char		*buff;
	char		*part;

	i = 0;
	presicion = (size_t)form->press;
	if (presicion <= ft_strlen(form->help))
		return ;
	buff = (char*)ft_memalloc(presicion - ft_strlen(form->help) + 1);
	while (i < presicion -  ft_strlen(form->help))
	{
		buff[i] = '0';
		i++;
	}
	part = form->help;
	form->help = ft_strjoin(buff, part);
	free(buff);
	free(part);
}

void			fill_width(t_struc *form)
{
	size_t		_do;
	size_t		_mi;
	char		*fa;
	char		*sol;

	_do = (size_t)form->width;
	if (ft_strlen(form->help) > _do)
		return ;
	_mi = 0;
	fa = form->help;
	sol = (char*)ft_memalloc(_do - ft_strlen(form->help) + 1);
	while (_mi < _do - ft_strlen(form->help))
		sol[_mi++] = (form->zero == '0' ? '0' : ' ');
	sol[_mi] = '\0';
	if (form->minus == '-')
	{
		if(form->zero == '0')
			sol = ignore_zero(form, _do);
		form->help = ft_strjoin(fa, sol);
	}
	else
		form->help = ft_strjoin(sol, fa);
	free(sol);
	free(fa);
}

char			*ignore_zero(t_struc *form, size_t d)
{
	char		*sol;
	size_t		mi;

	mi = 0;
	sol = (char*)ft_memalloc(d - ft_strlen(form->help) + 1);
	while (mi < d - ft_strlen(form->help))
		sol[mi++] = ' ';
	sol[mi] = '\0';
	return (sol);
}

void			*choose_signs(t_struc *form)
{
	if (form->press >= 0)
		fill_zero(form);
	if (form->hash == '#')
		fill_hash(form);
	fill_width(form);
	form->ret_nb += ft_strlen(form->help);
	write(1, form->help, ft_strlen(form->help));
	free(form->help);
	return (0);
}

t_struc			*ft_bases(t_struc *form, int base)
{
	uintmax_t	val;

	val = do_unsign_nb(form);
	if (val == 0 && form->hash == '#' && form->s_flag == 'o')
	{
		form->ret_nb += write(1, "0", 1);
		return (0);
	}
	if (form->press == 0)
	{
		if (form->width > 0)
		{
			form->help = ft_strdup("");
			fill_width(form);
			form->ret_nb += ft_strlen(form->help);
			write(1, form->help, ft_strlen(form->help));
		}
		return (0);
	}
	if (val == 0 )
	{
		form->ret_nb += write(1, "0", 1);
		return (0);
	}
	form->help = ft_lit_base (val, base, form);
	choose_signs(form);
	return (form);
}
