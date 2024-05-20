import time
import java
rl = java.type("com.raylib.Raylib")
WIDTH = 1000
HEIGHT = 1000
ITERATIONS = 100

#SetTraceLogLevel(LOG_ERROR)
rl.initWindow(WIDTH, HEIGHT, "raylib")

texBunny = rl.loadTexture("../bunny.png")

start_time = time.time()
for i in range(0, ITERATIONS):


    rl.beginDrawing()

    rl.clearBackground(rl.RAYWHITE)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
          rl.drawTexture(texBunny, x, y,rl.WHITE)


    rl.drawFPS(10, 10)

    rl.endDrawing()

end_time = time.time()

elapsed_time = end_time - start_time
mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000


rl.unloadTexture(texBunny)

rl.closeWindow()

print("Raylib | Python | raylib-python-jaylib |", mbunnies_per_second)
