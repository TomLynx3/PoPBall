

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

	Application::Run(% form);
	delete manager;
}