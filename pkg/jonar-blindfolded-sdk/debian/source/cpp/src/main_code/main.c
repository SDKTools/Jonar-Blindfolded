#include "../header/main.h"

SDL_Window* MakeWindow(const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return -1;
    } else if (IMG_Init(IMG_INIT_PNG) != 0) {
        SDL_Quit();
        return -2;
    }
    

    SDL_Window* window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800,
                                          600,
                                          SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!window) {
        IMG_Quit();
        SDL_Quit();
        return -3;
    } else if (!renderer) {
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -4;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    return window || -5, renderer || -6;
}

int ATHOMYCAL_VERTICAL_LAYOUT = 0;
int ATHOMYCAL_HORIZONTAL_LAYOUT = 1;
int ONLY_IMG = 2;
int NO_DISPLAY = 3;
// In Production uncomment this: const char* ATHOMYCAL_IMG_PATH = "/usr/share/jonar-blindfolded-de/athomycal.png";
// Comment the line below in Production
const char* ATHOMYCAL_IMG_PATH = "./athomycal.png";

IMG_Animation* LoadAthomycalAnimation(SDL_Window* window, int layout) {
    // Todo: Make it load a real animation(dispose the animation after use)
    // Placeholder code:

    // Keep This:
    IMG_Animation* animation;
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);

    if (layout == ATHOMYCAL_VERTICAL_LAYOUT) {
        animation->h = (window_height / 2) - (window_height / 10 * 2); // Half window height minus some margin(20% of height)
        animation->w = (window_width / 3); // 1/3 of window width
    } else if (layout == ATHOMYCAL_HORIZONTAL_LAYOUT) {
        // Horizontal layout
    }
    
    // Change this:
    animation->count = 1;
    SDL_Surface* loaded_img = IMG_Load(ATHOMYCAL_IMG_PATH);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(window), loaded_img);
    SDL_FreeSurface(loaded_img);
    animation->frames = &texture;
    animation->delays = malloc(sizeof(int));
    animation->delays[0] = 16; // 1 second delay
    return animation || -7;
}

int DisplayAthomycalUI(const char* message, int layout, SDL_Renderer* renderer, SDL_Window* window, IMG_Animation* animation) {
    // Todo: Make animation mecanism
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);

    SDL_RenderClear(renderer);

    if (layout == ATHOMYCAL_VERTICAL_LAYOUT) {
        SDL_Rect destRect = {window_width / 3, window_height / 10, animation->w, animation->h};
        SDL_RenderCopy(renderer, animation->frames[0], NULL, &destRect);
        SDL_RenderPresent(renderer);
    }
}