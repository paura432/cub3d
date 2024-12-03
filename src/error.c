#include "../inc/cub3d.h"

int cuberror(t_cub_err err, t_game *game, char *param, int c)
{
    if (!c)
        return (0);
    cub_end(game);
    write(2, "cub3d: ", 7* (err != end));
    write(2, "invalid number of argument\n", 28*(err == inv_argc));
    write(2, "not run in root of the project\n", 32*(err == inv_pwd));
    write(2, "file must be .cub\n", 19*(err == inv_ext));
    write(2, "error opening file\n", (err == inv_file));
    write(2, "file empty\n", (err == empty_file));
    write(2, "out of memory\n", (err == no_memory));
    write(2, "invalid color\n", (err == inv_color));
    write(2, "map not surrounded by walls\n", (err == inv_wall));
    write(2, "invalid map\n", (err == inv_map));
    write(2, "invalid character\n", (err == inv_charac));
    write(2, "invalid texture\n", (err == inv_tex));
    write(2, "invalid number of player\n", (err == inv_player));
    ft_putendl_fd(param, 2);
    if (err == inv_argc && ft_putchar_fd('\n', 2))
        cub_usage(1);
    if (err == end)
        cub_exit(0);
    exit(1);
    return (1);
}

void cub_usage(int err)
{
    ft_putstr_fd("cub3D\n simple raycaster",2);
    ft_putstr_fd("usage: <map.cub>\n", 2);
    exit(err);
}

void cub_exit(void *param)
{
    cuberror(end, param, NULL, 1);
    return (0);
}