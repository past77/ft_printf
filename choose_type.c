/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:01:22 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/22 17:01:23 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_struc	*choose_type(t_struc *form)
{ 
	if (form->s_flag == '%')
		pt_persent(form);
	else if (form->s_flag == 'c')
		pt_char(form);
	else if (form->s_flag == 'd' || form->s_flag == 'i')
		pt_digit(form);
	else if (form->s_flag == 's')
		pt_string(form);
	else if (form->s_flag == 'x' || form->s_form == 'X')
		pt_sixteen(form);
	return(form); 
}
