/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:27:07 by astein            #+#    #+#             */
/*   Updated: 2024/02/21 19:23:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ini_controller(t_controller *controller)
{
	controller->move_forward = false;
	controller->move_backwards = false;
	controller->move_left = false;
	controller->move_right = false;
	controller->rotate_left = false;
	controller->rotate_right = false;
	controller->game_over = false;
	controller->show_3d = true;
	controller->show_texture = true;
	controller->acitvate_mouse_rotate = false;
}

int	key_pressed(int keycode, t_controller *controller)
{
	if (keycode == K_ESC)
		controller->game_over = true;
	else if (keycode == 'w')
		controller->move_forward = true;
	else if (keycode == 's')
		controller->move_backwards = true;
	else if (keycode == 'a')
		controller->move_left = true;
	else if (keycode == 'd')
		controller->move_right = true;
	else if (keycode == K_ARROW_LEFT || keycode == 'q')
		controller->rotate_left = true;
	else if (keycode == K_ARROW_RIGHT || keycode == 'e')
		controller->rotate_right = true;
	return (0);
}

int	key_released(int keycode, t_controller *controller)
{
	printf("Key released: %c\n", keycode);
	if (keycode == 'w')
		controller->move_forward = false;
	else if (keycode == 's')
		controller->move_backwards = false;
	else if (keycode == 'a')
		controller->move_left = false;
	else if (keycode == 'd')
		controller->move_right = false;
	else if (keycode == K_ARROW_LEFT || keycode == 'q')
		controller->rotate_left = false;
	else if (keycode == K_ARROW_RIGHT || keycode == 'e')
		controller->rotate_right = false;
	else if (keycode == '2')
		controller->show_3d = false;
	else if (keycode == '3')
		controller->show_3d = true;
	else if (keycode == 't')
		controller->show_texture = !controller->show_texture;
	return (0);
}

int	mouse_click(int button, int x, int y, t_cub *cub)
{
	printf("button %d, Mouse clicked: %d, %d\n", button, x, y);
	if (button == 1)
	{
		cub->controller.acitvate_mouse_rotate = !cub->controller.acitvate_mouse_rotate;
		cub->controller.rotate_right = false;
		cub->controller.rotate_left = false;
	}
	else if (button == 4)
		cub->player.fov += 5;
	else if (button == 5)
		cub->player.fov -= 5;
	if (cub->player.fov < 50)
		cub->player.fov = 50;
	else if (cub->player.fov > 200)
		cub->player.fov = 200;
	return (0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	(void)y;
	if(cub->controller.acitvate_mouse_rotate)
	{
		if (x > 2 * (WIN_WIDTH / 3))
			cub->controller.rotate_right = true;
		else if ((x < WIN_WIDTH / 3))
			cub->controller.rotate_left = true;
		else
		{
			cub->controller.rotate_right = false;
			cub->controller.rotate_left = false;
		}
	}
	return (0);
}

void	destroy_controller(void *mlx, t_controller *controller)
{
	(void)controller;
	(void)mlx;
}
