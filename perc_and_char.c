/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_with_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:45:16 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 16:45:18 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


t_struc		*pt_persent(t_struc *form)
{
	char c;
	int length;
	int space;
	int zero;

	length = form->width;
	c = '%';
	if (form->s_flag == '%' && form->zero != '0' && form->minus != '-' && length == 0) 
		form->ret_nb += ft_putchar(c);
	else if (form->zero == '0' && form->minus != '-')
	{
		zero = '0';
		pt_width_c(form, c, zero);
	}
	else if (form->zero != '0' && form->minus != '-' && length > 0)
	{
		space = ' ';
		pt_width_c(form, c, space);
	}
	else if (form->minus == '-')
	{
		space = ' ';
		pt_width_c(form, c, space);
	}
	return (form);
}

t_struc		*pt_char(t_struc *form)
{
	char c;
	int length;
	int space;
	int zero;

	length = form->width;
	c = va_arg(form->ap, int);
	if (form->s_flag == 'c' && form->zero != '0' && form->minus != '-'&& length == 0) 
		form->ret_nb += ft_putchar(c);		
	else if (form->zero == '0' && form->minus != '-')
	{
		zero = '0';
		pt_width_c(form, c, zero);
	}
	else if (form->zero != '0' && form->minus != '-' && length > 0)
	{
		space = ' ';
		pt_width_c(form, c, space);
	}
	else if (form->minus == '-')
	{
		space = ' ';
		pt_width_c(form, c, space);
	}
	return (form);
}

void	*pt_width_c(t_struc *form, char c, int sign)
{
	char *string;
		if (form->width == 0)
		{
			write(1, &c, 1);
			form->ret_nb += 1;
		}
	else if ((form->width - 1) > 0)
	{
		form->ret_nb += form->width;
		if ((string = ft_strnew(form->width - 1)) == NULL)
			exit (-1);
		if (form->minus == '-')
			write(1, &c, 1);
		ft_memset(string, sign, form->width - 1);
		write(1, string, form->width - 1);
		if (form->minus != '-')
			write(1, &c, 1);
		free(string);
	}
	return(0);
} 	
