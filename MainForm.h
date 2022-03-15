#pragma once

#include "IFigure.h"
#include "Ball.h"
#include "Triangle.h"
#include "Square.h"
#include "Star.h"
#include "Explosion.h"
#include "Manager.h";
#include <cmath>
#include "Pictures.h"
#include "Animal.h"
#include "GameCreature.h"
#include "Monster.h"
#include "Hunter.h"
#include "Bullet.h"

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

			form = this;
			Pictures::loadAssets();
			this->animationTimer->Enabled = true;
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


















	private: System::Windows::Forms::Timer^ reactionTimer;
	private: System::Windows::Forms::Timer^ animationTimer;
	private: System::Windows::Forms::Button^ startGame;

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
			this->randomBtn = (gcnew System::Windows::Forms::RadioButton());
			this->starBtn = (gcnew System::Windows::Forms::RadioButton());
			this->triangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->rectangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ballBtn = (gcnew System::Windows::Forms::RadioButton());
			this->reactionTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->animationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->startGame = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(640, 549);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
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
			this->groupBox1->Size = System::Drawing::Size(180, 172);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Shape";
			// 
			// randomBtn
			// 
			this->randomBtn->AutoSize = true;
			this->randomBtn->Location = System::Drawing::Point(6, 138);
			this->randomBtn->Name = L"randomBtn";
			this->randomBtn->Size = System::Drawing::Size(74, 20);
			this->randomBtn->TabIndex = 4;
			this->randomBtn->TabStop = true;
			this->randomBtn->Text = L"random";
			this->randomBtn->UseVisualStyleBackColor = true;
			// 
			// starBtn
			// 
			this->starBtn->AutoSize = true;
			this->starBtn->Location = System::Drawing::Point(6, 112);
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
			this->triangleBtn->Location = System::Drawing::Point(6, 86);
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
			this->rectangleBtn->Location = System::Drawing::Point(6, 60);
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
			this->ballBtn->Location = System::Drawing::Point(6, 34);
			this->ballBtn->Name = L"ballBtn";
			this->ballBtn->Size = System::Drawing::Size(50, 20);
			this->ballBtn->TabIndex = 0;
			this->ballBtn->TabStop = true;
			this->ballBtn->Text = L"ball";
			this->ballBtn->UseVisualStyleBackColor = true;
			// 
			// reactionTimer
			// 
			this->reactionTimer->Interval = 1000;
			this->reactionTimer->Tick += gcnew System::EventHandler(this, &MainForm::reactionTimer_Tick);
			// 
			// animationTimer
			// 
			this->animationTimer->Enabled = true;
			this->animationTimer->Interval = 25;
			this->animationTimer->Tick += gcnew System::EventHandler(this, &MainForm::animationTimer_Tick);
			// 
			// startGame
			// 
			this->startGame->Location = System::Drawing::Point(658, 537);
			this->startGame->Name = L"startGame";
			this->startGame->Size = System::Drawing::Size(187, 23);
			this->startGame->TabIndex = 2;
			this->startGame->Text = L"Start Game";
			this->startGame->UseVisualStyleBackColor = true;
			this->startGame->Click += gcnew System::EventHandler(this, &MainForm::startGame_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 572);
			this->Controls->Add(this->startGame);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Ball V6: Hunter";
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
		bool isGameStarted = false;
		//Pictures::loadAssets();
		//this->animationTimer->Enabled = true;
	public: static MainForm^ form;


	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		manager->drawFrame(e->Graphics);
		

		/*List<Bitmap^>^ assets = Pictures::getHeroAssets("Minotaur");
		e->Graphics->DrawImage(assets[0], 50, 50, 75, 75);*/


	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		//Coordinates coord = Coordinates{ (float)e->X, (float)e->Y };

		////manager->add(new Animal(frame->Width, frame->Height, coord.x, coord.y));

		//IFigure* fig = manager->search(coord);

		//if (!fig) {

		//	
		//	if (ballBtn->Checked) {
		//	//	object = new Ball(frame->Width, frame->Height);
		//	//	object->setPos(e->X, e->Y);
		//	//	object = new Animal(frame->Width, frame->Height, coord.x, coord.y);
		//		object = new Hunter(frame->Width, frame->Height, coord.x, coord.y, "Pirate");
		//	}
		//	else if (rectangleBtn->Checked) {
		//		object = new Square(frame->Width, frame->Height, coord.x, coord.y);
		//		object->setPos(e->X, e->Y);
		//	}
		//	else if (triangleBtn->Checked) {
		//		object = new Triangle(frame->Width, frame->Height, coord.x, coord.y);
		//		object->setPos(e->X, e->Y);
		//	}
		//	else if (starBtn->Checked) {
		//		object = new Star(frame->Width, frame->Height, coord.x, coord.y);
		//		object->setPos(e->X, e->Y);
		//	}
		//	else if (randomBtn->Checked) {
		//		object = manager->createRandomFigure(frame->Width, frame->Height, coord.x, coord.y);
		//		object->setPos(e->X, e->Y);
		//	}


		//	tickCount = 0;
		//	isMousePressed = true;

		//	x1 = e->X;
		//	y1 = e->Y;

		//}
		//else {
		//	manager->remove(fig);
		//}

	

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
		/*isMousePressed = false;

		if (tickCount == 0) {
			tickCount = 1;
		}

		if (object) {


			manager->add(object);

			float deltaX = (e->X - x1) == 0 ? 2 : (e->X - x1);
			float deltaY = (e->Y - y1) == 0 ? 2 : (e->Y - y1);

			object->setSpeed(deltaX / tickCount, deltaY/ tickCount);
			
			object = nullptr;
		}*/
		
	}

