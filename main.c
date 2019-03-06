#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "function.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

int main(int argc, char const *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Error while initialising SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Load window
    SDL_Surface *icon = IMG_Load("pack_images_sdz/sdl_icone.bmp");
    // Set window title
    SDL_WM_SetCaption("Display BMP", NULL);
    // Set window icon + transparency
    SDL_WM_SetIcon(icon, NULL);

    SDL_Surface *screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, Rich, SDL_HWSURFACE); 
    
    if(screen == NULL) {
        fprintf(stderr, "Error while setting Video Mode: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);   
    }

/// Background
    // Position
    int backgroundX = 0;
    int backgroundY = 0;
    SDL_Rect backgroundPosition = {backgroundX, backgroundY};    
    SDL_Surface *backgroundImg = IMG_Load("pack_images_sdz/lac_en_montagne.bmp");

/// Tree
    int treeX = 100;
    int treeY = 50;
    SDL_Rect treePosition = {treeX, treeY};
    SDL_Surface *tree = IMG_Load("pack_images_sdz/sapin.png");
    Uint32 white = SDL_MapRGB(tree->format, 255, 255, 255);
    // Apply TOTAL transparency on blue
    SDL_SetColorKey(tree, SDL_SRCCOLORKEY, white);
    // Apply opacity on tree (value range: 0 - 255)
    SDL_SetAlpha(tree, SDL_SRCALPHA, 255);

/// Update window
    SDL_BlitSurface(backgroundImg, NULL, screen, &backgroundPosition);
    SDL_BlitSurface(tree, NULL, screen, &treePosition);
    SDL_Flip(screen);
    
    pause();
    
    SDL_FreeSurface(backgroundImg);
    SDL_Quit();

    return EXIT_SUCCESS;
}
