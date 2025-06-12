/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:26:06 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/26 11:53:43 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	freearry(char **arry)
{
	size_t	i;

	i = 0;
	if (arry)
	{
		while (arry && arry[i])
		{
			if (arry[i] != NULL)
			{
				free(arry[i]);
				arry[i] = NULL;
			}
			i++;
		}
		free(arry);
		arry = NULL;
	}
}

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
	}
	return (result * sign);
}

int	ftsqrt(int nrb)
{
	int	i;

	if (nrb < 4)
		return (1);
	i = 2;
	while (i * i < nrb)
		i++;
	if (i * i > nrb)
	{
		if ((i * i - nrb) < ((i - 1) * (i - 1) + (-nrb)))
			return (i);
	}
	return (i - 1);
}

void	insertion_sort(int array[], int count)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}
