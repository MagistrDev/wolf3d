#include "wolf3d.h"
// gcc main.c -g -I./include -L./lib -lmingw32 -lSDL2main -lSDL2 -pthread



//	win.sss = SDL_CreateRGBSurface(0,win.width,win.height,32,0xff0000,0xff00,0xff,0xff000000);
//	int *map = win.sss->pixels;
//	for (int i = win.width * 0.25; i < win.width*0.5; i++)
//	{
//		map[i] = 0x0fff0000;
//	}
//	SDL_BlitSurface(win.sss, NULL, win.scr, NULL);

void	putchar_fd(int fd, char ch)
{
	write(fd, &ch, 1);
}

void	put_pixel(SDL_Surface *scr, int x, int y, int argb)
{
	int		*map;

	map = scr->pixels;
	map[scr->w * y + x] = argb;
}

void	read_map(t_window *win)
{
	int		fd;
	int		fr;
	char	buf[512];

	(void)win;
	fd = 0;
	if((fd = open("map.wlf", O_RDONLY)))
	{
		fr = read(fd, &buf, 512);
		(void)fr;
		close(fd);
	}

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

int		init(t_window *win)
{
	win->width = 512;
	win->height = 512;
	SDL_Init( SDL_INIT_EVERYTHING );
	if ((win->window = SDL_CreateWindow( "Wolf", SDL_WINDOWPOS_UNDEFINED,\
		SDL_WINDOWPOS_UNDEFINED, win->width, win->height, SDL_WINDOW_ALLOW_HIGHDPI)) == NULL)
		return 1;
	win->scr = SDL_GetWindowSurface(win->window);
	fill_background(win->scr);
	SDL_UpdateWindowSurface(win->window);
	return(0);
}

int main( int argc, char *argv[] )
{
	(void)argc;
	(void)argv;
	t_window		win;

	if (init(&win))
		return (1);
	SDL_UpdateWindowSurface(win.window);
	while (1)
	{
		if (SDL_PollEvent(&(win.windowEvent)))
		{
			if ( SDL_QUIT == win.windowEvent.type )
			{
				break;
			}
		}
	}
	SDL_DestroyWindow( win.window );
	SDL_Quit( );
	return EXIT_SUCCESS;
}