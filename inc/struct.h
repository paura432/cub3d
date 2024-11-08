/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:04:19 by pau               #+#    #+#             */
/*   Updated: 2024/11/08 10:50:23 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


typedef struct s_map
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    char    **map;
}           t_map;

typedef struct s_image
{
    t_map   *tmap;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
    int		bits_p_pixel;
	int		line_len;
	int		endian;
    int     x_player;
    int     y_player;
    int     x_pixel;
    int     y_pixel;
	char	**map;
}				t_image;

#endif