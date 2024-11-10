/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:04:19 by pau               #+#    #+#             */
/*   Updated: 2024/11/10 20:48:08 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


typedef struct s_player
{
    float       px;
    float       py;
    float       pdx;
    float       pdy;
    float       pa;
}               t_player;

typedef struct s_image
{
    t_player    *player;
	void	    *img;
	void	    *mlx;
	void	    *mlx_win;
	char        *addr;
    int		    bits_p_pixel;
	int		    line_len;
	int		    endian;
    int         win_width;
    int         win_height;
    float       x_player;
    float       y_player;
    float       x_pixel;
    float       y_pixel;
	char	    **map;
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

typedef struct s_raycasting
{
    int         r;
    int         mx;
    int         my;
    int         mp;
    int         dof;
    float       rx;
    float       ry;
    float       ra;
    float       xo;
    float       yo;
}               t_raycasting;

#endif