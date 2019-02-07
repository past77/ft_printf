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
	if (form->minus != '-')
		ft_putstr("0x");
	form->ret_nb += 2;
	p = ft_ptoa(val);
	if (form->minus == '-')
		i = 1;
	if (form->press == 0 && val == 0)
		*p = '\0';
	if (form->zero == '0' && form->press == -1 && form->minus != '-')
	{
		form->press = form->width - 2;
		form->width = 0;
	}
	
	//pt_point(form, p, i);
	//form->ret_nb += write(1, p, ft_strlen(p));
	free(p);
	return (form->ret_nb);
}
/*
t_struc			pt_point(t_struc *form, char *p, int i)
{
	if (i == 0)
		displ(form, ' ', form->width - ft_strlen(p));
*/

static int		convert(int num)
{
	if (0 <= num && 9 >= num)
	{
		return (num + 48);
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
