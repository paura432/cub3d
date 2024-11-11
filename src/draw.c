/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:45 by pau               #+#    #+#             */
/*   Updated: 2024/11/12 00:44:24 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_map(t_image *img)
{
	int y;
	int x;

	y = 0;
	while(img->map[y])
	{
		x = -1;
		img->x_pixel = 0;
		while(img->map[y][++x])
		{
			if (img->map[y][x] == '1')
				draw_pixel(img, 0xFFFFFF, 64);
			if (img->map[y][x] == 'N')
			{
				draw_pixel(img, 0x00FF0000, 8);
				img->x_player = img->x_pixel;
				img->y_player = img->y_pixel;
			}
			img->x_pixel += 64;
		}
		img->y_pixel += 64;
		y++;
	}
}

void	draw_line(t_image *img, int color, int length)
{
	t_line line;
	int pixels_line;
	int i;
	int height;

	line.start_x = img->x_pixel + 4;
	line.start_y = img->y_pixel + 4;

	line.end_x = img->x_pixel + 4 + cos(img->player->pa) * length;
	line.end_y = img->y_pixel + 4 + sin(img->player->pa) * length;

	pixels_line = 100;
	height = -1;
	while(++height < 2)
	{
		i = -1;
		while (++i <= pixels_line)
		{
			line.intermediate_x = line.start_x + (line.end_x - line.start_x) * i / pixels_line;
			line.intermediate_y = line.start_y + (line.end_y - line.start_y) * i / pixels_line;
			mlx_pixel_put(img->mlx, img->mlx_win, (int)line.intermediate_x + height, (int)line.intermediate_y, color);
		}
	}
}

void	increase_degree(t_image *img)
{
	img->ray->ra += DR;
	if(img->ray->ra < 0)
		img->ray->ra += 2 * PI;
	else if(img->ray->ra > 2 * PI)
		img->ray->ra -= 2 * PI;
}

void draw_line_until_wall(t_image *img, int color, int max_distance)
{
	int i;
	int x;
	int y;
	int r;
	t_wall	wall;

	img->ray->ra = img->player->pa - DR * 30;
	r = -1;
	while (++r < 60)
	{
		i = -1;
		while (++i < max_distance)
		{
			x = img->x_pixel + 4 + cos(img->ray->ra) * i;
			y = img->y_pixel + 4 + sin(img->ray->ra) * i;
			if (img->map[y / 64][x / 64] == '1')
				break;
			mlx_pixel_put(img->mlx, img->mlx_win, x, y, color);
		}
		img->ray->dist_x = x;
		img->ray->dist_y = y;
        wall.wall_height = (img->win_height * 64) / (img->ray->dist_y + 1);  // +1 para evitar división por 0

        if (wall.wall_height > img->win_height)  // Limita la altura de la pared a la altura de la ventana
            wall.wall_height = img->win_height;

        // Dibuja la pared en la pantalla extendida
        wall.wall_y = (img->win_height / 2) - (wall.wall_height / 2);  // Empieza desde la parte superior de la pared
        while (wall.wall_y < (img->win_height / 2) + (wall.wall_height / 2))  // Dibuja la pared verticalmente
        {
            mlx_pixel_put(img->mlx, img->mlx_win, r + (img->win_width * 64), wall.wall_y, color);  // Dibuja el píxel en la pantalla
            wall.wall_y++;  // Incrementa la coordenada y
        }

		mlx_pixel_put(img->mlx, img->mlx_win, r * 8 + (img->win_width * 64), 0, color);
		mlx_pixel_put(img->mlx, img->mlx_win, r * 8 + (img->win_width * 64), img->ray->line_h, color);
        increase_degree(img);
	}
}

void    draw_pixel(t_image *img, int color, int pixel)
{
	int y;
	int x;

	y = 0;
	while(y < pixel)
	{
		x = -1;
		while(++x < pixel)
			mlx_pixel_put(img->mlx, img->mlx_win, (int)img->x_pixel + y, (int)img->y_pixel + x, color);
		y++;
	}
}