#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int MakeWindow(const char* title, int width, int height);

int ATHOMYCAL_VERTICAL_LAYOUT;
int ATHOMYCAL_HORIZONTAL_LAYOUT;
int ONLY_IMG;
int NO_DISPLAY;
const char* ATHOMYCAL_IMG_PATH;
int DisplayAthomycalUI(const char* message, int layout);