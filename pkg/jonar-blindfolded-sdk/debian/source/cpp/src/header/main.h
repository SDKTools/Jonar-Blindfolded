#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

SDL_Window* MakeWindow(const char* title);
SDL_Renderer* MakeRenderer(SDL_Window* window);

typedef struct Texture_Animation
{
    int w;                  /**< The width of the frames */
    int h;                  /**< The height of the frames */
    int count;              /**< The number of frames */
    SDL_Texture **frames;   /**< An array of frames */
    int *delays;            /**< An array of frame delays, in milliseconds */
} Texture_Animation;

extern int ATHOMYCAL_VERTICAL_LAYOUT;
extern int ATHOMYCAL_HORIZONTAL_LAYOUT;
extern int ONLY_IMG;
extern int NO_DISPLAY;

// In Production uncomment this: const char* ATHOMYCAL_IMG_PATH = "/usr/share/jonar-blindfolded-de/athomycal.png";
// Comment the line below in Production
extern const char* ATHOMYCAL_IMG_PATH;

Texture_Animation* LoadAthomycalAnimation(SDL_Window* window, int layout);
int DisplayAthomycalUI(const char* message, int layout, SDL_Renderer* renderer, SDL_Window* window, Texture_Animation* animation);

#endif