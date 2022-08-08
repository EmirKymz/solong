/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:08:06 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/02 13:22:43 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	makeanimation(t_sprite *sprite)
{
	static int	i;

	while (i++ == 6969 / 6)
	{
		sprite->coinloop = sprite->coinloop->next;
		i = 0;
	}
}

void	render_player2(t_main *main, int x, int y, int i)
{
	int	j;

	j = 0;
	while (j < main->map->x)
	{
		if (main->map->map[i][j] == '1')
			mlx_put_image_to_window(main->mlx, main->win,
				main->sprite->duvar, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
			mlx_put_image_to_window(main->mlx, main->win,
				main->sprite->yol, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'E')
			mlx_put_image_to_window(main->mlx, main->win,
				main->sprite->exit, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'C')
			mlx_put_image_to_window(main->mlx, main->win,
				main->sprite->coin1, j * PIXEL, i * PIXEL);
		makeanimation(main->sprite);
		j++;
	}
}

int	render_player(t_main *main)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = main->player_x - 1;
	y = main->player_y - 1;
	while (i < main->map->y)
	{
		render_player2(main, x, y, i);
		i++;
	}
	draw_first_line(main);
	mlx_put_image_to_window(main->mlx, main->win, main->sprite->playerl,
		(x + 1) * PIXEL, (y + 1) * PIXEL);
	return (0);
}

int	render(t_main *main)
{
	render_player(main);
	if (main->ccount == 0
		&& main->map->map[main->player_y][main->player_x] == 'E')
		key_event(53, main);
	write_move_count(main);
	return (0);
}
