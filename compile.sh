gcc -c function.c `sdl-config --cflags`
gcc -c main.c `sdl-config --cflags --libs` -lSDL -lSDL_image
gcc -o window main.o function.o `sdl-config --cflags --libs` -lSDL -lSDL_image