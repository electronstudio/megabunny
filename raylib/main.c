#include <sys/time.h>
#include <stdio.h>
#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 1000
#define ITERATIONS 100


int main(void)
{

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WIDTH, HEIGHT, "raylib");

    Texture2D texBunny = LoadTexture("../bunny.png");
    struct timeval start, end;
    double elapsed_time, mbunnies_per_second;

    gettimeofday(&start, NULL);

    for(int i=0; i<ITERATIONS; i++)
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int x=0; x<WIDTH; x++){
                for (int y=0; y<HEIGHT; y++){
                  DrawTexture(texBunny, x, y, WHITE);
                 }
            }
            DrawFPS(10, 10);

        EndDrawing();

    }
    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000;

    UnloadTexture(texBunny);

    CloseWindow();
    printf("Raylib | C | | %.1f |\n", mbunnies_per_second);

    return 0;
}
