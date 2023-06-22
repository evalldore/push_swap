/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/22 04:42:46 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushswap_init(t_pushswap *ps, char **argv)
{
	t_num		*num;

	ps->a = NULL;
	ps->b = NULL;
	while (*argv)
	{
		num = malloc(sizeof(t_num));
		if (!num)
		{
			ft_lstclear(&(ps->a), free);
			return ;
		}
		num->num = ft_atoi(*argv);
		ft_lstadd_back(&(ps->a), ft_lstnew(num));
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	(void)argc;
	pushswap_init(&ps, &argv[1]);
	sort(&ps);
	//print_stack('a', ps.a);
	return (EXIT_SUCCESS);
}
