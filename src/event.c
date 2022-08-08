/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:46 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/03 01:56:56 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_w(t_main *main, int keycode)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->player_y--;
	main->mcount++;
	printf("move %d\n", main->mcount);
	convert_lorr(main, 2);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_a(t_main *main)
{
	main->player_x--;
	main->mcount++;
	printf("move %d\n", main->mcount);
	convert_lorr(main, 4);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_s(t_main *main)
{
	main->player_y++;
	main->mcount++;
	printf("move %d\n", main->mcount);
	convert_lorr(main, 3);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_d(t_main *main)
{
	main->player_x++;
	main->mcount++;
	printf("move %d\n", main->mcount);
	convert_lorr(main, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

int	key_event(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_w(main, keycode);
	else if (keycode == W
		&& main->map->map[main->player_y - 1][main->player_x] != '1')
		ft_w(main, keycode);
	else if (keycode == A
		&& main->map->map[main->player_y][main->player_x - 1] != '1')
		ft_a(main);
	else if (keycode == S
		&& main->map->map[main->player_y + 1][main->player_x] != '1')
		ft_s(main);
	else if (keycode == D
		&& main->map->map[main->player_y][main->player_x + 1] != '1')
		ft_d(main);
	return (0);
}
