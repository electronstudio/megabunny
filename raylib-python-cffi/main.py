import time
from raylib import *
WIDTH = 1000
HEIGHT = 1000
ITERATIONS = 100

SetTraceLogLevel(LOG_ERROR)
InitWindow(WIDTH, HEIGHT, b"raylib")

texBunny = LoadTexture(b"../bunny.png")

start_time = time.time()
for i in range(0, ITERATIONS):


    BeginDrawing()

    ClearBackground(RAYWHITE)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
          DrawTexture(texBunny, x, y, WHITE)


    DrawFPS(10, 10)

    EndDrawing()

end_time = time.time()

elapsed_time = end_time - start_time
mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000


UnloadTexture(texBunny)

CloseWindow()

print("Raylib | Python | raylib-python-cffi |", mbunnies_per_second)