# Megabunny

Bunnymark is a traditional benchmark for game *engines* like Godot or Unity.
It's a very simple game that renders and moves a large number of
sprites.

However, it's not so useful for comparing rendering *frameworks* such as Raylib and SDL because it includes game logic
as well as rendering, something that is completely independent of the framework or library you are using.

It's also not so useful for comparing different language bindings of one framework, where we are really interested
in just the speed of the FFI calls.

Thus Megabunny simply draws one million identical static bunnies per frame and outputs the mbunnies/second.

Note that this benchmark is not a good reason for end users to choose one framework, language or binding over another.
It's most useful for library authors to check that your library isn't doing something ridiculously slow
and to check if your optimisations are having any effect.

# My results

Library | Language | Binding    | mbunnies 
--- | --- |------------|------------
SDL2 opengl | C | | 21.9
SFML | C | | 12.4
Raylib | C | | 9.6 |
Raylib | Java | Jaylib-FFM | 9.5
Raylib | Java | Jaylib | 8.9
Raylib | Python | raylib-python-jaylib | 5.9
Raylib | Python | raylib-python-cffi | 5.1
Raylib | Python | raylib-python-cffi (pyray) | 3.9




# See also

https://codeberg.org/glowiak/rl-bunnymarks