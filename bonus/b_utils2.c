/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:08:20 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/08 13:02:20 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	line_count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int	n_count(char *buffer)
{
	int	i;
	int	enter;

	enter = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

void	check_cn(t_main *main)
{
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
	printf("move %d\n", main->mcount);
}
