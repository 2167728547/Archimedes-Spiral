#include <math.h>
#include <stdio.h>

#include "SDL2/SDL.h"

#define WIDTH 800
#define HEIGHT 600

 int main(){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Archimedes Spiral",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    double XS, YS, XT, YT, ZS;
    int ZI, XIi;
    const double PI = 3.141592653589793;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    for (ZI = -64; ZI <= 64; ZI++) {

        ZS = ZI * ZI / 2.25;
        for (XIi = -64; XIi <= 64; XIi++) {

            XS = XIi / 64.0;
            XT = XS * PI;

            YS = sqrt(XIi * XIi + ZS) * 27;
            XT = sqrt(XIi * XIi + ZS) * 0.5;

            YT = (sin(XT) + sin(XT * 3) * 0.4) * YS;

            int X = (int)(WIDTH / 2 + XIi * 4);
            int Y = (int)(HEIGHT / 2 - YT - ZI * 2);

            SDL_RenderDrawPoint(renderer, X, Y);
        }
    }

    SDL_RenderPresent(renderer);

    printf("Done!\n");

    SDL_Event e;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
 }
 void test(SDL_Renderer *renderer)
 {
     SDL_RenderPresent(renderer);
 }