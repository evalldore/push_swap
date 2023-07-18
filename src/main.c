/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/18 19:35:21 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool validate_arg(char *arg)
{
	char	*c;

	if (*arg == '-' || *arg == '+')
		arg++;
	c = arg;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (false);
		c++;
	}
	return (true);
}

static bool	validate_int(int64_t integer)
{
	if (integer > INT32_MAX)
		return (false);
	if (integer < INT32_MIN)
		return (false);
	return (true);
}

static uint32_t	pushswap_init(t_pushswap *ps, char **argv)
{
	t_list		*node;
	int64_t		integer;
	int			*num;

	while (*argv)
	{
		if (!validate_arg(*argv))
			return (ERROR_NAN);
		integer = ft_atoi(*argv++);
		if (!validate_int(integer))
			return (ERROR_OOB);
		num = malloc(sizeof(int));
		if (!num)
			return (ERROR_ALOC);
		*num = (int)integer;
		node = ft_lstnew(num);
		if (!node)
			return (ERROR_ALOC);
		ft_lstadd_back(&(ps->a), node);
		node = ft_lstnew(num);
		if (!node)
			return (ERROR_ALOC);
		ft_lstadd_back(&(ps->c), node);
	}
	return (ERROR_NONE);
}

static void pushswap_clean(t_pushswap *ps)
{
	ft_lstclear(&ps->c, NULL);
	ft_lstclear(&ps->a, &free);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;
	uint32_t	status;

	ps.a = NULL;
	ps.b = NULL;
	ps.c = NULL;
	ps.num = argc - 1;
	status = pushswap_init(&ps, &argv[1]);
	if (status == ERROR_NONE)
	{
		assign_index(ps.c);
		sort(&ps);
	}
	else if (status == ERROR_NAN)
		ft_printf("Error: Argument isnt a number\n");
	else if (status == ERROR_DUP)
		ft_printf("Error: Duplicated number\n");
	else if (status == ERROR_OOB)
		ft_printf("Error: Number overflows 32 bit integer\n");
	pushswap_clean(&ps);
	return (EXIT_SUCCESS);
}
