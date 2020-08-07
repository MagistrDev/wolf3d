/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:34:17 by marvin            #+#    #+#             */
/*   Updated: 2020/05/02 00:34:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
//# include <windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <math.h>
# include <SDL.h>
# include "libft.h"

typedef struct s_player
{
	float	x;
	float	y;
	float	a;
	float	c;
	float	cur_x;
	float	cur_y;
}				t_player;

typedef struct s_map
{
	SDL_Surface	*scr;
	char		map[1000];
	int			w;
	int			h;
	int			sq_w;
	int			sq_h;
}				t_map;


typedef struct	s_window
{
	SDL_Window	*window;
	SDL_Surface	*scr;
	SDL_Surface	*scrm;
	SDL_Surface	*scr3d;
	SDL_Rect	maprect;
	SDL_Event	windowEvent;
	//char		capture[11] = "Hello World";
	int			width;
	int			height;
	t_map		map;
	t_player	player;

}				t_window;


#endif