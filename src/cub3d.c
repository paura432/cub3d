/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:40:31 by pau               #+#    #+#             */
/*   Updated: 2024/11/07 07:56:37 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_window(t_image *img)
{
	ft_printf("GAME FINISHED\n");
	free_list(img);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_image	img;

	if(argc == 0)
		return(0);
	map = ft_read(argv);
	img.x_player = 1024 / 2;
	img.y_player = 512 / 2;
	img.mlx = mlx_init();
	printf("%i	\n", count_bytes_w_fd(map[0]) * 64);
	img.mlx_win = mlx_new_window(img.mlx, count_bytes_w_fd(map[0]) * 64,
			count_lines_w_fd(map) * 64, "cub3d");
	img.map = map;
	draw_pixel(&img, 0x00FF0000, 8);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_hook(img.mlx_win, 2, 1L << 0, key_press, &img);
	mlx_loop(img.mlx);
}