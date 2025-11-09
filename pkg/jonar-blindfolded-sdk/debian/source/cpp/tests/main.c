#include "../src/header/main.h"

int main(int argc, char* argv[]) {
    const char* title = "Jonar Blindfolded SDK Window";
    int width = 800;
    int height = 600;

    auto window, renderer = MakeWindow(title);
    if (window == -1) {
        return -1;
    }

    IMG_Animation* animation = LoadAthomycalAnimation(window, ATHOMYCAL_VERTICAL_LAYOUT);
    while (width == 800) {
        // Main loop placeholder
        DisplayAthomycalUI("Welcome to Jonar Blindfolded SDK!", ATHOMYCAL_VERTICAL_LAYOUT, renderer, window, animation);
        SDL_Delay(1000 / 60); // 60 FPS
    }

    SDL_Quit();
    return 0;
}