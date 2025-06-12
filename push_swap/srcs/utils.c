/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:40:16 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/26 17:01:10 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fterror(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

int	cduplicates(int *num, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (num[i] == num[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	push_stack(t_stack *stack, int inde, int value)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->value = value;
	tmp->index = inde;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->size++;
}
/*push_stack function is designed to push a new node onto the top of a stack.*/

int	removeget_top(t_stack *stack)
{
	t_node	*head;
	int		value;

	if (!stack->top)
		exit(1);
	head = stack->top;
	value = head->value;
	stack->top = head->next;
	free(head);
	head = NULL;
	stack->size--;
	return (value);
}
/*removeget_top to remove and return the top element of a stack.*/

int	indexof(int n, int *arry)
{
	int	i;

	i = 0;
	while (arry[i] != n)
		i++;
	return (i);
}
