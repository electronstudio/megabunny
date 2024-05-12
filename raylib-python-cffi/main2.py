import time
from pyray import *
WIDTH = 1000
HEIGHT = 1000
ITERATIONS = 100

set_trace_log_level(LOG_ERROR)
init_window(WIDTH, HEIGHT, "raylib")

texBunny = load_texture("../bunny.png")

start_time = time.time()
for i in range(0, ITERATIONS):


    begin_drawing()

    clear_background(RAYWHITE)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
          draw_texture(texBunny, x, y, WHITE)


    draw_fps(10, 10)

    end_drawing()

end_time = time.time()

elapsed_time = end_time - start_time
mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000


unload_texture(texBunny)

close_window()

print("Raylib | Python | raylib-python-cffi (pyray) |", mbunnies_per_second)