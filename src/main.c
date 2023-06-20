/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/20 01:23:32 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	pushswap_init(t_pushswap *ps, char **argv)
{
	int		*num;

	ps->a = NULL;
	ps->b = NULL;
	while (*argv)
	{
		num = malloc(sizeof(int *));
		if (!num)
		{
			ft_lstclear(&(ps->a), free);
			return ;
		}
		*num = ft_atoi(*argv);
		ft_lstadd_back(&(ps->a), ft_lstnew(num));
		argv++;
	}
}

/*static void	print_stack(char c, t_list *stack)
{
	printf("--------%c--------\n", c);
	while (stack)
	{
		printf("\t%d\n", *(int *)(stack->content));
		stack = stack->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	(void)argc;
	pushswap_init(&ps, &argv[1]);
	sort(&ps);
	//print_stack('a', ps.a);
	return (EXIT_SUCCESS);
}
