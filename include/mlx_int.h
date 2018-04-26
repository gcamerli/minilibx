/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:51:24 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 19:50:28 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INT_H
# define MLX_INT_H
# define MAX_EVENT 32
# define MAX_PIXEL_NB 200000
# define UNIQ_BPP 4

# define FONT_WIDTH 10
# define FONT_HEIGHT 20

typedef int	(*t_func)();

/*
**	1. Structures
*/

typedef struct		s_glsl_info
{
	GLuint		pixel_vshader;
	GLuint		pixel_fshader;
	GLuint		pixel_program;
	GLint		loc_pixel_position;
	GLint		loc_pixel_texture;
	GLint		loc_pixel_winhalfsize;
	GLuint		image_vshader;
	GLuint		image_fshader;
	GLuint		image_program;
	GLint		loc_image_position;
	GLint		loc_image_winhalfsize;
	GLint		loc_image_texture;
	GLint		loc_image_pos;
	GLint		loc_image_size;
	GLuint		font_vshader;
	GLuint		font_fshader;
	GLuint		font_program;
	GLint		loc_font_position;
	GLint		loc_font_winhalfsize;
	GLint		loc_font_texture;
	GLint		loc_font_color;
	GLint		loc_font_posinwin;
	GLint		loc_font_posinatlas;
	GLint		loc_font_atlassize;
}					t_glsl_info;

typedef struct		s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	GLfloat					vertexes[8];
	struct s_mlx_img_list	*next;
}					t_mlx_img_list;

typedef struct		s_mlx_img_ctx
{
	GLuint					texture;
	GLuint					vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}					t_mlx_img_ctx;

typedef struct		s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}					t_mlx_win_list;

typedef struct		s_mlx_ptr
{
	void				*appid;
	t_mlx_win_list		*win_list;
	t_mlx_img_list		*img_list;
	void				(*loop_hook)(void *);
	void				*loop_hook_data;
	void				*loop_timer;
	t_mlx_img_list		*font;
	int					main_loop_active;
}					t_mlx_ptr;

/*
**	2. Functions
*/

int					mlx_shaders(t_glsl_info *glsl);
char				**mlx_int_str_to_wordtab(char *str);
int					mlx_int_str_str(char *str, char *find, int len);
int					mlx_int_str_str_cote(char *str, char *find, int len);
int					mlx_destroy_image(t_mlx_ptr *mlx_ptr,
		t_mlx_img_list *img_ptr);
void				*mlx_new_image();
void				*mlx_xpm_to_image(t_mlx_ptr *xvar, char **xpm_data,
		int *width, int *height);
int					mlx_do_sync(t_mlx_ptr *mlx_ptr);

#endif
