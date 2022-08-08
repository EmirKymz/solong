/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:59:09 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/02 16:20:01 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_cntrl_sag_sol(t_main *game)
{
	int	i;

	i = 0;
	while (i < game->map->y - 1)
	{
		if (game->map->map[i][0] != '1')
		{
			error1("Error\nMAP: (LEFT)", game);
			return (0);
		}
		else if (game->map->map[i][game->map->x - 1] != '1')
		{
			error1("Error\nMAP: (RIGHT)", game);
			return (0);
		}
	i++;
	}
	return (1);
}

int	ft_map_cntrl_ust_alt(t_main *game)
{
	int	i;

	i = 0;
	while (i < game->map->x)
	{
		if (game->map->map[0][i] != '1')
		{
			error1("Error\nMAP: (UP)", game);
			return (0);
		}
		if (game->map->map[game->map->y - 1][i] != '1')
		{
			error1("Error\nMAP: (DOWN)", game);
			return (0);
		}
	i++;
	}
	return (1);
}

int	map_check(t_main *main)
{
	if (main->ecount <= 0)
		error1("Error\nExit Bulunamadı", main);
	else if (main->cccount <= 0)
		error1("Error\nCoin Bulunamadi", main);
	else if (main->pcount <= 0 || main->pcount > 1)
		error1("Error\nPlayer Bulunamadi veya Birden Fazla Player", main);
	ft_map_cntrl_sag_sol(main);
	ft_map_cntrl_ust_alt(main);
	return (0);
}
