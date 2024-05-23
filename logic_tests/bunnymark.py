import platform
import random
import time

ITERATIONS=100

MAX_BUNNIES =  1000000



class Bunny:
    def __init__(self):
        self.position_x = random.randint(0, screenWidth)
        self.position_y = random.randint(0, screenHeight)
        self.speed_x = random.randint(-250, 250)/60.0
        self.speed_y = random.randint(-250, 250)/60.0

screenWidth = 1920;
screenHeight = 1080;



bunnies = []
for i in range(0, MAX_BUNNIES):
    bunnies.append(Bunny())




start_time = time.time()


for j in range(0, ITERATIONS):
    for i in range(0, MAX_BUNNIES):
        bunnies[i].position_x += bunnies[i].speed_x
        bunnies[i].position_y += bunnies[i].speed_y

        if ((bunnies[i].position_x + 32/2) > screenWidth) or ((bunnies[i].position_x + 32/2) < 0):
            bunnies[i].speed_x *= -1
        if ((bunnies[i].position_y + 32/2) > screenHeight) or ((bunnies[i].position_y + 32/2 - 40) < 0):
            bunnies[i].speed_y *= -1



end_time = time.time()

elapsed_time = end_time - start_time
mbunnies_per_second = ITERATIONS/elapsed_time



print(platform.python_implementation(), platform.python_version(),     "|", mbunnies_per_second)