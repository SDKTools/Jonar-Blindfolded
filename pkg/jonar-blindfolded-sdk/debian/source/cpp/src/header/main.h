#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* MakeWindow(const char* title);

int ATHOMYCAL_VERTICAL_LAYOUT;
int ATHOMYCAL_HORIZONTAL_LAYOUT;
int ONLY_IMG;
int NO_DISPLAY;
const char* ATHOMYCAL_IMG_PATH;
IMG_Animation* LoadAthomycalAnimation(SDL_Window* window, int layout);
int DisplayAthomycalUI(const char* message, int layout, SDL_Renderer* renderer, SDL_Window* window, IMG_Animation* animation);