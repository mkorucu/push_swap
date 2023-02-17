/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:01:00 by mkorucu           #+#    #+#             */
/*   Updated: 2022/10/19 13:55:49 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb_ss(t_stack **a, t_stack **b, char *str)
{
	int	swap;

	if ((!ft_strncmp(str, "ss", 3) || \
				!ft_strncmp(str, "sa", 3)) && (*a)->len >= 2)
	{
		swap = (*a)->arr[0];
		(*a)->arr[0] = (*a)->arr[1];
		(*a)->arr[1] = swap;
	}
	if ((!ft_strncmp(str, "ss", 3) || \
				!ft_strncmp(str, "sb", 3)) && (*b)->len >= 2)
	{
		swap = (*b)->arr[0];
		(*b)->arr[0] = (*b)->arr[1];
		(*b)->arr[1] = swap;
	}
	ft_printf("%s\n", str);
}

void	ft_pa_pb(t_stack **a, t_stack **b, char *str)
{
	int	swap;

	if (!ft_strncmp(str, "pa", 3) && (*b)->len != 0)
	{
		swap = (*b)->arr[0];
		ft_slider(b, "up");
		ft_slider(a, "down");
		(*a)->arr[0] = swap;
		(*b)->len--;
		(*a)->len++;
	}
	if (!ft_strncmp(str, "pb", 3) && (*a)->len != 0)
	{
		swap = (*a)->arr[0];
		ft_slider(a, "up");
		ft_slider(b, "down");
		(*b)->arr[0] = swap;
		(*b)->len++;
		(*a)->len--;
	}
	ft_printf("%s\n", str);
}

void	ft_ra_rb_rr(t_stack **a, t_stack **b, char *str)
{
	int	swap;

	if ((!ft_strncmp(str, "rr", 3) || \
				!ft_strncmp(str, "ra", 3)) && (*a)->len > 1)
	{
		swap = (*a)->arr[0];
		ft_slider(a, "up");
		(*a)->arr[(*a)->len - 1] = swap;
	}
	if ((!ft_strncmp(str, "rr", 3) || \
				!ft_strncmp(str, "rb", 3)) && (*b)->len > 1)
	{
		swap = (*b)->arr[0];
		ft_slider(b, "up");
		(*b)->arr[(*b)->len - 1] = swap;
	}
	ft_printf("%s\n", str);
}

void	ft_rra_rrb_rrr(t_stack **a, t_stack **b, char *str)
{
	int	swap;

	if ((!ft_strncmp(str, "rrr", 4) || \
				!ft_strncmp(str, "rra", 4)) && (*a)->len > 1)
	{
		swap = (*a)->arr[(*a)->len - 1];
		ft_slider(a, "down");
		(*a)->arr[0] = swap;
	}
	if ((!ft_strncmp(str, "rrr", 4) || \
				!ft_strncmp(str, "rrb", 4)) && (*b)->len > 1)
	{
		swap = (*b)->arr[(*b)->len - 1];
		ft_slider(b, "down");
		(*b)->arr[0] = swap;
	}
	ft_printf("%s\n", str);
}

void	ft_slider(t_stack **stack, char *str)
{
	int	i;

	if (!ft_strncmp(str, "up", 3))
	{
		i = 1;
		while (i < (*stack)->len)
		{
			(*stack)->arr[i - 1] = (*stack)->arr[i];
			i++;
		}
	}
	else if (!ft_strncmp(str, "down", 5))
	{
		i = (*stack)->len;
		while (i > 0)
		{
			(*stack)->arr[i] = (*stack)->arr[i - 1];
			i--;
		}
	}
}
