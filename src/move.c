/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/11/08 11:05:12 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key_code, t_image *img)
{
	draw_pixel(img, 0x000000, 8);
	
	if (key_code == 100)
		img->x_pixel += 8;
	if (key_code == 119)
		img->y_pixel -= 8;
	if (key_code == 97)
		img->x_pixel -= 8;
	if (key_code == 115)
		img->y_pixel += 8;
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
