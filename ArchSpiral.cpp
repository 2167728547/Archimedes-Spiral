#include <math.h>
#include <stdio.h>

#include <SDL2\SDL.h>

#define WIDTH 400
#define HEIGHT 700

 int main(int argc, char* argv[]){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(  "Archimedes Spiral",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            WIDTH,
                                            HEIGHT,
                                            SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int ZI = 0,
        XIi= 0;

    double  XS = 0,
            XP = 0,
            YS = 0,
            XT = 0,
            YT = 0,
            ZS = 0,
            ZT = 0;

    const double PI = 3.141592653589793;

    for (ZI = -128; ZI <= 128; ZI++) {

        ZS = ZI * ZI / 2.25;

        for (XIi = -128; XIi <= 128; XIi++) {

            XS = XIi / 64.0;
            XP = XS * PI;

            YS = sqrt(XIi * XIi + ZS) * 27;
            XT = sqrt(XIi * XIi + ZS) * 0.5;

            YT = (sin(XT) + sin(XT * 3) * 0.4) * YS;

            int X = (int)(WIDTH / 2 + XIi * 4);
            int Y = (int)(HEIGHT / 2 - YT - ZI * 2);

            SDL_SetRenderDrawColor(renderer, 0, XIi * 2, 0, XIi);
            SDL_RenderDrawPoint(renderer, (X / 4) + 150, (Y / 16) + 300);
        }
    }

    SDL_RenderPresent(renderer);

    SDL_Event e;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
 }
