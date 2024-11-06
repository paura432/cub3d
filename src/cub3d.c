/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:40:31 by pau               #+#    #+#             */
/*   Updated: 2024/11/06 11:09:21 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_image	*ft_new_sprite(t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path,
			&img->x_size, &img->y_size);
	if (img->img == NULL)
		perror("Error\nImage failed to push to window");
	img->addr = mlx_get_data_addr(img->img, &img->bits_p_pixel,
			&img->line_len, &img->endian);
	return (img);
}

int	close_window(t_image *img)
{
	ft_printf("GAME FINISHED\n");
	free_list(img);
	return (0);
}

// int	check_extension(char *str)
// {
// 	char	*ext;
// 	int		i;

// 	i = ft_strlen(str) - 4;
// 	ext = ft_substr(str, i, 4);
// 	if (ft_strnstr(ext, ".ber", 4))
// 		return (free(ext), 1);
// 	return (free(ext), 0);
// }

// // void	leaks(void)
// // {
// // 	system("leaks -q so_long");
// // }

// int	check_permision(char **argv)
// {
// 	if (open(argv[1], O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/background.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/door.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/rick-back.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/rick-front.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/rick-left.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/rick-right.xpm", O_RDONLY) == -1)
// 		return (0);
// 	if (open("sprites/wall.xpm", O_RDONLY) == -1)
// 		return (0);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	char	**map;
	t_image	*img;

	if(argc == 0)
		return(0);
	// if (!check_permision(argv) || argc != 2
	// 	|| (argc == 2 && !check_extension(argv[1])))
	// 	return (ft_printf("error\nbad argument\n"), 1);
	// if (!ft_read(argv))
	// 	return (ft_printf("error\nbad map\n"));
	map = ft_read(argv);
	// if (!check_map(map, argv))
	// 	return (free_matriz(map), ft_printf("error\nbad map\n"));
	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		exit(1);
	img->mlx = mlx_init();
	img->y_size = count_lines_w_fd(map) * 64;
	img->x_size = count_bytes_w_fd(map[0]) * 64;
	img->mlx_win = mlx_new_window(img->mlx, img->x_size,
			img->y_size, "cub3d");
	img->map = map;
	int i = 0;
	while(map[i])
		printf("%s\n", map[i++]);
	raycasting(img);
	mlx_hook(img->mlx_win, 17, 0, close_window, img);
	mlx_key_hook(img->mlx_win, move, img);
	mlx_loop(img->mlx);
}
