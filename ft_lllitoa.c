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

intmax_t	do_unsign_nb(t_struc *form)
{

	intmax_t num;

	if (form->hh == 1)
		num = (unsigned char)va_arg(form->ap, unsigned int);
	else if (form->h == 1)
		num = (unsigned short)va_arg(form->ap, unsigned int);
	else if (form->ll == 1)
		num = va_arg(form->ap,unsigned  long long);
	else if (form->l == 1)
		num = va_arg(form->ap,unsigned  long);
	else if (form->j == 1)
		num = va_arg(form->ap, uintmax_t);
	else if (form->z == 1)
		num = va_arg(form->ap, size_t);
	else
		num = (int)va_arg(form->ap,unsigned  int);
	return (num);
	if (num == 0 && form->s_flag != 'o')
		form->hash = 0;
}

static void	rape_digit(uintmax_t num, char *str, int *i, int base)
{
	char *values;

	values = "0123456789abcdef";
	if (num >= (uintmax_t)base)
		rape_digit(num / base, str, i, base);
	str[(*i)++] = values[num % base];
}

char	*ft_lit_base(intmax_t num, int base)
{
	int		i;
	char	*str;
	//printf("check: %s\n", form->format);

	i = 0;
	if (!(str = (char*)malloc(32)))
		return (NULL);
	if (base > 16 || base < 2)
		return (NULL);
	rape_digit(num, str, &i ,base);
	str[i] = '\0';
	return (str);
} 


void		fill_hash(t_struc *form)
{
	char	*buf;
	char	*hash;
	int		hs;

	hs = (form->s_flag == 'x' || form->s_flag == 'X') ? 1 : 0;
	hash = hs ? ft_strdup("0x") : ft_strdup("0");
	if (form->zero == '0')
	{
		form->width = (hs == 1) ? (form->width - 1) : (form->width - 2);
	/*
		if (hs == 1)
			form->width - 1; //form->width = (hs == 1) ? (form-width - 1) : (form->width - 2);
		else
			form->width - 2;
		fill_width(form); */
	}
	if (ft_strncmp(form->format, "0", 1) || (form->s_flag != 'o'))
	{
		buf = form->format;
		form->format = ft_strjoin(hash, buf);
		free(buf);
	}
	free(hash);
}

void		fill_width(t_struc *form)
{
	size_t	_do;
	size_t	_re;
	size_t	_mi;
	char	*fa;
	char	*sol;

	_do = (size_t)form->width;
	_re = ft_strlen(form->format);
	if (_re > _do)
		return ;
	_mi = 0;
	fa = form->format;
	sol = (char*)ft_memalloc(_do - _re + 1);
	while (_mi < _do - _re)
		sol[_mi++] = (form->zero == '0' ? '0' : ' ');
	sol[_mi] = '\0';
	if (form->minus == '-')
		form->format = ft_strjoin(fa, sol);
	else
		form->format = ft_strjoin(sol, fa);
	free(sol);
	free(fa);
}
void		*choose_signs(t_struc *form)
{
	char f;

	f = form->s_flag;
	if (form->hash == '#')
		fill_hash(form);
	form->ret_nb += ft_strlen(form->format);
	write(1, form->format, ft_strlen(form->format));
	free(form->format);
	return (0);
}

t_struc		*ft_bases(t_struc *form, int base)
{
	intmax_t	val;
	char *format;
	val = do_unsign_nb(form);
	format = ft_lit_base (val, base);
	form->format = format;
	choose_signs(form);
	return (form);
}

