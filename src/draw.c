/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:45 by pau               #+#    #+#             */
/*   Updated: 2024/11/26 22:52:47 by pau              ###   ########.fr       */
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

	line.end_x = img->x_pixel + 2 + cos(img->player->pa) * length;
	line.end_y = img->y_pixel + 2 + sin(img->player->pa) * length;

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

void draw_block(t_image *img, int x, int y, int color)
{
    int block_size;
    int block_x;
	int block_y;

	block_size = 8;
    block_y = y;
    while (block_y < y + block_size)
    {
        block_x = x;
        while (block_x < x + block_size)
        {
            mlx_pixel_put(img->mlx, img->mlx_win, block_x, block_y, color);
            block_x++;
        }
        block_y++;
    }
}

void draw_line_until_wall(t_image *img, int color, int max_distance)
{
    int r; // Índice del rayo
    t_wall wall; // Usamos la estructura para almacenar las propiedades del muro
	int eje;
	int suma;
	
    img->ray->ra = img->player->pa - DR * 30; // Ángulo inicial del rayo
    r = -1;
	eje = 0;
	suma = 0;
    while (++r < 60)
    {
        wall.distance = -1;
        while (++wall.distance < max_distance)
        {
            wall.wall_x = img->x_pixel + 4 + cos(img->ray->ra) * wall.distance;
            wall.wall_y = img->y_pixel + 4 + sin(img->ray->ra) * wall.distance;
            if (img->map[wall.wall_y / 64][wall.wall_x / 64] == '1')
                break;
            mlx_pixel_put(img->mlx, img->mlx_win, wall.wall_x, wall.wall_y, color);
        }
		wall.ca = img->player->pa - img->ray->ra;
		if (wall.ca < 0)
			wall.ca += 2 * PI;
		if (wall.ca > 2 * PI)
			wall.ca -= 2 * PI;
		wall.distance = wall.distance * cos(wall.ca);
		wall.lineH = ((240 * 64) / wall.distance);
		if (wall.lineH > 240)
			wall.lineH = 240;
		wall.lineO = (120 - wall.lineH) / 2;
		
		suma = wall.lineO;
		while (suma < wall.lineH)
		{
			draw_block(img, img->win_width * 64 + eje, wall.lineH + wall.lineO - suma, color);
			suma ++;
		}
		eje += 8;
        increase_degree(img); // Incrementamos el ángulo para el siguiente rayo
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