/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:04:19 by pau               #+#    #+#             */
/*   Updated: 2024/11/05 11:21:15 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d
{
    t_map *map;
    t_image *img;
} t_cub3d;

typedef struct s_image
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
    int		bits_p_pixel;
	int		line_len;
	int		endian;
    int		x_size;
	int		y_size;
	int		y_pos;
	int		x_pos;
	char	**map;
}				t_image;

typedef struct s_map
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    char    **map;
} t_map;

#endif