/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:57:33 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/08 13:01:15 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_if(t_main *main, int j, int i)
{
	mlx_put_image_to_window(main->mlx, main->win, main->sprite->playerl, j, i);
	main->player_y = i;
	main->player_x = j;
}

void	error1(char *errorcode, t_main *main)
{
	int	i;

	i = 0;
	while (errorcode[i])
	{
		write(1, &errorcode[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free_func(main);
	exit(0);
}

int	draw_map2(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == '1')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->duvar, j, i);
	else if (main->map->map[i][j] == '0')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->yol, j, i);
	else if (main->map->map[i][j] == 'P')
		player_if(main, j, i);
	else if (main->map->map[i][j] == 'E')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->exit, j, i);
	else if (main->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->coin1, j, i);
		main->ccount++;
	}
	else if (main->map->map[i][j] == '\n')
		;
	else
		error1("Error \n hatali harf", main);
	j++;
	return (j);
}

void	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (main->map->y))
	{
		while (j < (main->map->x))
		{
			j = draw_map2(main, i, j);
		}
		i++;
		j = 0;
	}
}
