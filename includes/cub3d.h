/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:22:21 by astein            #+#    #+#             */
/*   Updated: 2024/01/31 16:03:18 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft_printf.h"
# include "../mlx/mlx.h"
# include "config.h"
# include <stdbool.h>

typedef struct s_clr
{
	double			red;
	double			green;
	double			blue;
}						t_clr;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}			t_img;	

typedef struct s_win
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
}					t_win;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}						t_player;

typedef struct s_hash_map
{
	char	*param;
	bool	valid;
} 		t_hash_map;

typedef struct s_map_config
{
	t_hash_map no_texture;
	t_hash_map so_texture;
	t_hash_map we_texture;
	t_hash_map ea_texture;
	t_hash_map floor_clr;
	t_hash_map ceiling_clr;
	char	**map;
	char	*sides[4];
}				t_map_config;

typedef struct s_cub
{
	t_win				win;
	t_img				img_ray;
	t_img				img_mini;
	t_map_config		map_config;
	t_player			player;
	bool				show_mini;
}						t_cub;

void	init_cub(t_cub *cub);
bool 	parse(t_cub *cub, char *path);
void	mlx_main(t_cub *cub);
void	ini_win(t_cub *cub);
void	ini_img(t_cub *cub, t_img *img);
void	update_view(t_cub *cub);
int		deal_key(int key, t_cub *cub);
void eqip_imgs(t_cub *cub);


#endif
