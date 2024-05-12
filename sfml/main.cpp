#include <SFML/Graphics.hpp>
#include <sys/time.h>
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 1000
#define ITERATIONS 100


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    texture.loadFromFile("../bunny.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    struct timeval start, end;
    double elapsed_time, mbunnies_per_second;

    gettimeofday(&start, NULL);

    for(int i=0; i<ITERATIONS; i++)
    {

        window.clear();

        for (int x=0; x<WIDTH; x++){
            for (int y=0; y<HEIGHT; y++){
            sprite.setPosition(sf::Vector2f(x, y));
              window.draw(sprite);
             }
        }


        window.display();

    }
    gettimeofday(&end, NULL);

    window.close();

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    mbunnies_per_second = WIDTH*HEIGHT*ITERATIONS/elapsed_time/1000000;


    printf("SFML | C | | %.1f\n", mbunnies_per_second);

    return 0;

}