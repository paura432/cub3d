/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:45 by pau               #+#    #+#             */
/*   Updated: 2024/11/10 21:27:19 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void     draw_map(t_image *img)
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

void draw_line(t_image *img, int color, int length)
{
	t_line line;
	int pixels_line;
	int i;

	//donde empieza la linea el centro de nnuestro personaje
	line.start_x = img->x_pixel + 4;
	line.start_y = img->y_pixel + 4;

	//donde acaba
	line.end_x = img->x_pixel + 4 + cos(img->player->pa) * length;
	line.end_y = img->y_pixel + 4 + sin(img->player->pa) * length;

	pixels_line = 100;
	i = -1;
	while (++i <= pixels_line)
    {
		//los puntos que nos interesan que van desde el centro hasta el punto final
        line.intermediate_x = line.start_x + (line.end_x - line.start_x) * i / pixels_line;
        line.intermediate_y = line.start_y + (line.end_y - line.start_y) * i / pixels_line;

        mlx_pixel_put(img->mlx, img->mlx_win, (int)line.intermediate_x, (int)line.intermediate_y, color);
    }
}

void draw_line_until_wall(t_image *img, int color, int max_distance)
{
    int i;
    int x, y;

    i = 0;
    while (i < max_distance)
    {
        // Calculamos las coordenadas del rayo
        x = img->x_pixel + 4 + cos(img->player->pa) * i;
        y = img->y_pixel + 4 + sin(img->player->pa) * i;

        // Si encontramos un muro, dejamos de dibujar
        if (img->map[y / 64][x / 64] == '1')
            break;

        // Dibujamos el pixel en la pantalla
        mlx_pixel_put(img->mlx, img->mlx_win, x, y, color);

        i++; // Avanzamos
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