#pragma once

#include "Ball.h"

namespace OOPZerebkovs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			MouseWheel += gcnew MouseEventHandler(this, &MainForm::Form_MouseWheel);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	protected:

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
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(722, 452);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDoubleClick);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 476);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Balls V1: Single Ball";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;

		grp->FillRectangle(% SolidBrush(Color::FromArgb(217,212,212)), 0, 0, frame->Width, frame->Height);

		ball->Draw(grp);
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		ball->setPos(e->X, e->Y);

		frame->Invalidate();
	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		

		if (e->Button == System::Windows::Forms::MouseButtons::Left) { 
			
			ball->setPos(e->X, e->Y);

			frame->Invalidate();
		}
	}
	private: System::Void frame_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		ball->setRandomColor();

		frame->Invalidate();
	}

	private: void Form_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (ModifierKeys == Keys::Control) { 
		
			if (e->Delta < 0) { 
				
				ball->setSize(ball->getSize() - 5);
			}
			else {
				ball->setSize(ball->getSize() + 5);
			}
	
		}

		frame->Invalidate();
	}
	};
}
