/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/05 18:35:05 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushswap_init(t_pushswap *ps, char **argv)
{
	int		*num;

	ps->a = NULL;
	ps->b = NULL;
	ps->c = NULL;
	while (*argv)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			ft_lstclear(&(ps->a), free);
			return ;
		}
		*num = ft_atoi(*argv);
		ft_lstadd_back(&(ps->a), ft_lstnew(num));
		ft_lstadd_back(&(ps->c), ft_lstnew(num));
		argv++;
	}
	assign_index(ps->c);
}

/*static void	print_stack(char c, t_list *stack)
{
	int	*num;

	printf("--------%c--------\n", c);
	while (stack)
	{
		num = stack->content;
		ft_printf("\t%d\n", *num);
		stack = stack->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	pushswap_init(&ps, &argv[1]);
	sort(&ps, argc);
	//print_stack('a', ps.a);
	return (EXIT_SUCCESS);
}
