/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:49:26 by mkorucu           #+#    #+#             */
/*   Updated: 2022/10/19 15:40:58 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	ft_average(t_stack **stack)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < (*stack)->len)
		sum += (*stack)->arr[i++];
	(*stack)->average = sum / (*stack)->len;
}

void	ft_divide(t_stack **a, t_stack **b)
{
	int	len;

	while ((*a)->len > 2)
	{
		len = (*a)->len;
		ft_average(a);
		while (len-- > 0)
		{
			if ((*a)->arr[0] > (*a)->average)
				ft_ra_rb_rr(a, b, "ra");
			else
				ft_pa_pb(a, b, "pb");
		}
	}
}

void	ft_fix_a(t_stack **a, t_stack **b)
{
	if ((*a)->len > 1)
	{
		if ((*a)->arr[0] > (*a)->arr[1])
			ft_ra_rb_rr(a, b, "ra");
	}
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	int	order;

	while ((*b)->len > 0)
	{
		order = ft_order(*b, "max");
		if (order >= 0)
		{
			while (order-- > 0)
				ft_ra_rb_rr(a, b, "rb");
		}
		else if (order < 0)
		{
			order += (*b)->len;
			while (order-- > 0)
				ft_rra_rrb_rrr(a, b, "rrb");
		}
		ft_pa_pb(a, b, "pa");
	}
}

void	ft_mid_sort(t_stack **a, t_stack **b)
{
	ft_average(a);
	ft_divide(a, b);
	ft_fix_a(a, b);
	ft_push_back(a, b);
}
