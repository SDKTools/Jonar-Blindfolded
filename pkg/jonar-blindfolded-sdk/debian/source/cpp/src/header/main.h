#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* MakeWindow(const char* title);

typedef struct Texture_Animation
{
    int w;                  /**< The width of the frames */
    int h;                  /**< The height of the frames */
    int count;              /**< The number of frames */
    SDL_Texture **frames;   /**< An array of frames */
    int *delays;            /**< An array of frame delays, in milliseconds */
} Texture_Animation;

int ATHOMYCAL_VERTICAL_LAYOUT;
int ATHOMYCAL_HORIZONTAL_LAYOUT;
int ONLY_IMG;
int NO_DISPLAY;
const char* ATHOMYCAL_IMG_PATH;
Texture_Animation* LoadAthomycalAnimation(SDL_Window* window, int layout);
int DisplayAthomycalUI(const char* message, int layout, SDL_Renderer* renderer, SDL_Window* window, Texture_Animation* animation);