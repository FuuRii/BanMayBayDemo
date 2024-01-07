#include <SDL.h>
#include <Windows.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>

#include <random>
#include <ctime>

const int SCREEN_WIDTH = 144*3;
const int SCREEN_HEIGHT = 256*3;
const int SCREEN_BPP = 32;


SDL_Surface* g_screen = NULL;
SDL_Surface* g_bg = NULL;
SDL_Event g_event;

bool Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		fprintf(stderr, "ERROR : INIT %s", SDL_GetError());
		return false;
	}
	else {
		//dinh dang man hinh
		g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
		if (g_screen == NULL) {
			fprintf(stderr, "ERROR : Not load %s", SDL_GetError());
			return false;
		}
		printf("Success : Khoi tao man hinh thanh cong %d\n", g_screen->format->BitsPerPixel);
	}
	return true;
}

//dinh nghia 1 ham surface de load hinh anh
SDL_Surface* LoadImage(std::string file_path) {
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	//load anh vao bang cach lay ten cua tam anh do
	load_image = IMG_Load(file_path.c_str());
	//neu load image thanh cong thi lam
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		//sau khi load xong thi giai phong image khoi bo nho
		SDL_FreeSurface(load_image);
	}
	return optimize_image;
}

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	//day image tu nguon vao screen
	SDL_BlitSurface(src, NULL, des, NULL);
}

void CleanUp() {
	SDL_FreeSurface(g_screen);
	printf("Success : Giai phong g_screen\n");
	SDL_FreeSurface(g_bg);
	printf("Success : Giai phong g_background\n");
}

#ifdef main
#undef main
int main(int argc, char* argv[]) {
	bool is_quit = false;

	if (Init() == false) {
		printf("ERROR : Khoi tao man hinh that bai !\n");
		exit(-1);
	}
	else {
		printf("Success : Khoi tao man hinh thanh cong %d x %d\n", SCREEN_WIDTH,SCREEN_HEIGHT);
	}

	g_bg = LoadImage("bg.png");
	if (g_bg == NULL) {
		printf("ERROR : Load background that bai !\n");
		exit(-1);
	}
	else {
		printf("Success : Load background thanh cong %d\n", g_bg->format->BitsPerPixel);
	}

	ApplySurface(g_bg, g_screen, 0, 0);

	srand(time(0));
	
	while (!is_quit) {
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			else {
				int n_ran = rand() % 100;
				printf("Success : %d\n",n_ran);
			}
		}

		if (SDL_Flip(g_screen) == -1) {
			exit(-1);
		}
		
	}
	CleanUp();
	SDL_QUIT;
	return 0;
}
#endif
