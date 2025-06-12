/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istructions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:39 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/21 16:12:31 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack, char x, int y)
{
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
	if (y == 1)
	{
		write(1, "s", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *stackx, t_stack *stacky, char x, int y)
{
	int	inde;

	if (stacky->top == NULL)
		return ;
	inde = stacky->top->index;
	push_stack(stackx, inde, removeget_top(stacky));
	if (y == 1)
	{
		write(1, "p", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char x, int y)
{
	t_node	*tmp;
	t_node	*current;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	if (y == 1)
	{
		write(1, "r\n", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_stack *stack, char x, int y)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack->top || !stack->top->next || !stack)
		return ;
	current = stack->top;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
	if (y == 1)
	{
		write(1, "rr", 2);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}
