/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:53:53 by pramos            #+#    #+#             */
/*   Updated: 2024/11/08 14:40:31 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_list(t_image *img)
{
	if (img->player)
		free(img->player);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_matriz(img->map);
	free(img);
	exit(0);
}

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
		free(matriz[i++]);
	free(matriz);
}