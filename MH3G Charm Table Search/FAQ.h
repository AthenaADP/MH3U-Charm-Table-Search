#pragma once
#include "CharmDatabase.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MH3GCharmTableSearch {

	public ref class FAQ : public System::Windows::Forms::Form
	{
	public:
		FAQ( System::String^ name, System::String^ q, System::String^ a, System::String^ close )
		{
			InitializeComponent();

			btnClose->Text = close;
			lblQuestion->Text = q;
			if( a->StartsWith( L"***" ) )
			{
				a = a->Substring( 3 );
				txtAnswer->Text = a;
				const int np1 = a->IndexOf( L"\n\n" );
				const int nl1 = a->IndexOf( L"\n", np1 + 2 );
				const int nl2 = a->IndexOf( L"\n", nl1 + 1 );
				const int nl3 = a->IndexOf( L"\n", nl2 + 1 );
				const int np2 = a->IndexOf( L"\n\n", nl3 + 1 );
				txtAnswer->SelectionStart = np1;
				txtAnswer->SelectionLength = nl1 - np1;
				txtAnswer->SelectionColor = CharmDatabase::charm_colors[ 0 ];
				txtAnswer->SelectionStart = nl1;
				txtAnswer->SelectionLength = nl2 - nl1;
				txtAnswer->SelectionColor = CharmDatabase::charm_colors[ 1 ];
				txtAnswer->SelectionStart = nl2;
				txtAnswer->SelectionLength = nl3 - nl2;
				txtAnswer->SelectionColor = CharmDatabase::charm_colors[ 2 ];
				txtAnswer->SelectionStart = nl3;
				txtAnswer->SelectionLength = np2 - nl3;
				txtAnswer->SelectionColor = CharmDatabase::charm_colors[ 3 ];
			}
			else txtAnswer->Text = a;

			txtAnswer->LinkClicked += gcnew LinkClickedEventHandler( this, &FAQ::OnLinkClicked );

			Text = name->Replace( L"&", L"" );
		}

	protected:

		~FAQ()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Label^  lblQuestion;
	private: System::Windows::Forms::RichTextBox^  txtAnswer;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->txtAnswer = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->btnClose->Location = System::Drawing::Point(278, 397);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &FAQ::btnClose_Click);
			// 
			// lblQuestion
			// 
			this->lblQuestion->AutoSize = true;
			this->lblQuestion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblQuestion->Location = System::Drawing::Point(12, 9);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(57, 13);
			this->lblQuestion->TabIndex = 1;
			this->lblQuestion->Text = L"Question";
			// 
			// txtAnswer
			// 
			this->txtAnswer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtAnswer->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtAnswer->Location = System::Drawing::Point(15, 25);
			this->txtAnswer->Name = L"txtAnswer";
			this->txtAnswer->ReadOnly = true;
			this->txtAnswer->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->txtAnswer->Size = System::Drawing::Size(617, 366);
			this->txtAnswer->TabIndex = 2;
			this->txtAnswer->Text = L"";
			// 
			// FAQ
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 432);
			this->Controls->Add(this->txtAnswer);
			this->Controls->Add(this->lblQuestion);
			this->Controls->Add(this->btnClose);
			this->Name = L"FAQ";
			this->Text = L"FAQ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Close();
		}

		System::Void OnLinkClicked( System::Object^ sender, LinkClickedEventArgs^ args )
		{
			System::Diagnostics::Process::Start( args->LinkText );
		}
	};
}
