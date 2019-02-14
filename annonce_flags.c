/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annonce_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:49:55 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 16:49:57 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struc			*p_converse(t_struc *form)
{
	int			j;

	j = 0;
	while (form->sign[j] != '\0')
	{
		while (form->sign[j] == form->format[form->i])
		{
			if (form->format[form->i] == '+' && form->i++)
				form->plus = '+';
			else if (form->format[form->i] == '-' && form->i++)
				form->minus = '-';
			else if (form->format[form->i] == '0' && form->i++)
				form->zero = '0';
			else if (form->format[form->i] == '#' && form->i++)
				form->hash = '#';
			else if (form->format[form->i] == ' ' && form->i++)
				form->space = ' ';
			j = 0;
		}
		j++;
	}
	return (form);
}

t_struc			*p_specifer(t_struc *form)
{
	int			j;

	j = 0;
	while (form->specificators[j] != '\0')
	{
		if (form->specificators[j] == form->format[form->i])
			form->s_flag = form->specificators[j];
		j++;
	}
	return (form);
}

t_struc			*p_len(t_struc *form, int j, char *forma)
{
	forma = form->format;
	while (form->lens[j] != '\0')
	{
		while (form->lens[j] == form->format[form->i])
		{
			if (forma[form->i] == 'l' && forma[form->i + 1] == 'l')
				form->ll = 1;
			else if (forma[form->i] == 'l' && forma[form->i + 1] != 'l')
				form->l = 1;
			else if (forma[form->i] == 'L' && forma[form->i + 1] != 'L')
				form->lo = 1;
			else if (forma[form->i] == 'h' && forma[form->i + 1] == 'h')
				form->hh = 1;
			else if (forma[form->i] == 'h' && forma[form->i + 1] != 'h')
				form->h = 1;
			else if (form->format[form->i] == 'j')
				form->j = 1;
			else if (form->format[form->i] == 'z')
				form->z = 1;
			form->i++;
		}
		j++;
	}
	return (form);
}

t_struc			*p_press(t_struc *form)
{
	while (form->format[form->i] == '.')
	{
		form->i++;
		form->press = 0;
	}
	if (ft_isdigit(form->format[form->i]))
	{
		form->press = ft_atoi(&form->format[form->i]);
		while (ft_isdigit(form->format[form->i]))
			form->i++;
	}
	return (form);
}

t_struc			*p_width(t_struc *form)
{
	if (ft_isdigit(form->format[form->i]))
	{
		form->width = ft_atoi(&form->format[form->i]);
		while (ft_isdigit(form->format[form->i]))
			form->i++;
	}
	return (form);
}
