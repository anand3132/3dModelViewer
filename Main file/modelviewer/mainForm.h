#pragma once
#include "OpenGL.h"
POINT PT;

#include "source\Camera.h"
#include "source\mainScene.h"
#include"source\OBJReader.h"
#include <vcclr.h>

#pragma comment( lib, "Winmm.lib")

namespace modelviewer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	
	/// <summary>
	/// Summary for Form1
	/// </summary>
public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//full length view

			//4 view port
			float	OglWidth=this->Size.Width*1.196f;
			float	OglHeight=this->Size.Height*1.038f;
			m_pMainScene = new mainScene();

			//full single Perspective mode

			//4 Window view port
			MV_1_OpenGL=gcnew COpenGL(this, this->Size.Width*0.185f, this->Size.Height*0.04f, OglWidth, OglHeight, m_pMainScene);

			this->timer1->Enabled=true;
			m_fPrevTime=(float)timeGetTime()/1000.0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}

			//if(m_pCamera)
			//{
			//	delete m_pCamera;
			//}

			if(m_pMainScene)
			{
				delete m_pMainScene;
			}
		}
	private: System::ComponentModel::IContainer^  components;	
	private: System::Windows::Forms::Timer^  timer1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//user declaration
	float m_fPrevTime;
	private: OpenGLForm::COpenGL ^MV_1_OpenGL;
	private: OpenGLForm::COpenGL ^MV_2_OpenGL;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  panToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rotateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutUsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;


	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button11;


	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;


