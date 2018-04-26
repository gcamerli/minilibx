/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:13:04 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/26 16:13:17 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_loop_hook(t_xvar *xvar, int (*funct)(), void *param)
{
	xvar->loop_hook = funct;
	xvar->loop_param = param;
	return (0);
}
