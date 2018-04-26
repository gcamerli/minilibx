/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:21:48 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 16:58:22 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	1. GNU/Linux
**
**	MinilibX uses 2 library that it's necessary to add to the compilation:
**	-lmlx -lXext -lX11
**
**	2. MacOSX
**
**	MinilibX uses 2 library that it's necessary to add to the compilation:
**	-framework OpenGL -framework AppKit
*/

#ifndef MLX_H
# define MLX_H

void			*mlx_init();

/*
**	1. Basic actions
*/

void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
		char *title);
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
		int color);
/*
**  Note
**
**	Origin for x & y is top left corner of the window.
**  Color is 0x00RRGGBB.
*/

/*
**	2. Image
*/

void			*mlx_new_image(void *mlx_ptr, int width, int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
		int *size_line, int *endian);
/*
**	Note
**
**  Server X: little endian = 0 | big endian = 1
**
**  It is useless on macos, client and graphical framework
**	have the same endian.
*/

int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
		void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

/*
**	3. Events
*/

int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
		void *param);
int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);

/*
**	Note
**
**	Hook functions are called as follow:
**
**		expose_hook(void *param);
**		key_hook(int keycode, void *param);
**		mouse_hook(int button, int x,int y, void *param);
**		loop_hook(void *param);
*/

int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x,
		int y, int color, char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
		int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
		int *width, int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
**	Note
**
**	Generic hook system for all events, and minilibX functions that
**	can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
		int (*funct)(), void *param);
int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

#endif
