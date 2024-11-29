/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:42:37 by pau               #+#    #+#             */
/*   Updated: 2024/11/04 20:44:19 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"

typedef enum e_cub_err
{
	end,
	inv_argc,
	inv_ext,
	inv_file,
	empty_file,
	no_memory,
	inv_color,
	inv_wall,
	inv_map,
	inv_charac,
	inv_player,
	inv_tex,
	inv_pwd
}				t_cub_err;

typedef struct s_img
{
	int		height;
	int		width;
	void	*i;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_color
{
	long	t;
	long	r;
	long	g;
	long	b;
}				t_color;


typedef struct s_tex
{
	t_list	*n;
	t_list	*n_bak;
	t_list	*s;
	t_list	*s_bak;
	t_list	*w;
	t_list	*w_bak;
	t_list	*e;
	t_list	*e_bak;
	t_img	*b;
	int		floor;
	int		ceiling;
}				t_tex;


typedef struct s_key
{
	int	w_pressed;
	int	a_pressed;
	int	s_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}				t_key;


typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
	float	speed;
	int		door_cooldown;
	t_key	keys;
}				t_player;


typedef struct s_ray
{
	float	incre_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	lim;
	int		precision;
}				t_ray;


typedef struct s_game
{
	int			fd;
	char		**map;
	int			height;
	int			width;
	int			mouse_x;
	int			rate;
	int			neg;
	long		nframes;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_img		win_g;
	t_img		win_r;
	t_img		minimap;
	t_img		miniview;
	t_img		*scope;
	t_tex		tex;
	t_ray		ray;
	t_player	pl;
	float		x;
	float		y;
}				t_game;

#endif

#endif