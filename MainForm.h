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
#include "AmmoPack.h"
#include "LifePoints.h"

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
	private: System::Windows::Forms::Timer^ animationTimer;
	private: System::Windows::Forms::Button^ startGame;
	private: System::Windows::Forms::GroupBox^ stats;
	public: System::Windows::Forms::PictureBox^ armor;
	private:

	private: System::Windows::Forms::Label^ armorAmount;
	private: System::Windows::Forms::Label^ hpAmount;
	public: System::Windows::Forms::PictureBox^ hp;
	private: System::Windows::Forms::Label^ ammoAmount;
	public:

	public: System::Windows::Forms::PictureBox^ ammoIcon;
	private: System::Windows::Forms::Timer^ consumambleTimer;
	public:
	private:
	public:

	private:
	private:



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
			this->animationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->startGame = (gcnew System::Windows::Forms::Button());
			this->stats = (gcnew System::Windows::Forms::GroupBox());
			this->ammoAmount = (gcnew System::Windows::Forms::Label());
			this->ammoIcon = (gcnew System::Windows::Forms::PictureBox());
			this->hpAmount = (gcnew System::Windows::Forms::Label());
			this->hp = (gcnew System::Windows::Forms::PictureBox());
			this->armorAmount = (gcnew System::Windows::Forms::Label());
			this->armor = (gcnew System::Windows::Forms::PictureBox());
			this->consumambleTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->stats->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ammoIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->armor))->BeginInit();
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
			// stats
			// 
			this->stats->Controls->Add(this->ammoAmount);
			this->stats->Controls->Add(this->ammoIcon);
			this->stats->Controls->Add(this->hpAmount);
			this->stats->Controls->Add(this->hp);
			this->stats->Controls->Add(this->armorAmount);
			this->stats->Controls->Add(this->armor);
			this->stats->Location = System::Drawing::Point(658, 12);
			this->stats->Name = L"stats";
			this->stats->Size = System::Drawing::Size(187, 262);
			this->stats->TabIndex = 3;
			this->stats->TabStop = false;
			this->stats->Text = L"Stats";
			// 
			// ammoAmount
			// 
			this->ammoAmount->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->ammoAmount->ForeColor = System::Drawing::Color::Lime;
			this->ammoAmount->Location = System::Drawing::Point(71, 168);
			this->ammoAmount->Name = L"ammoAmount";
			this->ammoAmount->Size = System::Drawing::Size(92, 50);
			this->ammoAmount->TabIndex = 5;
			this->ammoAmount->Text = L"0";
			this->ammoAmount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ammoIcon
			// 
			this->ammoIcon->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ammoIcon->Location = System::Drawing::Point(6, 168);
			this->ammoIcon->Name = L"ammoIcon";
			this->ammoIcon->Size = System::Drawing::Size(60, 60);
			this->ammoIcon->TabIndex = 4;
			this->ammoIcon->TabStop = false;
			this->ammoIcon->WaitOnLoad = true;
			this->ammoIcon->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::ammoIcon_Paint);
			// 
			// hpAmount
			// 
			this->hpAmount->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->hpAmount->ForeColor = System::Drawing::Color::Red;
			this->hpAmount->Location = System::Drawing::Point(71, 102);
			this->hpAmount->Name = L"hpAmount";
			this->hpAmount->Size = System::Drawing::Size(92, 50);
			this->hpAmount->TabIndex = 3;
			this->hpAmount->Text = L"0 %";
			this->hpAmount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// hp
			// 
			this->hp->Location = System::Drawing::Point(6, 102);
			this->hp->Name = L"hp";
			this->hp->Size = System::Drawing::Size(60, 60);
			this->hp->TabIndex = 2;
			this->hp->TabStop = false;
			this->hp->WaitOnLoad = true;
			this->hp->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::hpIcon_Paint);
			// 
			// armorAmount
			// 
			this->armorAmount->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->armorAmount->Location = System::Drawing::Point(71, 34);
			this->armorAmount->Name = L"armorAmount";
			this->armorAmount->Size = System::Drawing::Size(92, 50);
			this->armorAmount->TabIndex = 1;
			this->armorAmount->Text = L"0";
			this->armorAmount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// armor
			// 
			this->armor->Location = System::Drawing::Point(6, 34);
			this->armor->Name = L"armor";
			this->armor->Size = System::Drawing::Size(60, 60);
			this->armor->TabIndex = 0;
			this->armor->TabStop = false;
			this->armor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::armor_Paint);
			// 
			// consumambleTimer
			// 
			this->consumambleTimer->Interval = 3500;
			this->consumambleTimer->Tick += gcnew System::EventHandler(this, &MainForm::consumambleTimer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 572);
			this->Controls->Add(this->stats);
			this->Controls->Add(this->startGame);
			this->Controls->Add(this->frame);
			this->ForeColor = System::Drawing::Color::Blue;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Ball V6: Hunter";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->stats->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ammoIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->armor))->EndInit();
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
		GameCreature* hunter;
		//Pictures::loadAssets();
		//this->animationTimer->Enabled = true;
	public: static MainForm^ form;


	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		manager->drawFrame(e->Graphics);
		

		if (isGameStarted) {


			armorAmount->Text = hunter->getArmor().ToString();
			hpAmount->Text = hunter->getHpInPercentages().ToString() + "%";
			ammoAmount->Text = hunter->getAmmoAmount().ToString();

			hpAmount->ForeColor = Color::FromArgb(hunter->getHpLabelColor());
			ammoAmount->ForeColor = Color::FromArgb(hunter->getAmmoLabelColor());
		}
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


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
			
			
	}
private: System::Void destroyAll_Click(System::Object^ sender, System::EventArgs^ e) {
		manager->explodeAllObjects();
	}
private: System::Void animationTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	manager->animate();
}
private: System::Void startGame_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!isGameStarted) {
		hunter = new Hunter(frame->Width, frame->Height, frame->Width / 2, frame->Height / 2, "Pirate");
		manager->add(hunter);
		isGameStarted = true;
		consumambleTimer->Enabled = true;
	}
}
private: System::Void armor_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	e->Graphics->DrawImage(Pictures::armorIcon,Point(0,0));
	
	}
private: System::Void hpIcon_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	e->Graphics->DrawImage(Pictures::hpIcon, Point(0, 0));
}
private: System::Void ammoIcon_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	e->Graphics->DrawImage(Pictures::ammoIcon, Point(0, 0));
}
private: System::Void consumambleTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	int number = rand() % 4;
	if (number == 0) {
		int random = rand() % 2;

		if (random == 0) {
			manager->place(new AmmoPack(frame->Width, frame->Height, 0, 0));
		}
		else {
			manager->place(new LifePoints(frame->Width, frame->Height, 0, 0));
		}
	}
	else if (number == 3) {

		IFigure* consumable = manager->search(&typeid(Consumable));

		if (consumable) {
			manager->remove(consumable);
		}
	}
	}
};

}
