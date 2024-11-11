/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:04:19 by pau               #+#    #+#             */
/*   Updated: 2024/11/12 00:18:49 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_raycasting
{
	int         r;
	float       ra;
	float       dist_x;
	float       dist_y;
	float 		line_h;
}               t_raycasting;

typedef struct s_player
{
	float		px;
	float       py;
	float       pdx;
	float       pdy;
	float       pa;
}               t_player;

typedef struct s_wall
{
	int     wall_height;
	int     wall_top;
	int     wall_bottom;
	int     wall_y;
	int 	distance;
}               t_wall;

typedef struct s_image
{
	t_player        *player;
	t_raycasting    *ray;
	void	        *img;
	void	        *mlx;
	void	        *mlx_win;
	char            *addr;
	int		        bits_p_pixel;
	int		        line_len;
	int		        endian;
	int             win_width;
	int             win_height;
	float           x_player;
	float           y_player;
	float           x_pixel;
	float           y_pixel;
	char	        **map;
}				t_image;

typedef struct s_line
{
	float       start_x;
	float       start_y;
	float       end_x;
	float       end_y;
	float       intermediate_x;
	float       intermediate_y;
}               t_line;


#endif