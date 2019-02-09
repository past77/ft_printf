/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:53:33 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/26 13:53:35 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pt_pointer(t_struc *form)
{
	uintmax_t	val;
	char		*p;
	int			i;

	i = 0;
	val = (unsigned long)(va_arg(form->ap, unsigned long int));
	val = (uintmax_t)val;
	if (!(p = ft_lit_base(val, 16, form)))
		exit(-1);
	if (form->press == 0 && val == 0)
		*p = '\0';
	if (form->zero == '0' && form->press == -1 && form->minus != '-')
	{
		form->press = form->width - 2;
		form->width = 0;
	}
	prnt_p(form, p, i);
	return (form->ret_nb);
}

t_struc		*prnt_p(t_struc *form, char *p, int i)
{
	int		np;
	int		np2;

	np = ft_strlen(p) + 2;
	np2 = np;

	if (form->minus != '-')
		fill_uni(form, ' ', form->width - np2);
	write (1, "0x", 2);
	fill_uni(form, '0', (form->press - np) + 2);
	write(1, &p, ft_strlen(p));
	if (form->minus == '-')
		fill_uni(form, ' ', form->width - np2);
	free (p);
	return (form);
}

void		fill_uni(t_struc *form, char a, int i)
{
	char	*str;

	if (i > 0)
	{
		if (!(str = ft_strnew(i)))
			exit (-1);
		ft_memset(str, a, i);
		write(1, str, i);
		free(str);
	}
}

static int		convert(int num)
{
	if (0 <= num && 9 >= num)
	{
		return ((char)num + '0');
	}
	else if (10 <= num && num <= 15)
	{
		num = num - 10;
		return (num + 97);
	}
	return (0);
}

char			*ft_ptoa(unsigned long val)
{
	char			*p;
	int				size;
	unsigned long	num;

	num = val;
	size = 0;

	while (num > 16)
	{
		num = num / 16;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			num = val % 16;
			p[size] = convert(num);
			val = val / 16;
			size--;
		}
	}
	return (p);
}
