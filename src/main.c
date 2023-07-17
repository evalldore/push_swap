/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/17 02:39:44 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool validate_arg(char *arg)
{
	char	*c;

	c = arg;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (false);
		c++;
	}
	return (true);
}

static bool	pushswap_init(t_pushswap *ps, int argc, char **argv)
{
	t_list	*node;
	int		*num;

	ps->a = NULL;
	ps->b = NULL;
	ps->c = NULL;
	ps->num = argc - 1;
	while (*argv)
	{
		if (!validate_arg(*argv))
			return (false);
		num = malloc(sizeof(int));
		if (!num)
			return (false);
		*num = ft_atoi(*argv++);
		node = ft_lstnew(num);
		if (!node)
			return (false);
		ft_lstadd_back(&(ps->a), node);
		node = ft_lstnew(num);
		if (!node)
			return (false);
		ft_lstadd_back(&(ps->c), node);
	}
	return (true);
}

static void pushswap_clean(t_pushswap *ps)
{
	ft_lstclear(&ps->c, NULL);
	ft_lstclear(&ps->a, &free);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (pushswap_init(&ps, argc, &argv[1]))
	{
		assign_index(ps.c);
		sort(&ps);
	}
	else
		ft_printf("Error\n");
	pushswap_clean(&ps);
	return (EXIT_SUCCESS);
}
