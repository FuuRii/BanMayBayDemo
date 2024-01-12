
#include "Common_Function.h"

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



#ifdef main
#undef main
int main(int argc, char* argv[]) {
	bool is_quit = false;

	if (Init() == false) {
		printf("ERROR : Khoi tao man hinh that bai !\n");
		exit(-1);
	}
	else {
		printf("Success : Khoi tao man hinh thanh cong %d x %d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	g_bg = SDL_CommonFunc::LoadImageW("Img/bl1.jpg");
	if (g_bg == NULL) {
		printf("ERROR : Load background that bai !\n");
		exit(-1);
	}
	else {
		printf("Success : Load background thanh cong %d\n", g_bg->format->BitsPerPixel);
	}
	SDL_CommonFunc::ApplySurface(g_bg, g_screen, 0, 0);
	printf("Success : Apply background thanh cong \n");

	//g_plane = LoadImage("Img/Picture2.png");
	//if (g_plane == NULL) {
	//	printf("ERROR : Load object fail !\n");
	//	exit(-1);
	//}
	/*ApplySurface(g_plane, g_screen, 190, 668);
	printf("Success : Apply object thanh cong \n");*/


	while (!is_quit) {
		//neu chua bam nut thoat thi chuong trinh chua duoc phep thoat
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			else {
				int n_ranx = rand() % 1000;
				printf("Success : %d\n", n_ranx);

			}
		}

		if (SDL_Flip(g_screen) == -1) {
			exit(-1);
		}

	}
	SDL_CommonFunc::CleanUp();
	SDL_QUIT;
	return 0;
}
#endif
