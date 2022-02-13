

#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#include <stdlib.h>
#include <time.h> 


using namespace System;
using namespace System::Windows::Forms;
int main()
{
	srand((unsigned)time(NULL));

	Application::EnableVisualStyles();
	OOPZerebkovs::MainForm form;

	manager = new Manager(form.frame->Width, form.frame->Height);

	ShapeInitParams params;

	params.x = form.frame->Width / 2;
	params.y = form.frame->Height / 2;
	params.color = Color::FromArgb(50, 145, 168).ToArgb();
	params.size = 30;
	params.frameWidth = form.frame->Width;
	params.frameHeight = form.frame->Height;
	params.dx = rand() % 20 + (-10);
	params.dy = rand() % 20 + (-10);

	Application::Run(% form);
	delete manager;
}