private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
	if (e->KeyCode == Keys::ControlKey) {
		moveTimer->Enabled = false;
	}


	//Try to combine actions
	else if (e->KeyCode == Keys::W) {
		manager->doCommand(Command::STARTUP);
	}
	else if (e->KeyCode == Keys::A) {
		manager->doCommand(Command::STARTLEFT);
	}
	else if (e->KeyCode == Keys::D) {
		manager->doCommand(Command::STARTRIGHT);
	}
	else if (e->KeyCode == Keys::S) {
		manager->doCommand(Command::STARTDOWN);
	}
	else if (e->KeyCode == Keys::Space) {
		
		manager->doCommand(Command::SHOOT);

	}
	}
private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (e->KeyCode == Keys::ControlKey) {
		moveTimer->Enabled = true;
	}
	else if (e->KeyCode == Keys::W) {
		manager->doCommand(Command::STOPUP);
	}
	else if (e->KeyCode == Keys::A) {
		manager->doCommand(Command::STOPLEFT);
	}
	else if (e->KeyCode == Keys::D) {
		manager->doCommand(Command::STOPRIGHT);
	}
	else if (e->KeyCode == Keys::S) {
		manager->doCommand(Command::STOPDOWN);
	}
	else if (e->KeyCode == Keys::Space) {
		manager->doCommand(Command::STOPSHOOT);
	}
	}

private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			
			/*if (extensionsCheckBox->Checked) {
				counterBox->Visible = true;
				destroyAll->Visible = true;
				charactersBox->Visible = true;
				reactionTimer->Enabled = true;
				
			}
			else {
				counterBox->Visible = false;
				destroyAll->Visible = false;
				charactersBox->Visible = false;
				reactionTimer->Enabled = false;
			}*/
			
	}
private: System::Void destroyAll_Click(System::Object^ sender, System::EventArgs^ e) {
		manager->explodeAllObjects();
	}
private: System::Void reactionTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	manager->makeReactions();
	}
private: System::Void animationTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	manager->animate();
}
private: System::Void startGame_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!isGameStarted) {
		manager->startGame();
		isGameStarted = true;
	}
}
};

}
