/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:44:05 by mkorucu           #+#    #+#             */
/*   Updated: 2022/10/19 15:41:05 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./sources/ft_printf/ft_printf.h"
# include "./sources/libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*arr;
	int	len;
	int	average;
}	t_stack;

int		ft_num_check(char **str);
void	ft_sa_sb_ss(t_stack **a, t_stack **b, char *str);
void	ft_pa_pb(t_stack **a, t_stack **b, char *str);
void	ft_slider(t_stack **stack, char *str);
void	ft_ra_rb_rr(t_stack **a, t_stack **b, char *str);
void	ft_rra_rrb_rrr(t_stack **a, t_stack **b, char *str);
int		ft_order(t_stack *stack, char *str);
void	ft_radix(t_stack **a, t_stack **b);
int		ft_repeat_test(char **str, int len);
void	ft_initialer(t_stack **a, t_stack **b, t_stack **a_cpy, char **str);
void	ft_2_3_5(t_stack **a, t_stack **b);
void	ft_4_5(t_stack **a, t_stack **b);
void	ft_mid_sort(t_stack **a, t_stack **b);
void	ft_push_back(t_stack **a, t_stack **b);
void	ft_fix_a(t_stack **a, t_stack **b);
void	ft_divide(t_stack **a, t_stack **b);
void	ft_average(t_stack **stack);
int		ft_o_c(t_stack *a, int len);

#endif
