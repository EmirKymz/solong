/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaymaz <ekaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:10:43 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/08/08 12:59:29 by ekaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define PIXEL 64
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define TITLE "so_long"

typedef struct s_loop
{
	void			*image;
	struct s_loop	*next;
}	t_loop;

typedef struct s_sprite
{
	void	*duvar;
	void	*yol;
	void	*coin1;
	void	*coin2;
	void	*exit;
	void	*playerr;
	void	*playerl;
	t_loop	*coinloop;
	int		sprite_h;
	int		sprite_w;
}	t_sprite;

typedef struct s_map
{
	char	**map;
	char	*yedekmap;
	int		x;
	int		y;
}	t_map;

typedef struct s_main
{
	int			last;
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			ccount;
	int			cccount;
	int			mcount;
	int			pcount;
	int			ecount;
	t_map		*map;
	t_sprite	*sprite;
}	t_main;

// INIT
t_main	*main_init(char *path);
void	convert(t_main *main);

// UTILS
char	*make_number(int number);
int		ft_strlen(char *str);
int		ft_yedekmap(t_main *main, char *buffer);
void	recursive(int number, int *index, char *str);
int		ft_key_esc(t_main *game);

//UTILS2.c
int		n_count(char *buffer);
int		line_count(char *buffer);
void	move_enemy(t_main *main);
void	check_cn(t_main *main);

// EVENT
int		key_event(int keycode, t_main *main);
void	convert_lorr(t_main *main, int move);

// RENDER // animasyon
int		draw_first_line(t_main *main);
int		render(t_main *main);
int		render_player(t_main *main);

//DRAW
void	error1(char *errorcode, t_main *main);
void	draw_map(t_main *main);

//MAP //Map check
char	**map_init(char *path, t_main *main);

//MAIN
int		check_ber(char *str);
void	write_move_count(t_main *main);
void	free_func(t_main *main);

//MAP_CHECK.c
int		map_check(t_main *main);
int		ft_map_cntrl_ust_alt(t_main *game);

#endif