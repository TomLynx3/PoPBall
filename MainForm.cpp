

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

	ShapeInitParams params;

	params.x = form.frame->Width / 2;
	params.y = form.frame->Height / 2;
	params.color = Color::FromArgb(50, 145, 168).ToArgb();
	params.size = 30;
	params.frameWidth = form.frame->Width;
	params.frameHeight = form.frame->Height;

	ball = new Ball(params);
	Application::Run(% form);
	delete ball;
}