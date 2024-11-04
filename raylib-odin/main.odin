package main

import "core:fmt"
import "core:time"
import rl "vendor:raylib"

WIDTH :: 1000
HEIGHT :: 1000
ITERATIONS :: 100

main :: proc() {
    rl.SetTraceLogLevel(.ERROR)
    rl.InitWindow(WIDTH, HEIGHT, "raylib")

    texBunny := rl.LoadTexture("../bunny.png")
    start := time.now()

    for i in 0..<ITERATIONS {
        rl.BeginDrawing()
        rl.ClearBackground(rl.WHITE)

        for x in 0..<WIDTH {
            for y in 0..<HEIGHT {
                rl.DrawTexture(texBunny, i32(x) , i32(y), rl.WHITE)
            }
        }

        rl.DrawFPS(10, 10)
        rl.EndDrawing()
    }

    elapsed_time := time.since(start)
    mbunnies_per_second := f64(WIDTH * HEIGHT * ITERATIONS) / time.duration_seconds(elapsed_time) / 1_000_000

    rl.UnloadTexture(texBunny)
    rl.CloseWindow()

    fmt.printf("Raylib | Odin | | %.1f\n", mbunnies_per_second)
}
