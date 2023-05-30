/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 21:38:29 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	pushswap_init(t_pushswap *ps, char **argv)
{
	int		*num;

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

static void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", *(int *)(stack->content));
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	(void)argc;
	ps.a = NULL;
	ps.b = NULL;
	pushswap_init(&ps, &argv[1]);
	print_stack(ps.a);
	pb(&ps);
	print_stack(ps.a);
	print_stack(ps.b);
	return (EXIT_SUCCESS);
}
