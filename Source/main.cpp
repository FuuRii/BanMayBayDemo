#include <SDL.h>
#include <Windows.h>
#include <string>
#include <SDL_image.h>



//hàm nhận tên của ảnh, đọc ảnh và trả về kiểu SDL_Surface
SDL_Surface* LoadImage(std::string file_path)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	//lưu ý: vị trí lưu ảnh phải cùng với vị trí lưu chương trình chính của các bạn để hàm IMG_Load đọc được ảnh
	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL)
	{
		//hàm định dạng hiển thị tối ưu hóa kiểu dữ liệu cho phù hợp
		optimize_image = SDL_DisplayFormat(load_image);
		//dữ liệu đã được đưa vào optimize_image nên load_image không cần nữa, ta giải phóng load_image
		SDL_FreeSurface(load_image);
	}
	return optimize_image;
}

#ifdef main
#undef main
int main(int argc, char* argv[]) {
	SDL_Surface* screen;
	SDL_Surface* image;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)   //khởi tạo màn hình SDL
		return 1;

	screen = SDL_SetVideoMode(1200, 600, 32, SDL_SWSURFACE); //định dạng màn hình
	image = LoadImage("bk_space.png");

	SDL_BlitSurface(image, NULL, screen, NULL); //tải ảnh vào screen

	SDL_Flip(screen);  //hiển thị ảnh lên màn hình
	SDL_Delay(100000);  //dừng 10s trước khi đóng chương trình
	SDL_FreeSurface(image); //giải phóng dữ liệu vì image đã được tải vào screen
	SDL_Quit();  //thoát khỏi SDL
	return 0;
}
#endif
