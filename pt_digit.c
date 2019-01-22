/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:22:45 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/12 18:22:46 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static intmax_t		do_number(t_struc *form)
{
	intmax_t num;

	if (form->hh == 1)
		num = (char)va_arg(form->ap, int);
	else if (form->h == 1)
		num = (short)va_arg(form->ap, int);
	else if (form->ll == 1)
		num = va_arg(form->ap, long long);
	else if (form->l == 1)
		num = va_arg(form->ap, long);
	else if (form->j == 1)
		num = va_arg(form->ap, uintmax_t);
	else if (form->z == 1)
		num = va_arg(form->ap, size_t);
	else
		num = (int)va_arg(form->ap, int);
	return (num);
}

t_struc		*choose_index(t_struc *form, intmax_t num)
{
	if (form->plus == '+' && form->width == 0 && form->minus != '-')
		ft_write_dig_pl(form, num);
	else if (form->minus == '-' && form->width > 0 && form->plus != '+' && form->space != ' ')
		ft_write_minus(form, num); 
	else if (form->plus == '+' && form->minus == '-' && form->width > 0)
		ft_write_common(form, num);
	else if (form->plus == '+' && form->zero == '0' && form->width > 0)
		ft_write_zero(form, num);
	else if (form->space == ' ' && form->zero == '0' && form->width > 0 && form->minus != '-')
		ft_write_space_zero(form, num);
	else if (form->space == ' ' && form->minus == '-' && form->width > 0)
		ft_write_space_minus(form, num);
	else if (form->width > 0 && form->plus == '+')
		ft_write_pluswidth(form, num);
	else if (form->width > 0 && form->zero == '0' && form->plus != '+')
		ft_write_owidth(form, num);
	else if (form->width > 0) 
		ft_write_width(form, num);
	else
		ft_write_other(form, num);
	return (form);
}

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

void *ft_lesspres(t_struc *form, intmax_t num, int i, int j, char *string)
{
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
	return (0);
}
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

	if (num < 0)
		write(1, "-", 1);
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

void	*pt_press_1(t_struc *form, intmax_t num)
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
		i = form->width - form->press;
		ft_lesspres(form, num, i, j, string);
	}
	else if (form->plus == '+' && form->minus == '-')
	{
		ft_compress(form, num, j);
	}
	else if (form->minus == '-' && form->width > 0)
		ft_presm(form, num, j, i);
	else if (form->plus == '+' && form->width > 0)
		ft_prespl(form,num, i, j);
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
t_struc		*work_w_press(t_struc *form, intmax_t num)
{

	if ((form->press == 0 && form->width == 0) || (form->press == 0 && form->width != 0))
		ft_ret(form, num);
	else if(form->width >= 0)
		pt_press_1(form, num);
	return (form);
}



t_struc		*pt_digit(t_struc *form)
{
	intmax_t num;
	
	num = do_number(form);
	if (form->press >= 0)
		work_w_press(form, num);
	else
		choose_index(form, num);
	return(form);
}






































