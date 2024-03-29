

#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H

const int WIDTH_MAIN_OBJECT = 40;
const int HEIGHT_MAIN_OBJECT = 40;

#include "Base_Object.h"
#include "Common_Function.h"

class MainObject : public BaseObject {
private:
	int x_val_;
	int y_val_;

public:
	MainObject();
	~MainObject();

	void HanleInputAction(SDL_Event events);
	void HandleMove();

};
#endif // !MAIN_OBJECT_H_

