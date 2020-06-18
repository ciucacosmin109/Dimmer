#include "Settings.h"
#include "Dimming.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Dimmer::Dimming form;
	Application::Run(%form);
} 