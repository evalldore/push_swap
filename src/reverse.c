/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:05:04 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/08 14:24:35 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	rra(t_pushswap *ps)
{
	reverse(&(ps->a));
	ft_printf("rra\n");
}

void	rrb(t_pushswap *ps)
{
	reverse(&(ps->b));
	ft_printf("rra\n");
}

void	rrr(t_pushswap *ps)
{
	reverse(&(ps->a));
	reverse(&(ps->b));
	ft_printf("rrr\n");
}
