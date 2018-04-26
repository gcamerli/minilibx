/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:32:25 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 19:38:55 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_expose_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[Expose].hook = funct;
	win->hooks[Expose].param = param;
	win->hooks[Expose].mask = ExposureMask;
	return (0);
}
