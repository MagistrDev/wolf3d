#include "wolf3d.h"
// gcc main.c -g -I./include -L./lib -lmingw32 -lSDL2main -lSDL2 -pthread



//	win.sss = SDL_CreateRGBSurface(0,win.width,win.height,32,0xff0000,0xff00,0xff,0xff000000);
//	int *map = win.sss->pixels;
//	for (int i = win.width * 0.25; i < win.width*0.5; i++)
//	{
//		map[i] = 0x0fff0000;
//	}
//	SDL_BlitSurface(win.sss, NULL, win.scr, NULL);

// void	putchar_fd(int fd, char ch)
// {
// 	write(fd, &ch, 1);
// }

void	put_pixel(SDL_Surface *scr, int x, int y, int argb)
{
	int		*map;

	map = scr->pixels;
	map[scr->w * y + x] = argb;
}

void	read_map(t_window *win)
{
	char	map[] = "0000000000000000"\
					"0              0"\
					"0    000000000 0"\
					"0        0     0"\
					"0        0     0"\
					"0     0000     0"\
					"0              0"\
					"0              0"\
					"0              0"\
					"0      0       0"\
					"0              0"\
					"0      0       0"\
					"0      0       0"\
					"0              0"\
					"0 0    00      0"\
					"0000000000000000\0";
	win->map.h = 16;
	win->map.w = 16;
	win->map.sq_w = win->width / win->map.w;
	win->map.sq_h = win->height / win->map.h;
	ft_strcpy(win->map.map, map);
}

void	fill_background(SDL_Surface *scr)
{
	int		argb;

	for (int y = 0; y < scr->h; y++)
	{
		for (int x = 0; x < scr->w; x++)
		{
			argb = 0;
			argb |= ((int)(255 * y / (float)scr->h) << 16); // varies between 0 and 255 as j sweeps the vertical
			argb |= ((int)(255 * x / (float)scr->w) << 8); // varies between 0 and 255 as i sweeps the horizontal
			//b = 0;
			put_pixel(scr, x, y, argb);
		}
	}
}

void draw_rectangle(t_window *win, int x, int y, int rgba)
{
	int		w;
	int		h;

	for (h = 0; h < win->map.sq_h; h++)
		for (w = 0; w < win->map.sq_w; w++)
			put_pixel(win->scr,x + w, y + h, rgba);
}

void draw_wall(t_window *win)
{
	int		i;
	char	c;
	for (i = 0; (c = win->map.map[i]); i++)
	{
		if (c == '0')
			draw_rectangle(win,(i % win->map.w) * win->map.sq_w, (i / win->map.w) * win->map.sq_h ,0xffff);
	}
}

void	draw_player(t_window *win)
{
	float	c;
	float	x;
	float	y;
	float	a;
	int		*map;
	
	put_pixel(win->scr, win->player.x - 1, win->player.y - 1, 0xffffff);
	put_pixel(win->scr, win->player.x - 1, win->player.y, 0xffffff);
	put_pixel(win->scr, win->player.x - 1, win->player.y + 1, 0xffffff);
	put_pixel(win->scr, win->player.x, win->player.y - 1, 0xffffff);
	put_pixel(win->scr, win->player.x, win->player.y, 0xffffff);
	put_pixel(win->scr, win->player.x, win->player.y + 1, 0xffffff);
	put_pixel(win->scr, win->player.x + 1, win->player.y - 1, 0xffffff);
	put_pixel(win->scr, win->player.x + 1, win->player.y, 0xffffff);
	put_pixel(win->scr, win->player.x + 1, win->player.y + 1, 0xffffff);
	map = win->scr->pixels;
	a = win->player.a - 0.002 * 512 / 2;
	// printf("\n0x%08X\n", map[]);
	for (int i = 0; i < 512; i++)
	{
		for (c = 0; c < 300; c+=1.5) {
			x = win->player.x + c*cos(a);
			y = win->player.y + c*sin(a);
			if (map[(int)x + (int)y * win->width] == 0xffff)
				break;
			put_pixel(win->scr, (int)x, (int)y, 0xffffff);
		}
		a += 0.002;
	}
	for (c = 0; c < 300; c+=1.5) {
			x = win->player.x + c*cos(win->player.a);
			y = win->player.y + c*sin(win->player.a);
			if (map[(int)x + (int)y * win->width] == 0xffff)
				break;
			put_pixel(win->scr, (int)x, (int)y, 0xff0000);
		}
}

void draw(t_window *win)
{
	read_map(win);
	fill_background(win->scr);
	draw_wall(win);
	draw_player(win);
	SDL_UpdateWindowSurface(win->window);
}

int		init(t_window *win)
{
	win->width = 512;
	win->height = 512;
	win->player.x = 80;
	win->player.y = 80;
	win->player.a = 1;
	// read_map(win);
	SDL_Init( SDL_INIT_EVERYTHING );
	if ((win->window = SDL_CreateWindow( "Wolf", SDL_WINDOWPOS_UNDEFINED,\
		SDL_WINDOWPOS_UNDEFINED, win->width, win->height, SDL_WINDOW_ALLOW_HIGHDPI)) == NULL)
		return 1;
	win->scr = SDL_GetWindowSurface(win->window);
	// fill_background(win->scr);
	// draw_wall(win);
	// draw_player(win);

	// SDL_UpdateWindowSurface(win->window);
	draw(win);
	return(0);
}

void move_player(t_window *win, int move)
{	
	float	c;
	float	x;
	float	y;
	int		*map;
	c = 5;
	x = 0;
	y = 0;
	if (move == 1)
	{
		x = win->player.x + c*cos(win->player.a);
		y = win->player.y + c*sin(win->player.a);
	}
	if (move == 0)
	{
		x = win->player.x + c*cos(win->player.a + M_PI);
		y = win->player.y + c*sin(win->player.a + M_PI);
	}
	map = win->scr->pixels;
	if (map[(int)x + (int)y * win->width] != 0xffff)
	{
		win->player.x = x;
		win->player.y = y;
	}
}

int main( int argc, char *argv[] )
{
	(void)argc;
	(void)argv;
	t_window	win;

	init(&win);
	SDL_UpdateWindowSurface(win.window);
	while (1)
	{
		if (SDL_WaitEvent(&(win.windowEvent)))
		{
			if ( SDL_QUIT == win.windowEvent.type )
				break;
			if ( SDL_KEYDOWN == win.windowEvent.type )
			{
				if (win.windowEvent.key.keysym.sym == SDLK_ESCAPE)
					break;
				if (win.windowEvent.key.keysym.sym == SDLK_LEFT)
					win.player.a -= 0.05;
				if (win.windowEvent.key.keysym.sym == SDLK_RIGHT)
					win.player.a += 0.05;
				if (win.windowEvent.key.keysym.sym == SDLK_UP)
					move_player(&win, 1);
				if (win.windowEvent.key.keysym.sym == SDLK_DOWN)
					move_player(&win, 0);
				draw(&win);
			}
		}
	}
	SDL_DestroyWindow( win.window );
	SDL_Quit( );
	return EXIT_SUCCESS;
}