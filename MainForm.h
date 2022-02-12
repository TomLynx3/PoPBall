#pragma once

#include "Ball.h"
#include <cmath> 

using namespace std;

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
	private: System::Windows::Forms::Timer^ moveTimer;
	public:
	private: System::Windows::Forms::Timer^ drawTimer;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->frame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseUp);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 10;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 10;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &MainForm::drawTimer_Tick);
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
			this->Text = L"Pop Balls V2: Moving Ball";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		int tickCount = 0;
		bool isMousePressed = false;
		int x1 = 0;
		int y1 = 0;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;

		grp->FillRectangle(% SolidBrush(Color::FromArgb(217,212,212)), 0, 0, frame->Width, frame->Height);

		ball->Draw(grp);
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		

		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			ball->followTo(e->X, e->Y);
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			
			ball->setSpeed(0, 0);

			ball->setPos(e->X, e->Y);

			tickCount = 0;

			isMousePressed = true;

			x1 = e->X;
			y1 = e->Y;
		}
	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		

		if (e->Button == System::Windows::Forms::MouseButtons::Left) { 
			
			ball->setPos(e->X, e->Y);

		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			ball->followTo(e->X, e->Y);
		}
	}
	private: System::Void frame_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		ball->setRandomColor();

	}

	private: void Form_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		/*if (ModifierKeys == Keys::Control || ModifierKeys == Keys::Scroll) { 
		
			// Sometimes scroll event not working
		}*/

		if (e->Delta < 0) {

			float dx = ball->getdX();
			float dy = ball->getdY();

			if (abs(dx) >= 1) {
				dx *= 0.3;
			}

			if (abs(dy) >= 1) {
				dy *= 0.3;
			}

			ball->setSpeed(dx, dy);
		}
		else {

			float dx = ball->getdX();
			float dy = ball->getdY();

			if (abs(dx) < 50) {
				dx *= 1.3;
			}

			if (abs(dy) < 50) {
				dy *= 1.3;
			}

			ball->setSpeed(dx, dy);
		}


	}
	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		ball->move();
		
		if (isMousePressed) {
			tickCount++;
		}
	}
private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		frame->Invalidate();

	}
private: System::Void frame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		isMousePressed = false ;

		if (tickCount == 0) {
			tickCount = 1;
		}

		ball->setSpeed((e->X - x1) / tickCount, (e->Y - y1) / tickCount);
	}
};
}
