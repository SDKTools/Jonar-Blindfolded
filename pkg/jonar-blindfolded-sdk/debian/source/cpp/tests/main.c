#include <main.h>

int main(int argc, char* argv[]) {
    const char* title = "Jonar Blindfolded SDK Window";
    int width = 800;
    int height = 600;
    int layout = ATHOMYCAL_VERTICAL_LAYOUT;

    SDL_Window* window = MakeWindow(title);
    SDL_Renderer* renderer = MakeRenderer(window);
    if (!window) {
        printf("Failed to create window\n");
        return -1;
    } else if (!renderer) {
        printf("Failed to create renderer\n");
        layout = NO_DISPLAY;
    }

    Texture_Animation* animation = LoadAthomycalAnimation(window, renderer, layout);

    if (animation == NULL) {
        printf("Failed to load animation\n");
        layout = NO_DISPLAY;
    }

    while (width == 800) {
        // Main loop placeholder
        DisplayAthomycalUI("Welcome to Jonar Blindfolded SDK!", layout, renderer, window, animation);

        if (CheckIfQuit() == QUIT_REQUESTED) {
            break;
        }

        SDL_Delay(1000 / 60); // 60 FPS
    }

    SDL_DestroyTexture(animation->frames[0]);
    free(animation->frames);
    free(animation->delays);
    free(animation);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}