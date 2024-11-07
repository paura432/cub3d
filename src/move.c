/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/11/07 07:44:46 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key_code, t_image *img)
{
	draw_pixel(img, 0x000000, 8);
	
	if (key_code == 100)
		img->x_player += 5;
	if (key_code == 119)
		img->y_player -= 5;
	if (key_code == 97)
		img->x_player -= 5;
	if (key_code == 115)
		img->y_player += 5;
	if (key_code == 65307)
	{
		ft_printf("GAME FINISHED\n");
		free_list(img);
	}
	
	draw_pixel(img, 0x00FF0000, 8);
	return (0);
}

int	key_release(void)
{	
	return (0);
}

//tamaño del jugador de 8x8
void    draw_pixel(t_image *img, int color, int pixel)
{
	int i;
	int j;

	i = 0;
	while(i < pixel)
	{
		j = -1;
		while(++j < pixel)
			mlx_pixel_put(img->mlx, img->mlx_win, img->x_player + i, img->y_player + j, color);
		i++;
	}
}
