/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:23:11 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/01/11 18:25:12 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{ 
	int x = 10;
	int y;

	ft_printf("............................................................MY PRINTF:\n");
	//ft_printf("\n");
	//ft_printf("%%%kfcuk\n");
	//ft_printf("%c\n", 'R');
	//ft_printf("%s\n", "printstring, yoyoyo");
	//ft_printf("%d\n", 1);
		
	// ft_printf("%5c", 'f');
	//y = ft_printf("%p", -42);
	//y = ft_printf("%#6o", 2500);
	y = ft_printf("%-.2s is a string", "this");   


	/*
		
			ft_printf("my: %--3%\n");
			ft_printf("my: %-%\n");
			ft_printf("my: %05%\n");
			ft_printf("my: %5%\n");
	*/			
				//ft_printf("my: %-c ... %c\n", 'Fcuk', 'you');
				//ft_printf("my: %05c .. %c\n", 'Fcuk', 'you');
				//ft_printf("my: %5c . %c\n", 'Fcuk', 'you');


	//ft_printf("%d %d %d", 42, 43, 44);
	//ft_printf("%+5.8lhd\n", 567);

	//ft_printf("%523d\n", -2);
	//ft_printf("%s %s\n", "test", "test2");
	
	printf("\nWMY: %d\n", y );
	
	//ft_printf("|------------------------------------|\nend of my printf\n|------------------------------------|");
	//ft_printf("\n");
	
	printf("%s\n", "............................................................ORIGINAL:" );
	

	//printf("DD");
	//printf("%*s", "d", '\n');
	/* printf("%%%kfcuk\n");
	printf("%c\n", 'R');
	printf("%s\n", "printstring, yoyoyo");
	//printf("%d\n", 2247483648);
	printf("%s %s\n", "test", "test2");
	//printf("%+ld\n", 0);
	*/
		//printf("%*c", 3, '\r');
	//printf("%%\n");
	//printf("%s\n", "d");
	//printf("or: %-2c\n", 'Fcuk');
	int i;
	//i = printf("my: %c\n %c\n" , '3', '4');
	i = printf("%-.2s is a string", "this");
	//printf("% d\n", -42);
	//printf("%5c", 'f');
//	i = printf("my: %+d %+d\n%-5d\n" , -3384747, 4, 42);
	
	//printf("or: %d %d\n", 233, 12);
		/*printf("or: %--3%\n");
		printf("or: %-%\n");
		printf("or: %05%\n");
		printf("or: %5%\n");
*/
			//printf("my: %-c ... %c\n", 'Fcuk', 'you');
			//printf("my: %05c .. %c\n", 'Fcuk', 'you');
			//printf("my: %5c . %c\n", 'Fcuk', 'you');

printf("\nWOR: %d\n", i);

	//printf("%ld\n", 3394994430955996965);
 //printf("%5...2s\n",  "st");
}
