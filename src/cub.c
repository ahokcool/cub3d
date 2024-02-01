/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:15:01 by astein            #+#    #+#             */
/*   Updated: 2024/02/01 15:53:07 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_cub *cub)
{
	cub->map_config.no_texture.param = NULL;
	cub->map_config.no_texture.checked = false;
	cub->map_config.so_texture.param = NULL;
	cub->map_config.so_texture.checked = false;
	cub->map_config.we_texture.param = NULL;
	cub->map_config.we_texture.checked = false;
	cub->map_config.ea_texture.param = NULL;
	cub->map_config.ea_texture.checked = false;
	cub->map_config.floor_clr.param = NULL;
	cub->map_config.floor_clr.checked = false;
	cub->map_config.ceiling_clr.param = NULL;
	cub->map_config.ceiling_clr.checked = false;
	cub->map_config.map = NULL;
}

void	init_cub(t_cub *cub)
{
	cub->win.mlx = NULL;
	cub->win.win = NULL;
	cub->win.win_height = 0;
	cub->win.win_width = 0;
	cub->img_ray.mlx_img = NULL;
	cub->img_ray.addr = NULL;
	cub->img_ray.bpp = 0;
	cub->img_ray.line_len = 0;
	cub->img_ray.endian = 0;
	cub->img_mini.mlx_img = NULL;
	cub->img_mini.addr = NULL;
	cub->img_mini.bpp = 0;
	cub->img_mini.line_len = 0;
	cub->img_mini.endian = 0;
	init_map(cub);
}

void	free_cub(t_cub *cub)
{
	(void)cub;
	// TODO:
}