private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label29;



















			 //private: System::Windows::Forms::MouseEventArgs ^GLmouseEvent;<<---

	private: mainScene* m_pMainScene;
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolStrip^  toolStrip1;
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutUsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			toolStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			toolStrip1->AutoSize = false;
			toolStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			toolStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			toolStrip1->GripMargin = System::Windows::Forms::Padding(1);
			toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->toolStripButton1, this->toolStripButton2, 
				this->toolStripButton3, this->toolStripSeparator3, this->toolStripButton5, this->toolStripButton7, this->toolStripButton6});
			toolStrip1->Location = System::Drawing::Point(16, 300);
			toolStrip1->Name = L"toolStrip1";
			toolStrip1->Size = System::Drawing::Size(157, 39);
			toolStrip1->TabIndex = 0;
			toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton1->CheckOnClick = true;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton1->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton1->Margin = System::Windows::Forms::Padding(1, 1, 0, 2);
			this->toolStripButton1->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton1->RightToLeftAutoMirrorImage = true;
			this->toolStripButton1->Size = System::Drawing::Size(23, 36);
			this->toolStripButton1->Text = L"X";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton2->CheckOnClick = true;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton2->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton2->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton2->RightToLeftAutoMirrorImage = true;
			this->toolStripButton2->Size = System::Drawing::Size(23, 36);
			this->toolStripButton2->Text = L"Y";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton3->CheckOnClick = true;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton3->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton3->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton3->RightToLeftAutoMirrorImage = true;
			this->toolStripButton3->Size = System::Drawing::Size(23, 36);
			this->toolStripButton3->Text = L"Z";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 39);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton5->CheckOnClick = true;
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton5->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton5->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton5->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton5->RightToLeftAutoMirrorImage = true;
			this->toolStripButton5->Size = System::Drawing::Size(26, 36);
			this->toolStripButton5->Text = L"-X ";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Form1::toolStripButton5_Click);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton7->CheckOnClick = true;
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton7->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton7->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton7->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton7->RightToLeftAutoMirrorImage = true;
			this->toolStripButton7->Size = System::Drawing::Size(26, 36);
			this->toolStripButton7->Text = L"-Y ";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &Form1::toolStripButton7_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripButton6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripButton6->CheckOnClick = true;
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton6->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripButton6->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStripButton6->RightToLeftAutoMirrorImage = true;
			this->toolStripButton6->Size = System::Drawing::Size(25, 36);
			this->toolStripButton6->Text = L"-Z ";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &Form1::toolStripButton6_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 708);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1008, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Stencil", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->helpToolStripMenuItem, 
				this->toolsToolStripMenuItem, this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->aboutUsToolStripMenuItem, 
				this->helpToolStripMenuItem1});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutUsToolStripMenuItem
			// 
			this->aboutUsToolStripMenuItem->Name = L"aboutUsToolStripMenuItem";
			this->aboutUsToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->aboutUsToolStripMenuItem->Text = L"About us";
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(130, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->zoomToolStripMenuItem, 
				this->panToolStripMenuItem, this->rotateToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// zoomToolStripMenuItem
			// 
			this->zoomToolStripMenuItem->Name = L"zoomToolStripMenuItem";
			this->zoomToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->zoomToolStripMenuItem->Text = L"Zoom";
			// 
			// panToolStripMenuItem
			// 
			this->panToolStripMenuItem->Name = L"panToolStripMenuItem";
			this->panToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->panToolStripMenuItem->Text = L"Pan";
			// 
			// rotateToolStripMenuItem
			// 
			this->rotateToolStripMenuItem->Name = L"rotateToolStripMenuItem";
			this->rotateToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->rotateToolStripMenuItem->Text = L"Rotate";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openToolStripMenuItem, 
				this->resetToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->resetToolStripMenuItem->Text = L"Reset";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->toolStripSeparator1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(107, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->groupBox2->Controls->Add(this->label30);
			this->groupBox2->Controls->Add(this->label29);
			this->groupBox2->Controls->Add(this->label28);
			this->groupBox2->Controls->Add(this->label27);
			this->groupBox2->Controls->Add(this->label26);
			this->groupBox2->Controls->Add(this->label25);
			this->groupBox2->Controls->Add(this->label24);
			this->groupBox2->Controls->Add(this->label23);
			this->groupBox2->Controls->Add(this->label22);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox2->Location = System::Drawing::Point(822, 24);
			this->groupBox2->Margin = System::Windows::Forms::Padding(5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(186, 684);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(6, 54);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Model Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Stencil", 11.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(23, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"MODEL DETAILS";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(toolStrip1);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->button10);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->groupBox1->Location = System::Drawing::Point(0, 24);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(190, 684);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(15, 446);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(160, 43);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Mesh OFF";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button11
			// 
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button11->Location = System::Drawing::Point(12, 623);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(160, 43);
			this->button11->TabIndex = 13;
			this->button11->Text = L"Exit";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button10->Location = System::Drawing::Point(12, 574);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(160, 43);
			this->button10->TabIndex = 12;
			this->button10->Text = L"RESET";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(14, 397);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(160, 43);
			this->button9->TabIndex = 11;
			this->button9->Text = L"WireFrame ON";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(15, 346);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(160, 43);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Texture ON";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(14, 250);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(160, 43);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Rotate ";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(14, 201);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 43);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Pan View";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(14, 152);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 43);
			this->button3->TabIndex = 5;
			this->button3->Text = L"ZoomOut";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 103);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 43);
			this->button2->TabIndex = 4;
			this->button2->Text = L"ZoomIN";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 43);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Stencil", 11.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(45, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"CONTROLS";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(6, 4);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Model Address :";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"\"3D OBJ files (*.obj)|*.obj|All files (*.*)|*.*\"";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(89, 4);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->Location = System::Drawing::Point(23, 69);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Model Name:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label7->Location = System::Drawing::Point(6, 103);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"File Type       :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Location = System::Drawing::Point(99, 103);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"3D model format";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label9->Location = System::Drawing::Point(6, 133);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(74, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Texture File   :";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label10->Location = System::Drawing::Point(99, 133);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(70, 13);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Model Name:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Location = System::Drawing::Point(6, 167);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(72, 13);
			this->label11->TabIndex = 13;
			this->label11->Text = L"No of Vertex :";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label12->Location = System::Drawing::Point(99, 167);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(70, 13);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Model Name:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label13->Location = System::Drawing::Point(6, 201);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(79, 13);
			this->label13->TabIndex = 15;
			this->label13->Text = L"No of polygon :";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label14->Location = System::Drawing::Point(99, 201);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(70, 13);
			this->label14->TabIndex = 16;
			this->label14->Text = L"Model Name:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label15->Location = System::Drawing::Point(6, 231);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(80, 13);
			this->label15->TabIndex = 17;
			this->label15->Text = L"Polygon Mesh :";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label16->Location = System::Drawing::Point(99, 231);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(54, 13);
			this->label16->TabIndex = 18;
			this->label16->Text = L"Triangular";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label17->Location = System::Drawing::Point(2, 265);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(181, 13);
			this->label17->TabIndex = 19;
			this->label17->Text = L"----------------------------------------------------------";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label18->Location = System::Drawing::Point(6, 326);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(80, 13);
			this->label18->TabIndex = 20;
			this->label18->Text = L"No of Viewport:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Stencil", 11.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label19->Location = System::Drawing::Point(23, 294);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(146, 18);
			this->label19->TabIndex = 21;
			this->label19->Text = L"VIEWPORT DETAILS";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label20->Location = System::Drawing::Point(99, 326);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(13, 13);
			this->label20->TabIndex = 22;
			this->label20->Text = L"4";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label21->Location = System::Drawing::Point(99, 361);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(46, 13);
			this->label21->TabIndex = 23;
			this->label21->Text = L"Enabled";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label22->Location = System::Drawing::Point(6, 361);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(69, 13);
			this->label22->TabIndex = 24;
			this->label22->Text = L"Perspective :";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label23->Location = System::Drawing::Point(6, 397);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(32, 13);
			this->label23->TabIndex = 25;
			this->label23->Text = L"Top :";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label24->Location = System::Drawing::Point(99, 397);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(48, 13);
			this->label24->TabIndex = 26;
			this->label24->Text = L"Disabled";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label25->Location = System::Drawing::Point(6, 437);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(31, 13);
			this->label25->TabIndex = 27;
			this->label25->Text = L"Left :";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label26->Location = System::Drawing::Point(6, 476);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(38, 13);
			this->label26->TabIndex = 28;
			this->label26->Text = L"Right :";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label27->Location = System::Drawing::Point(99, 437);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(48, 13);
			this->label27->TabIndex = 29;
			this->label27->Text = L"Disabled";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label28->Location = System::Drawing::Point(99, 476);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(48, 13);
			this->label28->TabIndex = 30;
			this->label28->Text = L"Disabled";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label29->Location = System::Drawing::Point(6, 509);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(40, 13);
			this->label29->TabIndex = 31;
			this->label29->Text = L"Bottom";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label30->Location = System::Drawing::Point(99, 509);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(48, 13);
			this->label30->TabIndex = 32;
			this->label30->Text = L"Disabled";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"modelviewer v0.1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Click += gcnew System::EventHandler(this, &Form1::Form1_Click);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			toolStrip1->ResumeLayout(false);
			toolStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e){
			//UNREFERENCED_PARAMETER(sender);	//suppress UNREFERENCED_PARAMETER warning
			//UNREFERENCED_PARAMETER(e);
			//float dtt=timer1->Tick;
			float current_time=(float)timeGetTime()/1000.0;
			float dt=current_time-m_fPrevTime;

	 		MV_1_OpenGL->Update(dt);
 			MV_1_OpenGL->SwapOpenGLBuffers();				 
			//GetCursorPos(&PT);
			m_fPrevTime=current_time;
			 }

	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
			 {
				
				// m_pMainScene->reSize(LOWORD((int)m.LParam), HIWORD((int)m.LParam));
				// MV_1_OpenGL->
					 //=gcnew COpenGL(this, this->Size.Width*0.185f, this->Size.Height*0.04f, OglWidth, OglHeight, m_pMainScene);
				//MV_1_OpenGL->ReSizeGLScene(this->Size.Width*0.8f, this->Size.Height*0.8f);
			 }

	private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) {
				/* timer1->Enabled=TRUE;
				 MV_1_OpenGL->GetOGLPos(PT.x,PT.y);*/
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				//  m_pMainScene->enableTexture();
			 }

	private: System::Void toolStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				if(openFileDialog1->ShowDialog() ==System::Windows::Forms::DialogResult::OK)
				{
					OBJReader objReader;
					//string to char* conversion
					pin_ptr<const wchar_t> wch = PtrToStringChars(openFileDialog1->FileName);
					char File_Name[_MAX_PATH];
					size_t r;
					wcstombs_s(&r, File_Name, wch, _TRUNCATE);
					//
					label4->Text=openFileDialog1->FileName;
					m_pMainScene->loadObjFile(File_Name);
				}

			 }
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::Application::Exit();
			 }
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 }
	//Load  button
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if(openFileDialog1->ShowDialog() ==System::Windows::Forms::DialogResult::OK)
		{

			OBJReader objReader;
			//string to char* conversion
			pin_ptr<const wchar_t> wch = PtrToStringChars(openFileDialog1->FileName);
			char File_Name[_MAX_PATH];
			size_t r;
			wcstombs_s(&r, File_Name, wch, _TRUNCATE);
			//
			label4->Text=openFileDialog1->FileName;

			//objReader.Load(File_Name);
			m_pMainScene->loadObjFile(File_Name);

		}
	}
	//Zoom in  button
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				   m_pMainScene->startZoomin();
			 }
	//zoom out  button
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				
				  m_pMainScene->startZoomOut();
			 }
	//pan  button	
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			{
			}
	//rotate   button
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				m_pMainScene->startRotate();
			 }
	////rotate y button
	//private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	//		 }
	////rotate z button
	//private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

	//				  }
	////Texture on/off
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 if (button8->Text=="Texture ON")
				 {
					 button8->Text="Texture OFF"; 
					 m_pMainScene->enableTexture();
				 } 
				 else
				 {
					 button8->Text="Texture ON";
					  m_pMainScene->disableTexture();
				 }
			 }
	//wire frame on/off
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 if (button9->Text=="WireFrame ON")
				 {
					  m_pMainScene->enableWireframe();
					 button9->Text="WireFrame OFF";
					
				 } 
				 else
				 {
					  m_pMainScene->disableWireframe();
					 button9->Text="WireFrame ON";
					
				 }
			 }

	
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
			button9->Text="WireFrame ON";
			button8->Text="Texture ON";
			button6->Text="Mesh OFF";
			 }
	//Exit
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			 	System::Windows::Forms::Application::Exit();
			  }
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
			 }

	//x axis
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripButton5->Checked=false;
		 }
	//y axis
	private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripButton7->Checked=false;

		 }
	//z axis
	private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
				 toolStripButton6->Checked=false;
			 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (button6->Text=="Mesh ON")
			 {
				button8->Text="Texture OFF"; 
				m_pMainScene->enableMesh();
				 button6->Text="Mesh OFF";

			 } 
			 else
			 {
				 m_pMainScene->disableMesh();
				 button6->Text="Mesh ON";

			 }
		 }
private: System::Void toolStripButton5_Click(System::Object^  sender, System::EventArgs^  e) {
			 toolStripButton1->Checked=false;
		 }
private: System::Void toolStripButton7_Click(System::Object^  sender, System::EventArgs^  e) {
			 toolStripButton2->Checked=false;
		 }
private: System::Void toolStripButton6_Click(System::Object^  sender, System::EventArgs^  e) {
			 toolStripButton3->Checked=false;
		 }
};
}

