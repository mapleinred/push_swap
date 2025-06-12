/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:53:55 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/02 14:54:03 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	minindex(t_stack *stack)
{
	t_node	*current;
	int		mininde;

	current = stack->top;
	mininde = current->index;
	while (current->next)
	{
		current = current->next;
		if (current->index < mininde)
			mininde = current->index;
	}
	return (mininde);
}

int	countsteps(t_node *stack, int inde)
{
	int	count;

	count = 0;
	while (stack && stack->index != inde)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	issorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	freestack(t_stack *stack)
{
	while (stack)
		removeget_top(stack);
}

void	sort(t_stack *stacka, t_stack *stackb, int *num, int len)
{
	if (issorted(stacka))
	{
		free(num);
		freestack(stacka);
		fterror("");
	}
	else if (len == 2)
		swap(stacka, 'a', 1);
	else if (len == 3)
		simple_sort(stacka, len);
	else if (len <= 7)
		insertionsort(stacka, stackb, len);
	else if (len > 7)
	{
		sort1(stacka, stackb, len);
		sort2(stacka, stackb, len);
	}
	else
		fterror("");
}
