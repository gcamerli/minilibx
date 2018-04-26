/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_data_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:33:48 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 20:39:33 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

char	*mlx_get_data_addr(t_img *img, int *bits_per_pixel,
		int *size_line, int *endian)
{
	*bits_per_pixel = img->bpp;
	*size_line = img->size_line;
	*endian = img->image->byte_order;
	return (img->data);
}
