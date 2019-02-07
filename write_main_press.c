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

void	*pt_precision(t_struc *form, intmax_t num)
{
	int i;
	int j;
	char *string;

	i = 0;
	string = NULL;
	j = len_of_nbr(num);
	if (form->press > form->width || form->width == 0)
		ft_owidth_p(form, num);
	else if (form->press < form->width && form->minus == '\0' && form->plus != '+')
	{
		ft_lesspres(form, num);
		form->ret_nb += write(1, form->help, ft_strlen(form->help));
	}
	else if (form->plus == '+' && form->minus == '-')
	{
		ft_compress(form, num, j);
	}
	else if (form->minus == '-' && form->width > 0)
		ft_presm(form, num, j, i);
	else if (form->plus == '+' && form->width > 0)
		ft_prespl(form,num, i, j);
	else if (form->press == form->width)
		ft_write_dig(form, num);
		//{
		//	printf("%s\n", "try4");	
		//	fill_width(form);
			//printf("%s\n", "try4");	
		//}
	return (0);
}

void	*ft_ret(t_struc *form, intmax_t num)
{
	char *str;

	if (num == 0 && form->width == 0)
		return (form);
	else if (num == 0 && form->width != 0)
	{
		if (!(str = ft_strnew(form->width)))
			exit (-1);
		ft_memset(str, ' ', form->width);
	form->ret_nb +=	write(1, str, form->width);
	}
	else
		ft_write_dig(form, num);
	return (0);
}
