/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:51:56 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 17:51:59 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	*ft_owidth_p(t_struc *form, intmax_t num) // write_width
{
	char *string;
	int i;

	i = len_of_nbr(num);
	if ((form->press - i) > 0)
	{
		form->ret_nb += form->press - i;
		if ((string = ft_strnew(form->press - i)) == NULL)
			exit (-1);
		if(num < 0)
			form->ret_nb += write(1, "-", 1);
		ft_memset(string, '0', form->press - i);
		write(1, string, form->press - i);
		ft_write_u(form, num);
		free(string);
	}
	else if (form->width > 0)
		ft_write_dig_pl(form, num);
	else
		ft_write_dig(form, num);
	return(0);
}

void *ft_lesspres(t_struc *form, intmax_t num)
{
	size_t		i;
	size_t		j;
	int		u;
	char		*fa;
	char		*sol;
	//char		*string;
	//int n;
	if (num < 0)
		i = ((size_t)form->width - 1);
	else
		i = (size_t)form->width;
	j = 0;
	u = (int)num;
	fa = ft_itoa(u);
	sol = (char*)ft_memalloc(i - len_of_nbr(num) + 1);
	while (j < i - len_of_nbr(num))
		sol[j++] = (form->zero == '0' ? '0' : ' ');
	sol[j] = '\0';
	//n = printf("SOL |%s|\n",sol );
	//printf("N%d", n);
	if (form->minus == '-' || form->width - form->press <= len_of_nbr(num))
	{
		zero(form, num);
		if (form->zero == '0')
			sol = ignore_zero(form, i);
	}
	else 
		form->help = ft_strjoin(sol, fa);

	free(sol);
	free(fa);
	return (0);
}

void 	*zero(t_struc *form, intmax_t num)
{
	//printf("%s\n", "tolyan kalyan");
	int j;
	int i = 0;
	i = form->width - form->press;
	j = len_of_nbr(num);
	char	*str;
	char *spaces;
	
	form->ret_nb += i + form->press - j;
	if ((form->width - j) > 0)
	{
		if (!(str = ft_strnew(form->press - j)) || !(spaces = ft_strnew(i - 1)))
			exit (-1);
		ft_memset(spaces, ' ',  i);
		if(num < 0)
		{
			ft_memset(spaces, ' ',  i - 1);
			write(1, spaces, i - 1);
			write(1, "-", 1);
		}
		else
			write(1, spaces, i);
		ft_memset(str, '0', form->press - j);
		write(1, str, form->press - j);
		ft_write_u(form, num);
		free(str);
		free(spaces);
	}
	else
		ft_write_dig_pl(form, num);
	return (0);
}
/*
	char *spaces;
	
	form->ret_nb += i + form->press - j;
	if ((form->width - j) > 0)
	{
		if (!(string = ft_strnew(form->press - j)) || !(spaces = ft_strnew(i - 1)))
			exit (-1);
		ft_memset(spaces, ' ',  i);
		if(num < 0)
		{
			ft_memset(spaces, ' ',  i - 1);
			write(1, spaces, i - 1);
			write(1, "-", 1);
		}
		else
			write(1, spaces, i);
		ft_memset(string, '0', form->press - j);
		write(1, string, form->press - j);
		ft_write_u(form, num);
		free(string);
		free(spaces);
	}
	else
		ft_write_dig_pl(form, num);
	return (0);*/

void		*ft_presm(t_struc *form,intmax_t num, int i, int j)
{
	char *string;

	if (num < 0)
		form->ret_nb += write(1, "-", 1);
	if (form->press > i)
	{
		j = form->press - i;
		form->ret_nb += write(1, "0", j);
		i++;
	}
	if (num < 0)
		i++;
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - i)) == NULL)
			exit (-1);
		ft_write_u(form, num);
		ft_memset(string, ' ', form->width - i);
		write(1, string, form->width - i);
		free(string);
	}
	else
		ft_write_dig(form, num);
	return(0);
}

void	*ft_prespl(t_struc *form, intmax_t num, int j, int i)
{
	char *string;
	char *str;
	
	j = form->press - i;
	
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if (!(string = ft_strnew(form->width - i - j - 1)) || !(str = ft_strnew(j)))
			exit (-1);
		ft_memset(string, ' ', form->width - i - j - 1);
		write(1, string, form->width - i - j - 1);
		if (num < 0)
			 write(1, "-", 1);
		else
			write(1, "+", 1);
		ft_memset(str, '0', j);
		write(1, str, j);
		ft_write_u(form, num);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);
	return(0);
}
void	*ft_compress(t_struc *form, intmax_t num, int i)
{
	char *string;
	char *str;
	//staic char pr[];

	if (num < 0) //////  pr = (num < 0) ? '-' : '+';
		write(1, "-", 1);// write (1, &pr, 1);
	else
		 write(1, "+", 1);
	if (form->press > i)
	{
		if ((str = ft_strnew(form->press - i)) == NULL)
			exit (-1);
		ft_memset(str, '0', form->press - i);
		 write(1, str, form->press - i);
	}
	if ((form->width - i) > 0)
	{
		form->ret_nb += form->width - i;
		if ((string = ft_strnew(form->width - form->press - 1)) == NULL)
			exit (-1);
		ft_write_u(form, num);
		ft_memset(string, ' ', form->width - form->press - 1);
		write(1, string, form->width - form->press - 1);
		free(string);
	}
	else
		ft_write_dig_pl(form, num);
	return(0);
}
