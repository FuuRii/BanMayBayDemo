#include <SDL.h>
#include <Windows.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>

const int WIDTH = 600;
const int HEIGHT = 1200;

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

#ifdef main
#undef main
int main(int argc, char* argv[]) {
	SDL_Surface* setup_screen = NULL;
	SDL_Surface* image = NULL;

	
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "ERROR : INIT %s", SDL_GetError());
		exit(-1);
	}

	setup_screen = SDL_SetVideoMode(WIDTH, HEIGHT, 24, SDL_SWSURFACE);
	if (setup_screen == NULL) {
		fprintf(stderr, "ERROR : Not load %s", SDL_GetError());
		exit(-1);
	}
	printf("Load Success : %d", setup_screen->format->BitsPerPixel);

	image = LoadImage("bk_space600x1200.jpg");
	SDL_BlitSurface(image, NULL, setup_screen, NULL);
	SDL_Flip(setup_screen);
	SDL_Delay(5000);
	SDL_FreeSurface(image);
	SDL_Quit();

	return 0;
}
#endif
