/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:26:12 by ppolozhe          #+#    #+#             */
/*   Updated: 2018/12/28 15:26:17 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_struc	*form;
	char	*frmt;
	int		revenir;

	frmt = (char *)format;
	form = (t_struc*)malloc(sizeof(t_struc));
	if (!form)
		return (-1);
	form->format = frmt;
	form = ft_init_li(form);
	va_start(form->ap, format);
	if (format)
		form->ret_nb = ft_parse_f(form);
	revenir = form->ret_nb;
	form->ret_nb = 0;
	va_end(form->ap);
	free(form);
	return (revenir);
}

t_struc		*ft_init_li(t_struc *form)
{
	form->len = 0;
	form->i = 0;
	return (form);
}

int			ft_parse_f(t_struc *form)
{
	if (ft_strcmp(form->format, "%") == 0 || form->format == '\0')
		return (0);
	while (form->format[form->i] != '\0')
	{
		if (form->format[form->i] == '%')
		{
			ft_init_other(form);
			ft_separ_fnc(form);
		}
		else
		{
				ft_putchar(form->format[form->i]);
			form->ret_nb++;
		}
		form->i++;
	}
	return (form->ret_nb);
}

t_struc		*ft_init_other(t_struc *form)
{
	form->specificators = "idscuobfxpUX%";
	form->sign = "-+# 0";
	form->lens = "lhzjL";
	form->index = '\0';
	form->l = '\0';
	form->h = '\0';
	form->ll = '\0';
	form->hh = '\0';
	form->s_flag = '\0';
	form->plus = '\0';
	form->minus = '\0';
	form->space = '\0';
	form->hash = '\0';
	form->zero = '\0';
	form->press = -1;
	form->width = 0;
	return (form);
}

int			ft_separ_fnc(t_struc *form)
{
	int		j;
	char	*forma;

	forma = NULL;
	j = 0;
	form->i++;
	p_converse(form);
	p_width(form);
	p_press(form);
	p_len(form, j, forma);
	p_specifer(form);
	choose_type(form);
	return (form->ret_nb);
}
