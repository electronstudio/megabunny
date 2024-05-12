#include <sys/time.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH 1000
#define HEIGHT 1000
#define ITERATIONS 100

SDL_Rect rects[WIDTH * HEIGHT];

int main(void) {

    SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1");
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window *win = SDL_CreateWindow("sdl2", 0, 0, 1000, 1000, 0);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
    SDL_RendererInfo rendererInfo;
    SDL_GetRendererInfo(ren, &rendererInfo);
    SDL_Surface *gScreenSurface = SDL_GetWindowSurface(win);

    SDL_Surface *loadedSurface = IMG_Load("../bunny.png");
    //SDL_Surface *optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, loadedSurface);
    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

    struct timeval start, end;
    double elapsed_time, mbunnies_per_second;

    gettimeofday(&start, NULL);

    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

    int j = 0;

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            rects[j++] = (SDL_Rect){x, y, 32, 32};
        }
    }


    for (int i = 0; i < ITERATIONS; i++) {
        SDL_RenderClear(ren);
        for (int k = 0; k < WIDTH * HEIGHT; k++) {
            SDL_RenderCopy(ren, tex, NULL, &rects[k]);
        }

        SDL_RenderPresent(ren);
    }

    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    mbunnies_per_second = WIDTH * HEIGHT * ITERATIONS / elapsed_time / 1000000;


    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();;
    printf("SDL2 %s | C | | %.1f\n", rendererInfo.name, mbunnies_per_second);

    return 0;
}
