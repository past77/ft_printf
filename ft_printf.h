/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:11:52 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/11 16:22:25 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
//# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h> 
 
typedef struct	s_struc
{
	va_list	ap;
	size_t 	i;
	char	*sign;
	char	space;
	char	zero;
	char	minus;
	char	plus;
	char	hash;
	int		width;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int	j;
	int 	z;
	int		press;
	int		ret_nb;
	char 	*format;
	int 	len;
	char 	*lens;
	char 	*specificators;
	int 	index;
	int 	fd;
	//char 	converse[6];
	//char 	ar_flag[2];
	char 	s_flag;
}				t_struc;

int			ft_printf(const char *format, ...);
//int			ft_specificator(va_list *ap, char *c);

t_struc		*ft_init_li(t_struc *form);
t_struc		parse_a(t_struc *form);
int 		ft_parse_f(t_struc *form);
t_struc		*ft_init_other(t_struc *form);
t_struc		*p_specifer(t_struc *form);
t_struc		*choose_type(t_struc *form);
t_struc		*p_converse(t_struc *form);
t_struc		*p_width(t_struc *form);
t_struc		*p_press(t_struc *form);
int 		ft_separ_fnc(t_struc *form);
t_struc		*p_len(t_struc *form);
t_struc		*pt_char(t_struc *form);
void 		*pt_width_c(t_struc *form, char c, int a);
t_struc		*pt_persent(t_struc *form);
t_struc		*pt_digit(t_struc *form);
t_struc		*choose_index(t_struc *form, intmax_t num);

void ft_write_u(t_struc *form, intmax_t num);
void ft_write_dig_pl(t_struc *form, intmax_t num);

void		*ft_write_minus(t_struc *form, intmax_t num);
void		*ft_write_common(t_struc *form, intmax_t num);
void		*ft_write_zero(t_struc *form, intmax_t num);
void		*ft_write_space_zero(t_struc *form, intmax_t num);
void		*ft_write_space_minus(t_struc *form, intmax_t num);
void		*ft_write_width(t_struc *form, intmax_t num);
void		*ft_write_pluswidth(t_struc *form, intmax_t num);
void		*ft_write_owidth(t_struc *form, intmax_t num);
void		*ft_write_other(t_struc *form, intmax_t num);
void		*pt_press_1(t_struc *form, intmax_t num);
void		*ft_ret(t_struc *form, intmax_t num);
void	*ft_prespl(t_struc *form, intmax_t num, int i, int j);
void		*ft_presm(t_struc *form,intmax_t num, int i, int j);
void	*ft_compress(t_struc *form, intmax_t num, int i);
void 		*ft_lesspres(t_struc *form, intmax_t num, int i, int j, char *string);
t_struc		*work_w_press(t_struc *form, intmax_t num);
//string
t_struc		*pt_string(t_struc *form);
void		pr_str(t_struc *form, char cha, int i);


char		*ft_llongitoa(intmax_t num);



size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
int 		ft_isdigit(int c);
int			ft_putchar(char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strnew(size_t size);
size_t		len_of_nbr(intmax_t nb);
void		*ft_memalloc(size_t size);
char		*ft_strndup(const char *str, size_t i);
void		ft_putstr(const char *str);

char	*ft_itoa(intmax_t num);
//int	ft_putchar_fd(char c);//, int fd);
void ft_write_dig(t_struc *form, intmax_t num);


/*int			ft_putstr(char *str);
size_t		ft_strlen(const char *str);
int 		ft_putnbr(int n);

int			pt_onechar(va_list *ap);
char		pt_string(va_list *ap);
int			pt_integer(va_list *ap);

int			ft_parse(va_list *ap, char **str);
char		*check_format(char *str, t_struc *format);
t_struc 	save_flags(char *str, int i);
int			plus_flag(char *s);
//int			minus_flag(char *s);
//int			space_flag(char *, int minus, int plus);
int			sign_converse(va_list *ap, char **str, t_struc form);
int	pt_nb(va_list *ap, t_struc form);

char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
void	*ft_memset(void *b, int c, size_t len);
*/
#endif
