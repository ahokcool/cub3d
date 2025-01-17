/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:37:11 by anshovah          #+#    #+#             */
/*   Updated: 2024/02/19 16:13:07 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Accepts a matrix which contains rgb colors and validates them */
static bool	check_rgb_colors(char **rgb_parts)
{
	if (ft_size_matrix(rgb_parts) != 3 || !rgb_parts[0] || !rgb_parts[1]
		|| !rgb_parts[2])
	{
		free_whatever("m", rgb_parts);
		return (false);
	}
	if (!ft_str_is_numeric(rgb_parts[0]) || !ft_str_is_numeric(rgb_parts[1]) 
		|| !ft_str_is_numeric(rgb_parts[2]) || ft_atoi(rgb_parts[0]) < 0
		|| ft_atoi(rgb_parts[0]) > 255 || ft_atoi(rgb_parts[1]) < 0
		|| ft_atoi(rgb_parts[1]) > 255 || ft_atoi(rgb_parts[2]) < 0
		|| ft_atoi(rgb_parts[2]) > 255)
	{
		free_whatever("m", rgb_parts);
		return (false);
	}
	return (true);
}

/* Assignes rgb colors to the structure */
static void	assign_rgb(t_cub *cub, char **rgb_colors, int flag)
{
	if (flag == 0)
	{
		cub->map_file.floor_clr.red = (uint8_t)ft_atoi(rgb_colors[0]);
		cub->map_file.floor_clr.green = (uint8_t)ft_atoi(rgb_colors[1]);
		cub->map_file.floor_clr.blue = (uint8_t)ft_atoi(rgb_colors[2]);
	}
	else
	{
		cub->map_file.ceiling_clr.red = (uint8_t)ft_atoi(rgb_colors[0]);
		cub->map_file.ceiling_clr.green = (uint8_t)ft_atoi(rgb_colors[1]);
		cub->map_file.ceiling_clr.blue = (uint8_t)ft_atoi(rgb_colors[2]);
	}
	free_whatever("m", rgb_colors);
}

/*
	Responsible for validation and assignment the color parts of a config file
*/
bool	handle_color_line(t_cub *cub, char **parts, int *found)
{
	char	**rgb_colors;

	rgb_colors = ft_split(parts[1], ',');
	if (!rgb_colors || !check_rgb_colors(rgb_colors))
		return (false);
	if (!ft_strcmp(parts[0], "F"))
	{
		if (cub->map_file.floor_clr.red != (uint8_t)260)
		{
			free_whatever("m", rgb_colors);
			return (false);
		}
		assign_rgb(cub, rgb_colors, 0);
	}
	else if (!ft_strcmp(parts[0], "C"))
	{
		if (cub->map_file.ceiling_clr.red != (uint8_t)260)
		{
			free_whatever("m", rgb_colors);
			return (false);
		}
		assign_rgb(cub, rgb_colors, 1);
	}
	(*found)--;
	return (true);
}
