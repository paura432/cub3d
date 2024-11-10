/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <pau@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:56:15 by pau               #+#    #+#             */
/*   Updated: 2024/11/10 21:30:06 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/cub3d.h"



// void    raycasting(t_image *img)
// {   
//     t_raycasting raycast;
//     float   atan;
//     int     x;
//     int     y;

//     raycast.ra = img->player->pa;
//     raycast.r = -1;
//     while(++raycast.r < 1)
//     {
//         raycast.dof = 0;
//         atan = -1 / tan(raycast.ra);
//         if(raycast.ra > PI)
//         {
//             raycast.ry = (((int)img->player->py>>6)<<6) -0.0001;
//             raycast.rx = (img->player->py - raycast.ry) * atan + img->player->px;
//             raycast.yo = -64;
//             raycast.xo = -raycast.yo * atan;
//         }
//         if(raycast.ra < PI)
//         {
//             raycast.ry = (((int)img->player->py>>6)<<6) + 64;
//             raycast.rx = (img->player->py - raycast.ry) * atan + img->player->px;
//             raycast.yo = 64;
//             raycast.xo = -raycast.yo * atan;
//         }
//         if (raycast.ra == 0 || raycast.ra == PI)
//         {
//             raycast.rx = img->player->px;
//             raycast.ry = img->player->py;
//             raycast. = 8;
//         }
//         while(raycast.dof < 8)
//         {
//             raycast.mx = (int) (raycast.rx) >> 6;
//             raycast.my = (int) (raycast.ry) >> 6;
//             raycast.mp = raycast.my * img->
//     }
// }
