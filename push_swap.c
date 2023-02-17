/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:08:29 by mkorucu           #+#    #+#             */
/*   Updated: 2022/11/12 13:15:03 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_check(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[++j])
	{
		i = 0;
		if (str[j][i] == '+' || str[j][i] == '-')
			i++;
		if (str[j][i] == '\0')
			return (0);
		while (str[j][i] != '\0')
		{
			if (!ft_isdigit(str[j][i]))
				return (0);
			i++;
		}
	}
	return (j - 1);
}

void	ft_initialer(t_stack **a, t_stack **b, t_stack **a_cpy, char **str)
{
	int	i;
	int	len;

	len = 1;
	while (str[len])
		len++;
	len--;
	(*a) = ft_calloc(sizeof(t_stack), 1);
	(*b) = ft_calloc(sizeof(t_stack), 1);
	(*a_cpy) = ft_calloc(sizeof(t_stack), 1);
	(*a)->arr = ft_calloc(sizeof(int), len);
	(*b)->arr = ft_calloc(sizeof(int), len);
	(*a_cpy)->arr = ft_calloc(sizeof(int), len);
	(*a)->len = len;
	(*a_cpy)->len = len;
	(*b)->len = 0;
	(*a)->average = 0;
	(*a_cpy)->average = 0;
	(*b)->average = 0;
	i = -1;
	while (++i < len)
		(*a)->arr[i] = ft_atoi(str[i + 1]);
}

void	ft_sorter(t_stack **a, t_stack **a_cpy)
{
	int	i;
	int	order;
	int	j;

	i = 0;
	while (i < (*a)->len)
	{
		j = 0;
		order = 0;
		while (j < (*a)->len)
		{
			if ((*a)->arr[i] > (*a)->arr[j++])
			order++;
		}
		(*a_cpy)->arr[i] = order;
		i++;
	}
}

int	ft_repeat_test(char **str, int len)
{
	int	num;
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		num = ft_atoi(str[i]);
		j = i + 1;
		if (!ft_atoi(str[i]) && *str[i] != '0')
			return (0);
		while (j < len)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*a_cpy;
	t_stack	*b;

	if (argc > 2 && ft_num_check(argv) && ft_repeat_test(argv, argc))
	{
		ft_initialer(&a, &b, &a_cpy, argv);
		ft_sorter(&a, &a_cpy);
		if (!ft_o_c(a_cpy, argc - 1))
			return (0);
		if ((a)->len >= 200)
			ft_radix(&a_cpy, &b);
		else if (a->len < 200 && a->len > 5)
			ft_mid_sort(&a, &b);
		else if (a->len < 6)
			ft_2_3_5(&a_cpy, &b);
	}
	else if (argc == 1)
		return (0);
	else if (argc <= 2 && ft_num_check(argv) && ft_repeat_test(argv, argc))
		return (0);
	else
		ft_printf("Error!\n");
	return (0);
}
