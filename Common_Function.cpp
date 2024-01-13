
#include "Common_Function.h"

//dinh nghia 1 ham surface de load hinh anh
SDL_Surface* SDL_CommonFunc::LoadImage(std::string file_path) {
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	//load anh vao bang cach lay ten cua tam anh do
	load_image = IMG_Load(file_path.c_str());
	//neu load image thanh cong thi lam
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		//sau khi load xong thi giai phong image khoi bo nho
		SDL_FreeSurface(load_image);

		if (optimize_image != NULL) {
			Uint32 colorkey = SDL_MapRGB(optimize_image->format, 127, 127, 127);
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, colorkey);
		}
	}
	return optimize_image;
}

void SDL_CommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	//day image tu nguon vao screen
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDL_CommonFunc::CleanUp() {
	SDL_FreeSurface(g_screen);
	printf("Success : Giai phong g_screen\n");
	SDL_FreeSurface(g_bg);
	printf("Success : Giai phong g_background\n");
	//SDL_FreeSurface(g_plane);
	//printf("Success : Giai phong g_plane\n");*/
}