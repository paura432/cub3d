/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:40:31 by pau               #+#    #+#             */
/*   Updated: 2024/11/10 21:32:35 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_window(t_image *img)
{
	ft_printf("GAME FINISHED\n");
	free_list(img);
	return (0);
}

void		start_values(t_image *img)
{
	img->player = (t_player *)malloc(sizeof(t_player));
	if (img->player == NULL)
		return (free_list(img));
	img->player->px = img->x_player;
	img->player->py = img->y_player;
	img->player->pdx = 5.0;
	img->player->pdy = 0.0;
	img->player->pa = 0.0;

	img->win_width = count_bytes_w_fd(img->map[0]);
	img->win_height = count_lines_w_fd(img->map);
}

int	main(int argc, char **argv)
{
	t_image	img;

	if(argc == 0)
		return(0);
	img.map = ft_read(argv);
	start_values(&img);
	img.x_player = (count_bytes_w_fd(img.map[0]) * 64) / 2;
	img.y_player = (count_lines_w_fd(img.map) * 64) / 2;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, count_bytes_w_fd(img.map[0]) * 64,
			count_lines_w_fd(img.map) * 64, "cub3d");
	draw_map(&img);
	img.y_pixel = img.y_player;
    img.x_pixel = img.x_player;
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_hook(img.mlx_win, 2, 1L << 0, key_press, &img);
	mlx_loop(img.mlx);
}
