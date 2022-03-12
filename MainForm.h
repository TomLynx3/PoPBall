#pragma once

#include "IFigure.h"
#include "Ball.h"
#include "Triangle.h"
#include "Square.h"
#include "Star.h"
#include "Explosion.h"
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
	private: System::Windows::Forms::GroupBox^ counterBox;


	private: System::Windows::Forms::CheckBox^ extensionsCheckBox;
	private: System::Windows::Forms::Button^ destroyAll;
	private: System::Windows::Forms::TextBox^ ballsCount;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ starsCount;
	private: System::Windows::Forms::TextBox^ trianglesCount;
	private: System::Windows::Forms::TextBox^ rectanglesCount;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ Rectangles;
	private: System::Windows::Forms::GroupBox^ charactersBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ reactionTimer;

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
			this->counterBox = (gcnew System::Windows::Forms::GroupBox());
			this->starsCount = (gcnew System::Windows::Forms::TextBox());
			this->trianglesCount = (gcnew System::Windows::Forms::TextBox());
			this->rectanglesCount = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Rectangles = (gcnew System::Windows::Forms::Label());
			this->ballsCount = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->destroyAll = (gcnew System::Windows::Forms::Button());
			this->extensionsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->charactersBox = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->reactionTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->counterBox->SuspendLayout();
			this->charactersBox->SuspendLayout();
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
			// counterBox
			// 
			this->counterBox->Controls->Add(this->starsCount);
			this->counterBox->Controls->Add(this->trianglesCount);
			this->counterBox->Controls->Add(this->rectanglesCount);
			this->counterBox->Controls->Add(this->label4);
			this->counterBox->Controls->Add(this->label3);
			this->counterBox->Controls->Add(this->Rectangles);
			this->counterBox->Controls->Add(this->ballsCount);
			this->counterBox->Controls->Add(this->label1);
			this->counterBox->Location = System::Drawing::Point(664, 190);
			this->counterBox->Name = L"counterBox";
			this->counterBox->Size = System::Drawing::Size(174, 159);
			this->counterBox->TabIndex = 2;
			this->counterBox->TabStop = false;
			this->counterBox->Text = L"Counters";
			this->counterBox->Visible = false;
			// 
			// starsCount
			// 
			this->starsCount->Location = System::Drawing::Point(108, 124);
			this->starsCount->Name = L"starsCount";
			this->starsCount->ReadOnly = true;
			this->starsCount->Size = System::Drawing::Size(38, 22);
			this->starsCount->TabIndex = 7;
			this->starsCount->Text = L"0";
			this->starsCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// trianglesCount
			// 
			this->trianglesCount->Location = System::Drawing::Point(108, 90);
			this->trianglesCount->Name = L"trianglesCount";
			this->trianglesCount->ReadOnly = true;
			this->trianglesCount->Size = System::Drawing::Size(38, 22);
			this->trianglesCount->TabIndex = 6;
			this->trianglesCount->Text = L"0";
			this->trianglesCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// rectanglesCount
			// 
			this->rectanglesCount->Location = System::Drawing::Point(108, 56);
			this->rectanglesCount->Name = L"rectanglesCount";
			this->rectanglesCount->ReadOnly = true;
			this->rectanglesCount->Size = System::Drawing::Size(38, 22);
			this->rectanglesCount->TabIndex = 5;
			this->rectanglesCount->Text = L"0";
			this->rectanglesCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Stars";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Triangles";
			// 
			// Rectangles
			// 
			this->Rectangles->AutoSize = true;
			this->Rectangles->Location = System::Drawing::Point(8, 62);
			this->Rectangles->Name = L"Rectangles";
			this->Rectangles->Size = System::Drawing::Size(76, 16);
			this->Rectangles->TabIndex = 2;
			this->Rectangles->Text = L"Rectangles";
			// 
			// ballsCount
			// 
			this->ballsCount->Location = System::Drawing::Point(108, 19);
			this->ballsCount->Name = L"ballsCount";
			this->ballsCount->ReadOnly = true;
			this->ballsCount->Size = System::Drawing::Size(38, 22);
			this->ballsCount->TabIndex = 1;
			this->ballsCount->Text = L"0";
			this->ballsCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Balls";
			// 
			// destroyAll
			// 
			this->destroyAll->Location = System::Drawing::Point(658, 511);
			this->destroyAll->Name = L"destroyAll";
			this->destroyAll->Size = System::Drawing::Size(174, 23);
			this->destroyAll->TabIndex = 0;
			this->destroyAll->Text = L"Destroy All";
			this->destroyAll->UseVisualStyleBackColor = true;
			this->destroyAll->Visible = false;
			this->destroyAll->Click += gcnew System::EventHandler(this, &MainForm::destroyAll_Click);
			// 
			// extensionsCheckBox
			// 
			this->extensionsCheckBox->AutoSize = true;
			this->extensionsCheckBox->Location = System::Drawing::Point(664, 540);
			this->extensionsCheckBox->Name = L"extensionsCheckBox";
			this->extensionsCheckBox->Size = System::Drawing::Size(94, 20);
			this->extensionsCheckBox->TabIndex = 3;
			this->extensionsCheckBox->Text = L"Extensions";
			this->extensionsCheckBox->UseVisualStyleBackColor = true;
			this->extensionsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// charactersBox
			// 
			this->charactersBox->Controls->Add(this->label7);
			this->charactersBox->Controls->Add(this->label6);
			this->charactersBox->Controls->Add(this->label5);
			this->charactersBox->Controls->Add(this->label2);
			this->charactersBox->Location = System::Drawing::Point(664, 356);
			this->charactersBox->Name = L"charactersBox";
			this->charactersBox->Size = System::Drawing::Size(174, 149);
			this->charactersBox->TabIndex = 4;
			this->charactersBox->TabStop = false;
			this->charactersBox->Text = L"Characters";
			this->charactersBox->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 120);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(108, 16);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Star is aggresive";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 16);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Triangle is coward";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 57);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 16);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Rectangle is careful";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Ball is friendly";
			// 
			// reactionTimer
			// 
			this->reactionTimer->Interval = 1000;
			this->reactionTimer->Tick += gcnew System::EventHandler(this, &MainForm::reactionTimer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 572);
			this->Controls->Add(this->charactersBox);
			this->Controls->Add(this->destroyAll);
			this->Controls->Add(this->extensionsCheckBox);
			this->Controls->Add(this->counterBox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Ball V5: Battle";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->counterBox->ResumeLayout(false);
			this->counterBox->PerformLayout();
			this->charactersBox->ResumeLayout(false);
			this->charactersBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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

		int ballCount = manager->countOf(&typeid(Ball));
		int triangleCount = manager->countOf(&typeid(Triangle));
		int rectangleCount = manager->countOf(&typeid(Square));
		int starCount = manager->countOf(&typeid(Star));

		ballsCount->Text = ballCount.ToString();
		trianglesCount->Text = triangleCount.ToString();
		rectanglesCount->Text = rectangleCount.ToString();
		starsCount->Text = starCount.ToString();
		
		
		ballCount > 0 ? ballsCount->BackColor = Color::Purple : ballsCount->BackColor = Color::White;
		triangleCount > 0 ? trianglesCount->BackColor = Color::Yellow : trianglesCount->BackColor = Color::White;
		rectangleCount > 0 ? rectanglesCount->BackColor = Color::Aqua : rectanglesCount->BackColor = Color::White;
		starCount > 0 ? starsCount->BackColor = Color::Brown : starsCount->BackColor = Color::White;

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

private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			
			if (extensionsCheckBox->Checked) {
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
			}
			
	}
private: System::Void destroyAll_Click(System::Object^ sender, System::EventArgs^ e) {
		manager->explodeAllObjects();
	}
private: System::Void reactionTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	manager->makeReactions();
	}
};

}
