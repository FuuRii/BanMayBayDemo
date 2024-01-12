
#ifndef	COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <Windows.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>
#include <random>
#include <ctime>

const int SCREEN_WIDTH = 432; //432
const int SCREEN_HEIGHT = 768; //768
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bg = NULL;
//SDL_Surface* g_plane = NULL;
static SDL_Event g_event;

namespace SDL_CommonFunc {
	SDL_Surface* LoadImageW(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}

#endif