/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:56:15 by pau               #+#    #+#             */
/*   Updated: 2024/11/06 11:05:35 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/cub3d.h"

void    fill_map(t_image *img)
{
	int		x;
	int		y;

	y = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x] != '\0' && img->map[y][x] != '\n')
		{
			if (img->map[y][x] == '1')
                fill_pixels(img, "textures/fondo_azul.xpm", x, y);
            else
                fill_pixels(img, "textures/suelo.xpm", x, y);
            if(img->map[y][x] == 'N')
            {
                img = ft_new_sprite(img, "textures/fondo mas pequeño.xpm");
                img->x_pos = x;
                img->y_pos = y;
                img->x_pxl_pos = x * 64;
                img->y_pxl_pos = y * 64;
                mlx_put_image_to_window(img->mlx, img->mlx_win,
                img->img, (x * 64), (y * 64));
            }
			x++;
		}
		y++;
	}
}

void    fill_pixels(t_image *img, char *relative_path, int x, int y)
{
	img = ft_new_sprite(img, relative_path);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
	img->img, (x * 64), (y * 64));
}

void    raycasting(t_image *img)
{   
    fill_map(img);
}