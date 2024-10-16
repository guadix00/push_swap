/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:03:43 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 16:42:22 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**split_arg(char const *s, char c)
{
	char	**arr;
	char	**new_arr;
	size_t	i;
	size_t	word_count;

	arr = ft_split(s, c);
	if (!arr)
		return (NULL);
	word_count = 0;
	while (arr[word_count])
		word_count++;
	new_arr = malloc(sizeof(char *) * (word_count + 2));
	if (!new_arr)
		return (NULL);
	new_arr[0] = malloc(sizeof(char));
	if (!new_arr[0])
		return (NULL);
	new_arr[0][0] = 0;
	i = -1;
	while (arr[++i])
		new_arr[i + 1] = arr[i];
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

long	ft_atol(char *str)
{
	long	nbl;
	int		sign;

	nbl = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbl = nbl * 10 + *str - '0';
		str++;
	}
	return (nbl * sign);
}

void	init_stack(t_stack **a, char *argv[], bool free_argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_free(a, argv, free_argv);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a, argv, free_argv);
		if (dup_error(*a, (int)num))
			error_free(a, argv, free_argv);
		innit_node(a, (int)num);
		i++;
	}
	if (free_argv)
		free_arr(argv);
}
