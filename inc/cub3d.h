/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:42:37 by pau               #+#    #+#             */
/*   Updated: 2024/11/10 21:26:30 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "struct.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>
# include <math.h>
# include <x86intrin.h>
# include <semaphore.h>
# define PI 3.1415926535

//cub3d
t_image	*ft_new_sprite(t_image *cub, char *path);
int	    close_window(t_image *cub);
void	start_values(t_image *img);

//read
int	    count_lines(char *argv);
int	count_bytes(char *argv);
char	**ft_read(char **argv);

//flood_fill
int	    count_bytes_w_fd(char *map);
int	    count_lines_w_fd(char **map);
void	f_fill_p2e(char **flood_map, char target, int y, int x);

//free
void	free_list(t_image *cub);
void	free_matriz(char **matriz);

//raycasting
void    raycasting(t_image *img);

//move.c
// int	    move(int key_code, t_image *img);

int	    key_press(int key_code, t_image *img);
int	    move_check(t_image *img, int actual_px, int actual_py);
void	right(t_image *img);
void	up(t_image *img);
void	left(t_image *img);
void	down(t_image *img);

//draw.c
void    draw_map(t_image *img);
void    draw_pixel(t_image *img, int color, int pixel);
void    draw_line(t_image *img, int color, int length);
void    draw_line_until_wall(t_image *img, int color, int max_distance);

#endif