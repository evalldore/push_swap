/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:58:03 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 21:36:31 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	sa(t_pushswap *ps)
{
	swap(ps->a);
	ft_printf("sa\n");
}

void	sb(t_pushswap *ps)
{
	swap(ps->b);
	ft_printf("sb\n");
}

void	ss(t_pushswap *ps)
{
	swap(ps->a);
	swap(ps->b);
	ft_printf("ss\n");
}
