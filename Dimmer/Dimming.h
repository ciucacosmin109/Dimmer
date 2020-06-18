#pragma once
#pragma comment(lib, "user32.lib") 
#include <Windows.h>
#include <windows.h>
#include <iostream>

#include "Settings.h"

namespace Dimmer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dimming
	/// </summary>
	public ref class Dimming : public Form
	{
	public:  
		int width, height;
		Dimming(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			st = gcnew Dimmer::Settings(this);
			timer = gcnew Timer();
			timer->Interval = 30;
			timer->Tick += gcnew System::EventHandler(this, &Dimmer::Dimming::OnTick);
			timer->Start();

			RECT desktop; 
			const HWND hDesktop = GetDesktopWindow(); 
			GetWindowRect(hDesktop, &desktop); 
			width = desktop.right;
			height = desktop.bottom;

			this->Tray->ContextMenuStrip = this->contextMenuStrip1;
			
			this->ShowInTaskbar = false; // Hide from taskbar
			this->TopMost = true; // Always on top                     
			this->Visible = true; // If this property is not set, the form is not shown
			this->MinimizeBox = false; 
			this->MaximizeBox = false;
			this->ControlBox = false;
			this->ShowIcon = false;

			// Make it Transparent
			this->BackColor = Color::Black;
			this->TransparencyKey = Color::White;
			this->Opacity = 0;

			// To hide from Task View (Alt+Tab)
			this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->WindowState = FormWindowState::Maximized; // Make maximized
			
			// Set the form click-through
			int initialStyle = GetWindowLong(static_cast<HWND>(Handle.ToPointer()), -20);
			SetWindowLong(static_cast<HWND>(Handle.ToPointer()), -20, initialStyle | 0x80000 | 0x20);

		}
		void setOpacity(int value) {
			this->Opacity = value;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dimming()
		{
			if (components)
			{
				delete components; 
			}
		}
	private: Dimmer::Settings^ st;
	private: System::Windows::Forms::NotifyIcon^  Tray;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  opacityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem; 
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^ timer;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dimming::typeid));
			this->Tray = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->opacityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Tray
			// 
			this->Tray->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"Tray.Icon")));
			this->Tray->Text = L"Double Click to set opacity";
			this->Tray->Visible = true;
			this->Tray->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dimming::Tray_MouseDoubleClick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->BackColor = System::Drawing::Color::White;
			this->contextMenuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->opacityToolStripMenuItem,
					this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->ShowImageMargin = false;
			this->contextMenuStrip1->Size = System::Drawing::Size(105, 54);
			// 
			// opacityToolStripMenuItem
			// 
			this->opacityToolStripMenuItem->Name = L"opacityToolStripMenuItem";
			this->opacityToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->opacityToolStripMenuItem->Text = L"Brightness";
			this->opacityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dimming::Open_Opacity);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(101, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dimming::Exit_App);
			// 
			// Dimming
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(124, 97);
			this->ControlBox = false;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Dimming";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->TopMost = true;
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	/*protected: property bool ShowWithoutActivation {
		bool get() override { return true; } 
	} 
	protected: property System::Windows::Forms::CreateParams^ CreateParams {
		virtual System::Windows::Forms::CreateParams^ get() override {
			System::Windows::Forms::CreateParams^ createParams = Form::CreateParams;
			createParams->ExStyle |= WS_EX_TOPMOST; // 0x00000008
			return createParams;
		}
	}*/

	private: System::Void Tray_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if(!st->Visible)
			st->run();
		else {
			st->WindowState = FormWindowState::Normal;
			st->Focus();
		}
	}
	private: System::Void Open_Opacity(System::Object^  sender, System::EventArgs^  e) {
		if (!st->Visible)
			st->run();
		else {
			st->WindowState = FormWindowState::Normal;
			st->Focus();
		}
	}
	private: System::Void Exit_App(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	private: void OnTick(System::Object^ sender, System::EventArgs^ e) {
		try {
			//ShowWindow((HWND)this->Handle.ToPointer(), SW_SHOWNOACTIVATE);
			SetWindowPos((HWND)this->Handle.ToPointer(), HWND_TOPMOST,
				-1, -1, width+2, height+2, SWP_NOACTIVATE);
		} catch(...) { }
	};
};
}
 
