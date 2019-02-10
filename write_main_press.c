/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_press_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:11:12 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/23 12:11:14 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*pt_precision(t_struc *form, intmax_t num)
{
	int		i;
	int		j;
	char	*string;
	int		wi;
	int		pr;

	pr = form->press;
	wi = form->width;
	i = 0;
	string = NULL;
	j = len_of_nbr(num);
	if (pr > wi || wi == 0 || (pr == wi && pr > (int)j))
		ft_owidth_p(form, num);
	else if (pr < wi && form->minus == '\0' && form->plus != '+')
		ft_lesspres(form, num);
	else if (form->plus == '+' && form->minus == '-')
		ft_compress(form, num, j);
	else if (form->minus == '-' && form->width > 0)
		ft_presm(form, num, j, i);
	else if (form->plus == '+' && form->width > 0)
		ft_prespl(form, num, i, j);
	else if (form->press == form->width)
		ft_write_dig(form, num);
	return (0);
}

void		*ft_ret(t_struc *form, intmax_t num)
{
	char	*str;

	if (num == 0 && form->width == 0)
		return (form);
	else if (num == 0 && form->width != 0)
	{
		if (!(str = ft_strnew(form->width)))
			exit(-1);
		ft_memset(str, ' ', form->width);
		form->ret_nb += write(1, str, form->width);
	}
	else
		ft_write_dig(form, num);
	return (0);
}

void		*ft_owidth_p(t_struc *form, intmax_t num)
{
	char	*string;
	int		i;

	i = len_of_nbr(num);
	if ((form->press - i) > 0)
	{
		form->ret_nb += form->press - i;
		if ((string = ft_strnew(form->press - i)) == NULL)
			exit(-1);
		if (num < 0)
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
	return (0);
}

void		*ft_lesspres(t_struc *form, intmax_t num)
{
	size_t	i;
	size_t	j;
	char	*fa;
	char	*sol;

	if (num < 0)
		i = ((size_t)form->width - 1);
	else
		i = (size_t)form->width;
	j = 0;
	fa = ft_itoa((int)num);
	sol = (char*)ft_memalloc(i - len_of_nbr(num) + 1);
	while (j < i - len_of_nbr(num))
		sol[j++] = (form->zero == '0' ? '0' : ' ');
	sol[j] = '\0';
	if (form->minus == '-' || form->press >= (int)len_of_nbr(num))
		zero(form, num);
	else
	{
		form->help = ft_strjoin(sol, fa);
		form->ret_nb += write(1, form->help, ft_strlen(form->help));
	}
	free(sol);
	free(fa);
	return (0);
}
