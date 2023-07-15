/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/15 06:30:41 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushswap_init(t_pushswap *ps, int argc, char **argv)
{
	int		*num;

	ps->a = NULL;
	ps->b = NULL;
	ps->c = NULL;
	ps->num = argc - 1;
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

static void pushswap_clean(t_pushswap *ps)
{
	ft_lstclear(&ps->c, NULL);
	ft_lstclear(&ps->a, &free);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	pushswap_init(&ps, argc, &argv[1]);
	sort(&ps);
	pushswap_clean(&ps);
	return (EXIT_SUCCESS);
}
