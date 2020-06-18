#pragma once

namespace Dimmer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public Form
	{
	public:

		Settings(Form^ dm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Visible = false;
			dimming = dm;
		}
		void run() {
			Opacity->Value = int((1- dimming->Opacity) * 100);
			OpacityNumeric->Value = int((1- dimming->Opacity)*100);

			this->Show();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TrackBar^  Opacity;
	private: System::Windows::Forms::NumericUpDown^  OpacityNumeric;
	private: System::Windows::Forms::Form^ dimming;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
			this->Opacity = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->OpacityNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Opacity))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpacityNumeric))->BeginInit();
			this->SuspendLayout();
			// 
			// Opacity
			// 
			this->Opacity->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Opacity->Location = System::Drawing::Point(6, 19);
			this->Opacity->Maximum = 100;
			this->Opacity->Minimum = 25;
			this->Opacity->Name = L"Opacity";
			this->Opacity->Size = System::Drawing::Size(238, 45);
			this->Opacity->TabIndex = 1;
			this->Opacity->Value = 100;
			this->Opacity->Scroll += gcnew System::EventHandler(this, &Settings::Opacity_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->OpacityNumeric);
			this->groupBox1->Controls->Add(this->Opacity);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(311, 60);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Brightness";
			// 
			// OpacityNumeric
			// 
			this->OpacityNumeric->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OpacityNumeric->Location = System::Drawing::Point(250, 21);
			this->OpacityNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			this->OpacityNumeric->Name = L"OpacityNumeric";
			this->OpacityNumeric->Size = System::Drawing::Size(55, 20);
			this->OpacityNumeric->TabIndex = 2;
			this->OpacityNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->OpacityNumeric->ValueChanged += gcnew System::EventHandler(this, &Settings::OpacityNumeric_ValueChanged);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(311, 60);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1024, 1000);
			this->MinimumSize = System::Drawing::Size(319, 31);
			this->Name = L"Settings";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Settings::Settings_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Opacity))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpacityNumeric))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Settings_Load(System::Object^  sender, System::EventArgs^  e) {

		int sHeight = dimming->Height;
		int sWidth = dimming->Width;
		this->SetDesktopLocation(sWidth - this->Width, sHeight - this->Height - 40);

	}
	private: System::Void Opacity_Scroll(System::Object^  sender, System::EventArgs^  e) {
		int value = Opacity->Value;
		OpacityNumeric->Value = value;
		dimming->Opacity = 1-double(value)/100;
	}
	private: System::Void OpacityNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		int value = int(OpacityNumeric->Value);
		Opacity->Value = value;
		dimming->Opacity = 1-double(value)/100;
	}
	private: System::Void Settings_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->Hide();
		if( e->CloseReason != CloseReason::ApplicationExitCall && 
			e->CloseReason != CloseReason::WindowsShutDown)
			
			e->Cancel = true;
	}
};
}
