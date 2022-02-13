#pragma once

#include "IShape.h"
#include "Ball.h"
#include "Manager.h";
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
			this->frame->Click += gcnew System::EventHandler(this, &MainForm::frame_Click);
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
			this->Text = L"Pop Ball V3: Brownian motion";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		int tickCount = 0;
		bool isMousePressed = false;
		int x1 = 0;
		int y1 = 0;
		IShape* object;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		manager->drawFrame(e->Graphics);

	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


		IShape* fig = manager->search(Coordinates{ (float)e->X, (float)e->Y });

		if (!fig) {
			ShapeInitParams params = manager->createRandomObjectParams(e->X, e->Y);
			
			params.dx = 0;
			params.dy = 0;
			
			object = new Ball(params);	

			tickCount = 0;
			isMousePressed = true;

			x1 = e->X;
			y1 = e->Y;

		}
		else {
			manager->remove(fig);
		}

	

	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		

	}
	private: System::Void frame_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
	}

	private: void Form_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{

		if (e->Delta < 0) {
			manager->decreaseSpeed();
		}
		else {
			manager->increaseSpeed();
		}

	}
	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

		manager->move();

		if (isMousePressed) {
			tickCount++;
		}
	}
private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

		frame->Invalidate();

	}
private: System::Void frame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isMousePressed = false;

		if (tickCount == 0) {
			tickCount = 1;
		}

		if (object) {

			manager->add(object);

			float deltaX = (e->X - x1) == 0 ? 2 : (e->X - x1);
			float deltaY = (e->Y - y1) == 0 ? 2 : (e->Y - y1);

			object->setSpeed(deltaX / tickCount, deltaY/ tickCount);
			
			object = nullptr;
		}
		
	}
private: System::Void frame_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
	}
private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
	if (e->KeyCode == Keys::ControlKey) {
		moveTimer->Enabled = false;
		}
	}
private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::ControlKey) {
			moveTimer->Enabled = true;
		}
	}
};
}
