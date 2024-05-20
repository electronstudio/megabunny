import time
import java
rl = java.type("com.raylib.Raylib")
jl = java.type("com.raylib.Jaylib")
WIDTH = 1000
HEIGHT = 1000
ITERATIONS = 100

#SetTraceLogLevel(LOG_ERROR)
rl.InitWindow(WIDTH, HEIGHT, "raylib")

texBunny = rl.LoadTexture("../bunny.png")

start_time = time.time()
for i in range(0, ITERATIONS):


    rl.BeginDrawing()

    rl.ClearBackground(jl.RAYWHITE)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
          rl.DrawTexture(texBunny, x, y, jl.WHITE)


    rl.DrawFPS(10, 10)

    rl.EndDrawing()

end_time = time.time()

elapsed_time = end_time - start_time
mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000


rl.UnloadTexture(texBunny)

rl.CloseWindow()

print("Raylib | Python | raylib-python-cffi |", mbunnies_per_second)
