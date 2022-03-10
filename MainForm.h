#pragma once

#include "IFigure.h"
#include "Ball.h"
#include "Triangle.h"
#include "Square.h"
#include "Star.h"
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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ ballBtn;
	private: System::Windows::Forms::RadioButton^ starBtn;
	private: System::Windows::Forms::RadioButton^ triangleBtn;
	private: System::Windows::Forms::RadioButton^ rectangleBtn;
	private: System::Windows::Forms::RadioButton^ randomBtn;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->starBtn = (gcnew System::Windows::Forms::RadioButton());
			this->triangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->rectangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ballBtn = (gcnew System::Windows::Forms::RadioButton());
			this->randomBtn = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(621, 417);
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->randomBtn);
			this->groupBox1->Controls->Add(this->starBtn);
			this->groupBox1->Controls->Add(this->triangleBtn);
			this->groupBox1->Controls->Add(this->rectangleBtn);
			this->groupBox1->Controls->Add(this->ballBtn);
			this->groupBox1->Location = System::Drawing::Point(658, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(127, 294);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Shape";
			// 
			// starBtn
			// 
			this->starBtn->AutoSize = true;
			this->starBtn->Location = System::Drawing::Point(35, 198);
			this->starBtn->Name = L"starBtn";
			this->starBtn->Size = System::Drawing::Size(50, 20);
			this->starBtn->TabIndex = 3;
			this->starBtn->TabStop = true;
			this->starBtn->Text = L"star";
			this->starBtn->UseVisualStyleBackColor = true;
			// 
			// triangleBtn
			// 
			this->triangleBtn->AutoSize = true;
			this->triangleBtn->Location = System::Drawing::Point(35, 147);
			this->triangleBtn->Name = L"triangleBtn";
			this->triangleBtn->Size = System::Drawing::Size(72, 20);
			this->triangleBtn->TabIndex = 2;
			this->triangleBtn->TabStop = true;
			this->triangleBtn->Text = L"triangle";
			this->triangleBtn->UseVisualStyleBackColor = true;
			// 
			// rectangleBtn
			// 
			this->rectangleBtn->AutoSize = true;
			this->rectangleBtn->Location = System::Drawing::Point(35, 94);
			this->rectangleBtn->Name = L"rectangleBtn";
			this->rectangleBtn->Size = System::Drawing::Size(84, 20);
			this->rectangleBtn->TabIndex = 1;
			this->rectangleBtn->TabStop = true;
			this->rectangleBtn->Text = L"rectangle";
			this->rectangleBtn->UseVisualStyleBackColor = true;
			// 
			// ballBtn
			// 
			this->ballBtn->AutoSize = true;
			this->ballBtn->Location = System::Drawing::Point(35, 40);
			this->ballBtn->Name = L"ballBtn";
			this->ballBtn->Size = System::Drawing::Size(50, 20);
			this->ballBtn->TabIndex = 0;
			this->ballBtn->TabStop = true;
			this->ballBtn->Text = L"ball";
			this->ballBtn->UseVisualStyleBackColor = true;
			this->ballBtn->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ballBtn_CheckedChanged);
			// 
			// randomBtn
			// 
			this->randomBtn->AutoSize = true;
			this->randomBtn->Location = System::Drawing::Point(35, 251);
			this->randomBtn->Name = L"randomBtn";
			this->randomBtn->Size = System::Drawing::Size(74, 20);
			this->randomBtn->TabIndex = 4;
			this->randomBtn->TabStop = true;
			this->randomBtn->Text = L"random";
			this->randomBtn->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 477);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Ball V3: Brownian motion";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		int tickCount = 0;
		bool isMousePressed = false;
		int x1 = 0;
		int y1 = 0;
		IFigure* object;

	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		manager->drawFrame(e->Graphics);

	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		Coordinates coord = Coordinates{ (float)e->X, (float)e->Y };

		IFigure* fig = manager->search(coord);

		if (!fig) {

			
			
			if (ballBtn->Checked) {
				object = new Ball(frame->Width, frame->Height);
				object->setPos(e->X, e->Y);
			}
			else if (rectangleBtn->Checked) {
				object = new Square(frame->Width, frame->Height, coord.x, coord.y);
				object->setPos(e->X, e->Y);
			}
			else if (triangleBtn->Checked) {
				object = new Triangle(frame->Width, frame->Height, coord.x, coord.y);
				object->setPos(e->X, e->Y);
			}
			else if (starBtn->Checked) {
				object = new Star(frame->Width, frame->Height, coord.x, coord.y);
				object->setPos(e->X, e->Y);
			}
			else if (randomBtn->Checked) {
				object = manager->createRandomFigure(frame->Width, frame->Height, coord.x, coord.y);
				object->setPos(e->X, e->Y);
			}


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

			//Triangle* tr = new Triangle(frame->Width,frame->Height,100,200);
			//Square* sq = new Square(frame->Width, frame->Height, 20, 50);

			manager->add(object);
			//manager->add(tr);
			//manager->add(sq);

			float deltaX = (e->X - x1) == 0 ? 2 : (e->X - x1);
			float deltaY = (e->Y - y1) == 0 ? 2 : (e->Y - y1);

			object->setSpeed(deltaX / tickCount, deltaY/ tickCount);
			
			object = nullptr;
		}
		
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
private: System::Void ballBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};

}
