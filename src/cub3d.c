/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:40:31 by pau               #+#    #+#             */
/*   Updated: 2024/11/04 20:40:32 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


// void	leaks(void)
// {
// 	system("leaks -q so_long");
// }
/*
*verifica los archivos pasados como argumentos en el prompt
*/
static void check_file(int argc, char **argv)
{
	int fd;

	cuberror(inv_argc, NULL, NULL, argc!=2);
	if (!ft_strncmp(argv[1], "-h", 3) || !ft_Strncmp(argv[1], "--help", 7))
		cub_usage(0);
	fd = open(argv[1],O_RDONLY);
	close(fd);
	cuberror(inv_file, NULL, argv[1], fd < 0);
	if (ft_strrncmp(".cub", argv[1], 4))
		cuberror(inv_ext, NULL, NULL, 1);
	
}

void init_sprites(t_game *game)
{
	game->win_img.i = NULL;
	game->win_r.i = NULL;
	game->win_g.i = NULL;
	game->minimap.i = NULL;
	game->miniview.i = NULL;
	game->tex.e = NULL;
	game->tex.e_bak = NULL;
	game->tex.n = NULL;
	game->tex.n_bak = NULL;
	game->tex.s = NULL;
	game->tex.s_bak = NULL;
	game->tex.w = NULL;
	game->tex.w_bak = NULL;
	game->tex.b = mlx_load_img(game->mlx_ptr, "textura");
	game->scope = mlx_load_img(game->mlx_ptr, "textura");
	if (!game->tex.b || !game->tex.b->i || !game->scope || !game->scope->i)
		cuberror(inv_pwd, game, NULL, 1);
}

static t_game init_cub(void)
{
	t_game game;
	game.fd = -1;
	game.height = 0;
	game.map = NULL;
	game.pl.dir = 0;
	game.mlx_ptr = NULL;
	game.win_ptr = NULL;
	game.mlx_ptr = mlx_init();
	init_sprites(&game);
	game.tex.ceiling = -1;
	game.tex.floor = -1;
	game.mouse_x = 0;
	game.neg = -1;
	game.nframes = 0;
	game.rate = 30;
	game.width = 0;
	game.pl.x = -1;
	game.pl.y = -1;
	game.pl.speed = 0.12;
	game.pl.door_cooldown = 0;
	ft_bzero(&game.pl.keys, sizeof(t_key));
	return (game);

}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	check_file(argc, argv);
	game = init_cub();
}
