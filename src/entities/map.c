/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:58:53 by astein            #+#    #+#             */
/*   Updated: 2024/02/21 21:32:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ini_map(t_cub *cub)
{
	cub->map_file.no_texture = NULL;
	cub->map_file.so_texture = NULL;
	cub->map_file.we_texture = NULL;
	cub->map_file.ea_texture = NULL;
	cub->map_file.floor_clr.red = (uint8_t)260;
	cub->map_file.ceiling_clr.red = (uint8_t)260;
	cub->map_file.floor_clr.green = (uint8_t)0;
	cub->map_file.ceiling_clr.green = (uint8_t)0;
	cub->map_file.floor_clr.blue = (uint8_t)0;
	cub->map_file.ceiling_clr.blue = (uint8_t)0;
	cub->map_file.rgb_floor = (uint8_t)0;
	cub->map_file.rgb_ceiling = (uint8_t)0;
	cub->map_file.map = NULL;
}

bool	config_map(t_cub *cub, char *map_path)
{
	if (!parse(cub, map_path))
	{
		ft_putstr_fd("Error\nInvalid map\n", STDERR_FILENO);
		return (false);
	}
	cub->map_file.rgb_ceiling = create_rgb(cub->map_file.ceiling_clr.red, \
		cub->map_file.ceiling_clr.green, cub->map_file.ceiling_clr.blue);
	cub->map_file.rgb_floor = create_rgb(cub->map_file.floor_clr.red, \
		cub->map_file.floor_clr.green, cub->map_file.floor_clr.blue);
	return (true);
}

void	destroy_map(t_map_file *map)
{
	if (map->no_texture)
		free (map->no_texture);
	if (map->so_texture)
		free (map->so_texture);
	if (map->we_texture)
		free (map->we_texture);
	if (map->ea_texture)
		free (map->ea_texture);
	if (map->map)
		free_whatever("m", map->map);
}
