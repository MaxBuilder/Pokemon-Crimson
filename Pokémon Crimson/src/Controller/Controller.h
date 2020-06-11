#pragma once
#include "../View/View.h"

class Controller
{

private:
	View * view;
	// Model model

public:
	void init(View& v);
	void handleEvents(int event);

};

