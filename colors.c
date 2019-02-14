/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:59:37 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/14 16:59:41 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_back_color(const char *format, t_struc *form)
{
	if (!ft_strncmp(format + form->i, "{bk-green}", 10))
	{
		ft_putstr("\x1B[42m\0");
		form->i += 10;
	}
	else if (!ft_strncmp(format + form->i, "{bk-red}", 8))
	{
		ft_putstr("\x1B[41m\0");
		form->i += 8;
	}
	else if (!ft_strncmp(format + form->i, "{bk-blue}", 9))
	{
		ft_putstr("\x1B[44m\0");
		form->i += 9;
	}
	else if (!ft_strncmp(format + form->i, "{bk-yellow}", 11))
	{
		ft_putstr("\x1B[43m\0");
		form->i += 11;
	}
	return ;
}

void		parse_standr_color(const char *format, t_struc *form)
{
	if (!ft_strncmp(format + form->i, "{white}", 7))
	{
		ft_putstr("\x1B[37m\0");
		form->i += 7;
	}
	else if (!ft_strncmp(format + form->i, "{yellow}", 8))
	{
		ft_putstr("\x1B[33m\0");
		form->i += 8;
	}
	else if (!ft_strncmp(format + form->i, "{red}", 5))
	{
		ft_putstr("\x1B[31m\0");
		form->i += 5;
	}
	else if (!ft_strncmp(format + form->i, "{green}", 7))
	{
		ft_putstr("\x1B[32m\0");
		form->i += 7;
	}
	else
		parse_back_color(format, form);
	return ;
}

void		parse_brackets(const char *format, t_struc *form)
{
	if (!ft_strncmp(format + form->i, "{n}", 5))
	{
		ft_putstr("\x1B[0m\0");
		form->i += 5;
		return ;
	}
	else if (!ft_strncmp(format + form->i, "{blue}", 6))
	{
		ft_putstr("\x1B[34m\0");
		form->i += 6;
	}
	else if (!ft_strncmp(format + form->i, "{magenta}", 9))
	{
		ft_putstr("\x1B[35m\0");
		form->i += 9;
	}
	else if (!ft_strncmp(format + form->i, "{cyan}", 6))
	{
		ft_putstr("\x1B[36m\0");
		form->i += 6;
	}
	else
		parse_standr_color(format, form);
	return ;
}
