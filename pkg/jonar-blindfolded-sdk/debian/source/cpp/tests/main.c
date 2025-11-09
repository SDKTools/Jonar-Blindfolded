#include "../src/header/main.h"

int main(int argc, char* argv[]) {
    const char* title = "Jonar Blindfolded SDK Window";
    int width = 800;
    int height = 600;

    int result = MakeWindow(title, width, height);
    if (result == -1) {
        return -1;
    }

    // Main loop placeholder
    SDL_Delay(3000); // Keep the window open for 3 seconds

    SDL_Quit();
    return 0;
}