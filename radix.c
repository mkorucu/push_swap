/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:48:15 by mkorucu           #+#    #+#             */
/*   Updated: 2022/11/12 12:50:15 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_o_c(t_stack *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i != a->arr[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_2_3_5(t_stack **a, t_stack **b)
{
	if (ft_o_c(*a, (*a)->len) && (*a)->len == 2 && ft_order(*a, "min") == -1)
		ft_ra_rb_rr(a, b, "ra");
	else if (ft_o_c(*a, (*a)->len) && (*a)->len == 3)
	{
		if (!ft_order(*a, "min"))
			ft_ra_rb_rr(a, b, "ra");
		else if (ft_order(*a, "min") == 1)
			ft_rra_rrb_rrr(a, b, "rra");
		if (ft_order(*a, "max") == 0)
			ft_sa_sb_ss(a, b, "sa");
		ft_rra_rrb_rrr(a, b, "rra");
	}
	else if ((*a)->len >= 4 && ft_o_c(*a, (*a)->len))
		ft_4_5(a, b);
}

void	ft_4_5(t_stack **a, t_stack **b)
{
	while ((*a)->len == 5 && ft_order(*a, "min") != 0)
	{
		if (ft_order(*a, "min") > 0)
			ft_ra_rb_rr(a, b, "ra");
		else
			ft_rra_rrb_rrr(a, b, "rra");
	}
	if ((*a)->len == 5)
		ft_pa_pb(a, b, "pb");
	while (ft_order(*a, "min") != 0)
	{
		if (ft_order(*a, "min") == 1)
			ft_ra_rb_rr(a, b, "ra");
		if (ft_order(*a, "min") < 0)
			ft_rra_rrb_rrr(a, b, "rra");
	}
	ft_pa_pb(a, b, "pb");
	ft_2_3_5(a, b);
	ft_pa_pb(a, b, "pa");
	ft_pa_pb(a, b, "pa");
}

int	ft_order(t_stack *stack, char *str)
{
	int	num;
	int	order;
	int	i;

	i = 0;
	order = 0;
	num = stack->arr[i];
	while (++i < stack->len)
	{
		if (!ft_strncmp(str, "min", 4) && stack->arr[i] < num)
		{
			num = stack->arr[i];
			order = i;
		}
		else if (!ft_strncmp(str, "max", 4) && stack->arr[i] > num)
		{
			num = stack->arr[i];
			order = i;
		}
	}
	if (order < (i + 1) / 2)
		return (order);
	else
		return (-order);
}

void	ft_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	bit;
	int	x;

	bit = 1;
	i = (*a)->len;
	while (i > bit)
		bit *= 2;
	i = 1;
	while (i < bit)
	{
		x = (*a)->len;
		while (x != 0 && x--)
		{
			if ((*a)->arr[0] & i)
				ft_ra_rb_rr(a, b, "ra");
			else
				ft_pa_pb(a, b, "pb");
		}
		x = 0;
		while (x < (*b)->len)
			ft_pa_pb(a, b, "pa");
		i *= 2;
	}
}
