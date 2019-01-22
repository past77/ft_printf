/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:04:52 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 17:04:54 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_write_minus(t_struc *form, intmax_t num)
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if (num < 0)
		i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		ft_write_dig(form, num);
		ft_memset(string, ' ', form->width - i);
		write(1, string, form->width - i);
		free(string);
	}
	else
		ft_write_dig(form, num);
	return(0);
} 	

void	*ft_write_common(t_struc *form, intmax_t num)
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if (num > 0 || num < 0)
		i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		ft_write_dig_pl(form, num);
		ft_memset(string, ' ', form->width - i);
		write(1, string, form->width - i);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);

	return(0);
}

void	*ft_write_zero(t_struc *form, intmax_t num)
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if  (num < 0 || num > 0)
		i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		if (num > 0)
			form->ret_nb += write(1, "+", 1);
		else
			form->ret_nb += write(1, "-", 1);
		ft_memset(string, '0', form->width - i);
		write(1, string, form->width - i);
		ft_write_u(form, num);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);
	return(0);
}
void	*ft_write_space_zero(t_struc *form, intmax_t num)
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if (num > 0 || num < 0)
		i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		if(num > 0)
			form->ret_nb += write(1, " ", 1);
		else
			form->ret_nb += write(1, "-", 1);
		ft_memset(string, '0', form->width - i);
		write(1, string, form->width - i);
		ft_write_u(form, num);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);
	return(0);
}

void	*ft_write_space_minus(t_struc *form, intmax_t num)
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if (num > 0 || num < 0)
			i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		ft_write_dig(form, num);
		ft_memset(string, ' ', form->width - i);
		write(1, string, form->width - i);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);
	return(0);
}
