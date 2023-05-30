/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:01:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 21:32:08 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	ra(t_pushswap *ps)
{
	reverse(&(ps->a));
	ft_printf("ra\n");
}

void	rb(t_pushswap *ps)
{
	reverse(&(ps->b));
	ft_printf("rb\n");
}

void	rr(t_pushswap *ps)
{
	rotate(&(ps->a));
	rotate(&(ps->b));
	ft_printf("rr\n");
}
