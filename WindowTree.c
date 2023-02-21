#include "arbre.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 1400
#define HEIGHT 675

// Display the graphical tree in a new window
void WindowDisplay(char tableau[][10000], int nbLignes, int nbColonnes)
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    int CELL_W = (WIDTH / nbColonnes)+1;


    // Create window
    SDL_Window* window = SDL_CreateWindow("Graphical Binary Tree Dictionnary Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH,
                                          HEIGHT,
                                          SDL_WINDOW_SHOWN);

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    // Create font
    TTF_Font* font = TTF_OpenFont("Verdana.ttf", 18);

    // Render grid
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect cellRect;
    
    for (int i = 4; i < nbLignes+4; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            // Render cell
            surface = TTF_RenderText_Solid(font, &tableau[i-4][j], textColor);
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            cellRect.x = j * CELL_W;
            cellRect.y = i * 30;
            cellRect.w = CELL_W;
            cellRect.h = 30;
            SDL_RenderCopy(renderer, texture, NULL, &cellRect);
            SDL_DestroyTexture(texture);
        }

    }

    // Render to screen
    SDL_RenderPresent(renderer);

    // Wait for quit event
    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    // Clean up
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}
