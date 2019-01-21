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

int 	ft_putchar (char c)
{
	write(1, &c, 1);
	return (1);
}


int				ft_printf(const char *format, ...)
{
	t_struc		*form;
	char		*frmt;
	int 		revenir;

	frmt = (char *)format;
	form = (t_struc*)malloc(sizeof(t_struc));
	if (!form)
		return (-1);
	form->format = frmt;
	form = ft_init_li(form);
		if (format)
		{
			va_start(form->ap, format);
			form->ret_nb = ft_parse_f(form);
			va_end(form->ap);
		}
		revenir = form->ret_nb;
		form->ret_nb = 0;
		free(form);
	return (revenir);
}

t_struc	*ft_init_li(t_struc *form)
{
	form->len = 0;
	form->i = 0;

	return(form);
}		

int		ft_parse_f(t_struc *form)
{
	if (ft_strcmp(form->format ,"%") == 0 || form->format == '\0')
		return (0);
	while (form->format[form->i] != '\0')
	{
		if(form->format[form->i] == '%')
			{
				ft_init_other(form);
				ft_separ_fnc(form);
			}
		else //(form->ret_nb >= 0)
		{
			ft_putchar(form->format[form->i]);
			form->ret_nb++;
		}
		//if(form->format[form->i] != '\0') 
			form->i++;
	}
	return(form->ret_nb);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int	ft_atoi(const char *str)
{
	int				i;
	long long int	minus;
	long long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
	&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
	&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		res = (res * 10) + (long long int)str[i++] - '0';
	}
	return (res * minus);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strnew(len);
	if (str == NULL || !s)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char *s1;

	s1 = s;
	ft_memset(s1, 0, n);
}

void	*ft_memalloc(size_t size)
{
	char	*mal;

	mal = malloc(size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, size);
	return (mal);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c1;
	char			*b1;
	int				i;

	c1 = (unsigned char)c;
	b1 = b;
	i = 0;
	while (len > 0)
	{
		*b1 = c1;
		b1++;
		len--;
	}
	return (b);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}


t_struc	*ft_init_other(t_struc *form)
{
	form->specificators = "idscuoxbpDSCUX%";
	form->sign = "-+# 0";
	form->lens = "lhzj";
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
	form->fd = 1;
	return (form);
}
int ft_separ_fnc(t_struc *form)
{
	form->i++;
	p_converse(form);
	p_width(form);
	p_press(form);
	p_len(form);
	p_specifer(form);
	choose_type(form);
	return (form->ret_nb); //!!!!!!!!!!!!!!!!!!!
}

t_struc		*p_converse(t_struc *form)
{
	int j;

	j = 0;
	while(form->sign[j] != '\0')
	{
		while(form->sign[j] == form->format[form->i])
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

t_struc	*p_specifer(t_struc *form)
{
	int j;

	j = 0;
	while (form->specificators[j] != '\0')
	{
		if (form->specificators[j] == form->format[form->i])
			form->s_flag = form->specificators[j];
		j++;
	}
	return (form);
}

t_struc			*p_len(t_struc *form)
{
	int j;

	j = 0;
	while(form->lens[j] != '\0')
	{
		while(form->lens[j] == form->format[form->i])
		{
			if (form->format[form->i] == 'l' && form->format[form->i + 1] == 'l')
				form->ll = 1;
			else if (form->format[form->i] == 'l' && form->format[form->i + 1] != 'l')
				form->l = 1;
			else if (form->format[form->i] == 'h' && form->format[form->i + 1] == 'h')
				form->hh = 1;
			else if (form->format[form->i] == 'h' && form->format[form->i + 1] != 'h')
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

t_struc		*p_press(t_struc *form)
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

t_struc		*p_width(t_struc *form)
{
	if (ft_isdigit(form->format[form->i]))
	{
		form->width = ft_atoi(&form->format[form->i]);
		while (ft_isdigit(form->format[form->i]))
			form->i++;
	}
	return (form);
} 

t_struc	*choose_type(t_struc *form)
{ 
	if (form->s_flag == '%')
		pt_persent(form);
	else if (form->s_flag == 'c')
		pt_char(form);
	else if (form->s_flag == 'd' || form->s_flag == 'i')
		pt_digit(form);
	//printf("press : %d\n",form->press);
//printf("spec : %c\n", form->s_flag);
   /* printf("width : %d\n",form->width);
    printf("press : %d\n",form->press);
    printf("spec : %c\n", form->s_flag);
     printf("l : %i\n", form->l);
      printf("ll : %d\n", form->ll);
      printf("hh : %d\n", form->hh);
      printf("h : %d\n", form->h);
       printf("plus : %c\n",form->plus);

	if (form->s_flag == 'd')
	{
		ft_putchar(1);
	} 

	//else if (form->s_flag == 'c')
		//ft_putchar() */
	return (form); 
}

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
/*
t_struc		*pt_digit(t_struc *form)
{
	intmax n
}
*/














/*
int	ft_printf(char *format, ...)
{
	va_list cnv;
	int rtr;
	
	rtr = 0;
	
	if (format)
	{
		va_start(cnv, format);
		if (*format == '%')
		{
			rtr = rtr + ft_specificator(cnv, format[i+1]);
			format++;
		}
		else
			rtr += ft_putchar(format);
		format++;
		va_end(cnv);
	}
	return (rtr);
}



	rtr = 0;
	while (*str)
	{
		//if (*str == '%')

	
			str++;
	}
	return(rtr);
*/