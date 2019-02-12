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
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_struc
{
	char		*help;
	va_list		ap;
	size_t		i;
	char		*sign;
	char		space;
	char		zero;
	char		minus;
	char		plus;
	char		hash;
	int			width;
	int			L;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			j;
	int			z;
	int			press;
	int			ret_nb;
	char		*format;
	int			len;
	char		*lens;
	char		*specificators;
	int			index;
	char		s_flag;
}				t_struc;

int				ft_printf(const char *format, ...);

t_struc			*ft_init_li(t_struc *form);
t_struc			parse_a(t_struc *form);
int				ft_parse_f(t_struc *form);
t_struc			*ft_init_other(t_struc *form);
t_struc			*p_specifer(t_struc *form);
t_struc			*choose_type(t_struc *form);
t_struc			*p_converse(t_struc *form);
t_struc			*p_width(t_struc *form);
t_struc			*p_press(t_struc *form);
int				ft_separ_fnc(t_struc *form);
t_struc			*p_len(t_struc *form, int j, char *forma);
t_struc			*pt_char(t_struc *form);
void			*pt_width_c(t_struc *form, char c, int a);
t_struc			*pt_persent(t_struc *form);
t_struc			*pt_digit(t_struc *form);
t_struc			*choose_index(t_struc *form, intmax_t num);

void			ft_write_u(t_struc *form, intmax_t num);
void			ft_write_dig_pl(t_struc *form, intmax_t num);
void			ft_write_dig(t_struc *form, intmax_t num);

void			*ft_write_minus(t_struc *form, intmax_t num);
void			*ft_write_common(t_struc *form, intmax_t num);
void			*ft_write_zero(t_struc *form, intmax_t num);
void			*ft_write_space_zero(t_struc *form, intmax_t num);
void			*ft_write_space_minus(t_struc *form, intmax_t num);
void			*ft_write_width(t_struc *form, intmax_t num);
void			*ft_write_pluswidth(t_struc *form, intmax_t num);
void			*ft_write_owidth(t_struc *form, intmax_t num);
void			*ft_write_other(t_struc *form, intmax_t num);
void			*pt_precision(t_struc *form, intmax_t num);
void			*ft_ret(t_struc *form, intmax_t num);
void			*ft_prespl(t_struc *form, intmax_t num, int i, int j);
void			*ft_presm(t_struc *form, intmax_t num, int i, int j);
void			*ft_compress(t_struc *form, intmax_t num, int i);
void			*ft_lesspres(t_struc *form, intmax_t num);
t_struc			*work_w_press(t_struc *form, intmax_t num);
void			*ft_owidth_p(t_struc *form, intmax_t num);
void			helpzero(t_struc *form, intmax_t num, int i, int j);

void			*zero(t_struc *form, intmax_t num);
t_struc			*pt_string(t_struc *form);
void			pr_str(t_struc *form, char cha, int i);

char			*ft_lit_base(intmax_t num, int base, t_struc *form);
t_struc			*ft_bases(t_struc *form, int base);
void			*choose_signs(t_struc *form);

void			fill_hash(t_struc *form);
void			fill_width(t_struc *form);
void			fill_zero(t_struc *form);

char			*ignore_zero(t_struc *form, size_t d);
uintmax_t		do_unsign_nb(t_struc *form);
t_struc			*parse_exclusion(t_struc *form, uintmax_t val);
t_struc			*excl(t_struc *form, uintmax_t val, int i);

char			*ft_ptoa(unsigned long n);
int				pt_pointer(t_struc *form);
void			fill_uni(t_struc *form, char a, int i);
t_struc			*prnt_p(t_struc *form, char *p, int i);

t_struc			*pr_float(t_struc *form);
void			sings_flt(t_struc *form, long double val);
void			make_chaos(t_struc *form, long double val);
char			*ft_exeptiontoa(double n);



size_t			ft_strlen(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_putchar(char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnew(size_t size);
size_t			len_of_nbr(intmax_t nb);
void			*ft_memalloc(size_t size);
char			*ft_strndup(const char *str, size_t i);
void			ft_putstr(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_itoa(int n);
char			*ft_longtoa(long n)

#endif
