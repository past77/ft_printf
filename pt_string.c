/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:02:34 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 13:02:35 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(const char *str, size_t i)
{
	char	*str1;
	size_t	n;

	n = 0;
	if (!(str1 = (char *)malloc(sizeof(*str1) * (i + 1))))
		return (NULL);
	while (str[n] && i > n)
	{
		str1[n] = str[n];
		n++;
	}
	str1[n] = '\0';
	return (str1);
}

char		*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(src);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

t_struc		*ft_separete_str(t_struc *form, char *str)
{
	if (form->press >= 0 && str != '\0')
		str = ft_strndup(str, form->press);
	else if (form->press == -1 && str)
		str = ft_strdup(str);
	else if (form->press == -1 && !str)
		str = ft_strdup("(null)");
	else if (form->press >= 0 && !str)
		str = ft_strndup("(null)", form->press);
	form->ret_nb += ft_strlen(str);
	if (form->zero == '0' && form->minus != '-')
		pr_str(form, '0', form->width - ft_strlen(str));
	else if (form->minus != '-')
		pr_str(form, ' ', form->width - ft_strlen(str));
	ft_putstr(str);
	if (form->minus == '-')
		pr_str(form, ' ', form->width - ft_strlen(str));
	free(str);
	return (form);
}

t_struc		*pt_string(t_struc *form)
{
	char	*str;

	str = va_arg(form->ap, char *);
	ft_separete_str(form, str);
	return (form);
}

void		pr_str(t_struc *form, char cha, int i)
{
	char	*s;

	if (i > 0)
	{
		if (!(s = ft_strnew(i)))
			exit(-1);
		ft_memset(s, cha, i);
		form->ret_nb += write(1, s, i);
		free(s);
	}
}
