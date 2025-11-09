#include "../header/main.h"

int MakeWindow(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return -1;
    } else if (IMG_Init(IMG_INIT_PNG) != 0) {
        return -2;
    }
    

    SDL_Window* window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,
                                          height,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Quit();
        return -3;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    return window || -4;
}

int ATHOMYCAL_VERTICAL_LAYOUT = 0;
int ATHOMYCAL_HORIZONTAL_LAYOUT = 1;
int ONLY_IMG = 2;
int NO_DISPLAY = 3;
// In Production uncomment this: const char* ATHOMYCAL_IMG_PATH = "/usr/share/jonar-blindfolded-de/athomycal.png";
// Comment the line below in Production
const char* ATHOMYCAL_IMG_PATH = "./athomycal.png";

int DisplayAthomycalUI(const char* message, int layout) {

}