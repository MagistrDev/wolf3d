#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
//#include <iostream>
// gcc main.c -I./include -L./lib -lmingw32 -lSDL2main -lSDL2 -pthread
#include "SDL2/SDL.h"

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    int fd;
    char bla[501];
    fd = open("hop.txt", O_RDWR);
    int fr = read(fd, &bla, 500);
    printf("%s \n", bla);
    write(fd, "hophophop\n",10);
    close(fd);
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    
    // Check that the window was successfully created
    if ( NULL == window )
    {
        // In the case that the window could not be made...
        //std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }
    
    SDL_Event windowEvent;
    
    while (1)
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
    }
    
    SDL_DestroyWindow( window );
    SDL_Quit( );
    
    return EXIT_SUCCESS;
}