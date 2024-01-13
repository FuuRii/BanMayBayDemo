
#include "Common_Function.h"
#include "main_Object.h"

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

	g_bg = SDL_CommonFunc::LoadImage("Img/bl1.jpg");
	if (g_bg == NULL) {
		printf("ERROR : Load background that bai !\n");
		exit(-1);
	}
	else {
		printf("Success : Load background thanh cong %d\n", g_bg->format->BitsPerPixel);
	}
	
	/*printf("Success : Apply background thanh cong \n");*/


	MainObject plane_object;
	plane_object.SetRect(190, 668);
	bool ret = plane_object.LoadImg("Img/Picture2.png");
	if (ret == false) {
		return 0;
	}

	while (!is_quit) {
		//neu chua bam nut thoat thi chuong trinh chua duoc phep thoat
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			plane_object.HanleInputAction(g_event);
		}
		SDL_CommonFunc::ApplySurface(g_bg, g_screen, 0, 0);
		plane_object.Show(g_screen);
		plane_object.HandleMove();

		if (SDL_Flip(g_screen) == -1) {
			exit(-1);
		}
		/*int n_ranx = rand() % 1000;
		printf("Success : %d\n", n_ranx);*/
	}
	SDL_CommonFunc::CleanUp();
	SDL_QUIT;
	return 0;
}
#endif
