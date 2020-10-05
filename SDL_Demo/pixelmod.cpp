#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

#define COLOR0 0x000f380f 
#define COLOR1 0x00306230 
#define COLOR2 0x008bac0f 
#define COLOR3 0x009bbc0f 

uint32_t miniPix[8];
uint32_t pixel;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
uint32_t rmask = 0xff000000;
uint32_t gmask = 0x00ff0000;
uint32_t bmask = 0x0000ff00;
uint32_t amask = 0x000000ff;

void init();
void loadMedia();
uint32_t * getRowColor(uint16_t row);


SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* stretchSurface = NULL;

void init(){
    // initialize sdl
    SDL_Init(SDL_INIT_VIDEO); 
    //create the window
    window = SDL_CreateWindow("PLEASE WORK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
}

void loadMedia(){
    
}

int main(){
    uint32_t ** colors = (uint32_t**)malloc(8*sizeof(uint32_t*));
    for (int i = 0; i < 8; i++){
        colors[i] = (uint32_t*)malloc(8*sizeof(uint32_t));
    }

    // uint32_t *pixels = (unsigned int *)stretchSurface->pixels;
	// // convert bytearray to rgb values
	uint16_t smileyTile[8] = {0xFF00, 0xFF00, 0xFF24, 0xFF00, 
                              0xFF42, 0xFF7E, 0xFF00, 0xFF00};


    // uint16_t testTile[8] = {0x0000, 0x0000, 0x0000, 0x0000, 
    //                         0x0000, 0x0000, 0xFFFF, 0x0000};

    // printf("%x ", *getRowColor(smileyTile[1]));

   for (int i = 0; i < 8; i++){
       colors[i] = getRowColor(smileyTile[i]);
       for (int j = 0; j < 8; j++) printf("% 6x ", colors[i][j]);
       printf("\n");
   } 
}

uint32_t * getRowColor(uint16_t row){
    for (int i = 0; i < 8; i++){
        miniPix[i] = -1;
    }
        uint16_t byte1 = (row & 0xFF00) >> 8; // grab high order byte out of the 2
        uint16_t byte2 = (row & 0x00FF);      // grab low order byte
        uint16_t mask = 0x01;

        for (int i = 0; i < 8; i++){
            if (byte1 & (mask << i)) miniPix[7-i] += 2; // if byte 1's bit is on
            if (byte2 & (mask << i)) miniPix[7-i] += 3; // if byte 2's bit is on
            switch (miniPix[7-i]){
            case 0:
                miniPix[7-i] = COLOR0;
                break;

            case 1:
                miniPix[7-i] = COLOR1;
                break;

            case 2:
                miniPix[7-i] = COLOR2;
                break;

            case 3:
                miniPix[7-i] = COLOR3;
                break;

            default:
                miniPix[7-i] = 0x00000000;
                break;
            }
        }
        return miniPix;
}
