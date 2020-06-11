#include "Controller.h"

void Controller::init(View& v) {
	view = &v;
}

void Controller::handleEvents(int event) {
	if (event == 1)
		view->render(true);
	else view->render(false);
}