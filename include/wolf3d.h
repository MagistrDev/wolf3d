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
# include <windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
#include "SDL2/SDL.h"

typedef struct s_map
{
	SDL_Surface	*sss;
	char		map[512];
	int			w;
	int			h;
}				t_map;


typedef struct	s_window
{
	SDL_Window	*window;
	SDL_Surface	*scr;
	SDL_Event	windowEvent;
	//char		capture[11] = "Hello World";
	int			width;
	int			height;
	t_map		map;

}				t_window;


#endif