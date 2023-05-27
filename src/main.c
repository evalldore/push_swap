/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/26 23:38:47 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	populate_list(t_list **list, char **argv)
{
	int		*num;

	while (*argv)
	{
		num = malloc(sizeof(int *));
		if (!num)
		{
			ft_lstclear(list, free);
			return ;
		}
		*num = ft_atoi(*argv);
		ft_lstadd_back(list, ft_lstnew(num));
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
	t_list	*a;
	t_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	populate_list(&a, &argv[1]);
	printf("-----A-----\n");
	print_stack(a);
	push(&b, &a);
	printf("-----B-----\n");
	print_stack(b);
	printf("-----A-----\n");
	print_stack(a);
	return (EXIT_SUCCESS);
}
