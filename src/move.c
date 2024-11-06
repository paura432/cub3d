/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/11/06 11:15:18 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	move(int key_code, t_image *img)
{
	if (key_code == 100)
		right(img);
	// if (key_code == 119)
	// 	up(img);
	// if (key_code == 97)
	// 	left(img);
	// if (key_code == 115)
	// 	down(img);
	if (key_code == 65307)
	{
		ft_printf("GAME FINISHED\n");
		free_list(img);
	}
	return (0);
}
void	black_out(t_image *img)
{
	int		x;
	int		y;

	y = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x] != '\0' && img->map[y][x] != '\n')
		{
			if (img->map[y][x] == '0' || img->map[y][x] == 'N')
                fill_pixels(img, "textures/suelo.xpm", x, y);
			x++;
		}
		y++;
	}
}

void	right(t_image *img)
{
	// if ((img->x_pos + 1) *64 < img->x_pxl_pos + 4)
	// 	return ;
	img->x_pxl_pos += 4;
	black_out(img);
	img = ft_new_sprite(img, "fonod mas pequeño.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pxl_pos, img->y_pxl_pos);
}