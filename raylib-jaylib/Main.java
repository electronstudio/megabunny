import static com.raylib.Jaylib.WHITE;
import static com.raylib.Raylib.*;

static int WIDTH=1000;
static int HEIGHT=1000;
static int ITERATIONS=100;

public static void main(String args[]) {
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WIDTH, HEIGHT, "raylib");

    var v = new Vector2().x(4).y(6);

    var p = new Sound();
    System.out.println(p);
    var texBunny = LoadTexture("../bunny.png");
    long start, end;
    double elapsed_time, mbunnies_per_second;


    start = System.nanoTime();

    for(int i=0; i<ITERATIONS; i++)
    {

        BeginDrawing();

            ClearBackground(WHITE);

            for (int x=0; x<WIDTH; x++){
                for (int y=0; y<HEIGHT; y++){
                  DrawTexture(texBunny, x, y, WHITE);
                 }
            }
            DrawFPS(10, 10);

        EndDrawing();

    }
    end = System.nanoTime();

    elapsed_time = (end - start) * 1e-9f;
    mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000f;

    UnloadTexture(texBunny);

    CloseWindow();
    System.out.println("Raylib | Java | Jaylib | "+mbunnies_per_second);


}
