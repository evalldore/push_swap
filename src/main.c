/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:53:05 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/25 20:23:29 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		nums[4];

	(void)argc;
	(void)argv;
	b = NULL;
	nums[0] = 10;
	nums[1] = 240;
	nums[2] = 2;
	nums[3] = 1;
	a = ft_lstnew(&nums[0]);
	a->next = ft_lstnew(&nums[1]);
	printf("before : 1: %d 2: %d\n", *((int *)(a->content)), *((int *)(a->next->content)));
	swap(a);
	printf("after : 1: %d 2: %d\n", *((int *)(a->content)), *((int *)(a->next->content)));
	push(&b, &a);
	printf("b : 1: %d\n", *((int *)(b->content)));
	return (EXIT_SUCCESS);
}
