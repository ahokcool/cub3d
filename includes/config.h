/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:18:47 by astein            #+#    #+#             */
/*   Updated: 2024/02/06 21:15:16 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define WIN_WIDTH 680
# define WIN_HEIGHT 600

//KEYS
# define K_ESC 65307
# define K_ARROW_LEFT 65361
# define K_ARROW_UP 65362
# define K_ARROW_RIGHT 65363
# define K_ARROW_DOWN 65364

//RAY CASTING
# define FOV 90
# define WALL_HEIGHT 250

//RENDER DETAILS
# define MINIMAP_PIXEL_WIDTH 10
# define MINIMAP_BORDER_SIZE 2 //if value is 3 it will be a 7x7 square
# define MAP2D_PIXEL_WIDTH 20
# define TILE_SIZE 10

#endif