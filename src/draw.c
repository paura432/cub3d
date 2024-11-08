/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:45 by pau               #+#    #+#             */
/*   Updated: 2024/11/08 11:02:41 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void     draw_map(t_image *img)
{
    int i;
	int j;

	i = 0;
	while(img->map[i])
	{
		j = -1;
        img->x_pixel = 0;
        while(img->map[i][++j])
        {
            if (img->map[i][j] == '1')
                draw_pixel(img, 0xFFFFFF, 64);
            if (img->map[i][j] == 'N')
            {
                draw_pixel(img, 0x00FF0000, 8);
                img->x_player = img->x_pixel;
                img->y_player = img->y_pixel;
                printf("%i :: img->x_player\n", img->x_player);
                printf("%i :: img->x_player\n", img->y_player);
            }
            img->x_pixel += 64;
        }
        img->y_pixel += 64;
		i++;
	}
}

void    draw_pixel(t_image *img, int color, int pixel)
{
	int i;
	int j;

	i = 0;
	while(i < pixel)
	{
		j = -1;
		while(++j < pixel)
			mlx_pixel_put(img->mlx, img->mlx_win, img->x_pixel + i, img->y_pixel + j, color);
		i++;
	}
}