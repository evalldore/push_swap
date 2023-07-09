/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:58:03 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/03 18:10:21 by niceguy          ###   ########.fr       */
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
