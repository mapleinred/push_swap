/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:58:16 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/20 17:39:11 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cdigits(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
					&& av[i][j] != '-')
				return (-1);
			if (ft_isdigit(av[i][j]) && (av[i][j + 1] == ' ' ||
						av[i][j + 1] == '\0'))
				count += 1 ;
			j++;
		}
		i++;
	}
	return (count);
}

void	crange(char **numbers, int *num)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (ft_atol(numbers[i]) > 2147483647 \
		|| ft_atol(numbers[i]) < -2147483648)
		{
			freearry(numbers);
			free(num);
			fterror("Error\n");
		}
		i++;
	}
}

int	*argparse(int ac, char **av, int count)
{
	char	**numbers;
	int		*num;
	int		i;
	int		j;
	int		k;

	num = (int *)malloc(sizeof(int) * count);
	if (!num)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		if (!numbers)
			fterror("");
		crange(numbers, num);
		k = 0;
		while (numbers[k])
			num[j++] = ft_atoi(numbers[k++]);
		freearry(numbers);
	}
	return (num);
}
