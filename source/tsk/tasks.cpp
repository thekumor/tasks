#include <tsk/application.h>

#define TSK_WINDOW_WIDTH 1280
#define TSK_WINDOW_HEIGHT 720

int main(int argc, char** argv)
{
	tsk::Application* app = new tsk::Application(TSK_WINDOW_WIDTH, TSK_WINDOW_HEIGHT, "Tasks");
	app->Run();
}