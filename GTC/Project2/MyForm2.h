#pragma once
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  choose;


	private: System::Windows::Forms::RichTextBox^  txtbox;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->choose = (gcnew System::Windows::Forms::Button());
			this->txtbox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(327, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Guessing The Character";
			// 
			// choose
			// 
			this->choose->Location = System::Drawing::Point(133, 55);
			this->choose->Name = L"choose";
			this->choose->Size = System::Drawing::Size(104, 32);
			this->choose->TabIndex = 2;
			this->choose->Text = L"Open Camera";
			this->choose->UseVisualStyleBackColor = true;
			this->choose->Click += gcnew System::EventHandler(this, &MyForm::choose_Click);
			// 
			// txtbox
			// 
			this->txtbox->Location = System::Drawing::Point(63, 93);
			this->txtbox->Name = L"txtbox";
			this->txtbox->Size = System::Drawing::Size(245, 229);
			this->txtbox->TabIndex = 3;
			this->txtbox->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(402, 362);
			this->Controls->Add(this->txtbox);
			this->Controls->Add(this->choose);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Guessing The Character";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void choose_Click(System::Object^  sender, System::EventArgs^  e) {
			VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

			if (!stream1.isOpened()) { //check if video device has been initialised
				cout << "cannot open camera";
			}

			//unconditional loop
			while (true) {
				Mat cameraFrame;
				stream1.read(cameraFrame);
				imshow("cam", cameraFrame);
				if (waitKey(30) >= 0)
					break;
			}
	}
	};
	}