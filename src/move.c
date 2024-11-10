/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/11/10 21:32:00 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key_code, t_image *img)
{
	float actual_px;
	float actual_py;

	actual_px = img->x_pixel;
	actual_py = img->y_pixel;
	draw_pixel(img, 0x000000, 8);
	draw_line_until_wall(img, 0x000000, count_bytes_w_fd(img->map[0]) * 64);

	
	if (key_code == 100)
		if(move_check(img, (actual_px + 8), actual_py))
			right(img);
	if (key_code == 119)
		if(move_check(img, actual_px,(actual_py - 8)))
			up(img);
	if (key_code == 97)
		if(move_check(img, (actual_px - 8), actual_py))
			left(img);
	if (key_code == 115)
		if(move_check(img, actual_px, (actual_py + 8)))
			down(img);
	if (key_code == 65307)
	{
		ft_printf("GAME FINISHED\n");
		free_list(img);
	}
	
	draw_pixel(img, 0x00FF0000, 8);
	draw_line_until_wall(img, 0x00FF0000, count_bytes_w_fd(img->map[0]) * 64);
		
	return (0);
}

void	right(t_image *img)
{
	img->player->pa -= 0.1;
	if(img->player->pa < 0)
		img->player->pa += 2*PI;
	img->player->pdx = cos(img->player->pa) * 5;
	img->player->pdy = sin(img->player->pa) * 5;
}

void	up(t_image *img)
{
    img->x_pixel += img->player->pdx;
    img->y_pixel += img->player->pdy;
}

void	left(t_image *img)
{
	img->player->pa += 0.1;
	if(img->player->pa > 2 * PI)
		img->player->pa -= 2*PI;

	img->player->pdx = cos(img->player->pa) * 5;
	img->player->pdy = sin(img->player->pa) * 5;
}

void	down(t_image *img)
{
    img->x_pixel -= img->player->pdx;
    img->y_pixel -= img->player->pdy;
}

int	move_check(t_image *img, int actual_px, int actual_py)
{
	int x_map;
	int y_map;
	
	x_map = (int)actual_px / 64;
	y_map = (int)actual_py / 64;
	if(img->map[y_map][x_map] == '1')
		return(0);
	return (1);
}
