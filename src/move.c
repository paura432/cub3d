/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/11/26 22:56:40 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key_code, t_image *img)
{
	draw_line_until_wall(img, 0x000000, count_bytes_w_fd(img->map[0]) * 64);
	draw_pixel(img, 0x000000, 8);

	if (key_code == 100)
		right(img);
	if (key_code == 97)
		left(img);
	move_check(img);
	if (key_code == 119)
		up(img);
	if (key_code == 115)
		down(img);
	if (key_code == 65307)
	{
		ft_printf("GAME FINISHED\n");
		free_list(img);
	}
	
	draw_line_until_wall(img, 0x00FF00, count_bytes_w_fd(img->map[0]) * 64);
	draw_pixel(img, 0x00FF0000, 8);
	
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
	if(img->map[img->check->ipy][img->check->ipx_add_xo] == '0'
		|| img->map[img->check->ipy][img->check->ipx_add_xo] == 'N')
    	img->x_pixel += img->player->pdx;
	if(img->map[img->check->ipy_add_yo][img->check->ipx] == '0' 
		|| img->map[img->check->ipy_add_yo][img->check->ipx] == 'N')
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
	if(img->map[img->check->ipy][img->check->ipx_sub_xo] == '0'
		|| img->map[img->check->ipy][img->check->ipx_sub_xo] == 'N')
    	img->x_pixel -= img->player->pdx;
	if(img->map[img->check->ipy_sub_yo][img->check->ipx] == '0' 
		|| img->map[img->check->ipy_sub_yo][img->check->ipx] == 'N')
    	img->y_pixel -= img->player->pdy;
}

int	move_check(t_image *img)
{
	int x;
	int y;

	if(img->player->pdx < 0)
		img->check->x = -20;
	else
		img->check->x = 20;
	if(img->player->pdy < 0)
		img->check->y = -20;
	else
		img->check->y = 20;
	x = (int)img->x_pixel;
	y = (int)img->y_pixel;
	img->check->ipx = (int)img->x_pixel / 64;
	img->check->ipy = (int)img->y_pixel / 64;
	img->check->ipx_add_xo = ((x + img->check->x) / 64);
	img->check->ipy_add_yo = ((y + img->check->y) / 64);
	img->check->ipx_sub_xo = ((x - img->check->x) / 64);
	img->check->ipy_sub_yo = ((y - img->check->y) / 64);
	return (0);
}

