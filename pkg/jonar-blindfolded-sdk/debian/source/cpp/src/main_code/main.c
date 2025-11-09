#include <main.h>

SDL_Window* MakeWindow(const char* title) {
    int img_init = IMG_Init(IMG_INIT_PNG);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return NULL;
    } else if (img_init == 0) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        printf("IMG_Init num: %d\n", img_init);
        SDL_Quit();
        return NULL;
    }
    

    SDL_Window* window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800,
                                          600,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        IMG_Quit();
        SDL_Quit();
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    return window;
}

SDL_Renderer* MakeRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return NULL;
    }
    return renderer;
}

int ATHOMYCAL_VERTICAL_LAYOUT = 0;
int ATHOMYCAL_HORIZONTAL_LAYOUT = 1;
int ONLY_IMG = 2;
int NO_DISPLAY = 3;

// In Production uncomment this: const char* ATHOMYCAL_IMG_PATH = "/usr/share/jonar-blindfolded-de/athomycal.png";
// Comment the line below in Production
const char* ATHOMYCAL_IMG_PATH = "./athomycal.png";

Texture_Animation* LoadAthomycalAnimation(SDL_Window* window, SDL_Renderer* renderer, int layout) {
    // Todo: Make it load a real animation(dispose the animation after use)
    // Placeholder code:

    // Keep This:
    Texture_Animation* animation = malloc(sizeof(struct Texture_Animation));
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);

    if (layout == ATHOMYCAL_VERTICAL_LAYOUT) {
        animation->h = (window_height / 3 * 2) - (window_height / 10 * 2); // Half window height minus some margin(20% of height)
        animation->w = (window_width / 3); // 1/3 of window width
    } else if (layout == ATHOMYCAL_HORIZONTAL_LAYOUT) {
        // Horizontal layout
    }
    
    // Change this:
    animation->count = 1;
    SDL_Surface* loaded_img = IMG_Load(ATHOMYCAL_IMG_PATH);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_img);
    SDL_FreeSurface(loaded_img);
    animation->frames = malloc(sizeof(SDL_Texture*));
    animation->frames[0] = texture;
    animation->delays = malloc(sizeof(int));
    animation->delays[0] = 16; // 1 second delay
    return animation;
}

int DisplayAthomycalUI(const char* message, int layout, SDL_Renderer* renderer, SDL_Window* window, Texture_Animation* animation) {
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

int QUIT_REQUESTED = 4;

int CheckIfQuit() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return QUIT_REQUESTED;
        }
    }
    return 0;
}
