#pragma once
#include "CharmDatabase.h"
#include "Version.h"
#include "frmAbout.h"
#include "FAQ.h"

namespace MH3GCharmTableSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int CompareSkillIndices( const unsigned a, const unsigned b )
	{
		return CharmDatabase::ability_names[ a ]->CompareTo( CharmDatabase::ability_names[ b ] );
	}

	#define Compare(A, B) { const int av = A, bv = B; if( av != bv ) return bv - av; }
	static unsigned sort_by_ability;
	static int CompareCharmsByRNG( CharmDatum^ a, CharmDatum^ b )
	{
		Compare( GetCharmType( b->hash ), GetCharmType( a->hash ) );
		return a->num - b->num;
	}
	static int CompareCharmsByAbility( CharmDatum^ ah, CharmDatum^ bh )
	{
		const unsigned a = ah->hash, b = bh->hash;
		const unsigned askill1 = GetCharmAbility1Index( a );
		const unsigned bskill1 = GetCharmAbility1Index( b );

		if( askill1 == sort_by_ability )
		{
			if( bskill1 == sort_by_ability )
			{
				Compare( GetCharmAbility1Points( a ), GetCharmAbility1Points( b ) );
				Compare( GetCharmSlots( a ), GetCharmSlots( b ) );
				Compare( GetCharmAbility2Points( a ), GetCharmAbility2Points( b ) );
				Compare( ( GetCharmAbility2Index( a ) + 1 ) % 123, ( GetCharmAbility2Index( b ) + 1 ) % 123 );
			}
			else
			{
				Compare( GetCharmAbility1Points( a ), GetCharmAbility2Points( b ) );
				Compare( GetCharmSlots( a ), GetCharmSlots( b ) );
				Compare( GetCharmAbility2Points( a ), GetCharmAbility1Points( b ) );
				Compare( ( GetCharmAbility2Index( a ) + 1 ) % 123, ( GetCharmAbility1Index( b ) + 1 ) % 123 );
			}
		}
		else
		{
			if( bskill1 == sort_by_ability )
			{
				Compare( GetCharmAbility2Points( a ), GetCharmAbility1Points( b ) );
				Compare( GetCharmSlots( a ), GetCharmSlots( b ) );
				Compare( GetCharmAbility1Points( a ), GetCharmAbility2Points( b ) );
				Compare( ( GetCharmAbility1Index( a ) + 1 ) % 123, ( GetCharmAbility2Index( b ) + 1 ) % 123 );
			}
			else
			{
				Compare( GetCharmAbility2Points( a ), GetCharmAbility2Points( b ) );
				Compare( GetCharmSlots( a ), GetCharmSlots( b ) );
				Compare( GetCharmAbility1Points( a ), GetCharmAbility1Points( b ) );
				Compare( ( GetCharmAbility1Index( a ) + 1 ) % 123, ( GetCharmAbility1Index( b ) + 1 ) % 123 );
			}
		}
		return 0;
	}
#undef Compare

	public ref class Form1 : public System::Windows::Forms::Form
	{
#pragma region Members
	private: System::Windows::Forms::ListView^  lstTable2;
	private: System::Windows::Forms::GroupBox^  grpTable2;
	private: System::Windows::Forms::GroupBox^  grpTable3;
	private: System::Windows::Forms::GroupBox^  grpTable4;
	private: System::Windows::Forms::GroupBox^  grpTable5;
	private: System::Windows::Forms::GroupBox^  grpTable6;
	private: System::Windows::Forms::GroupBox^  grpTable9;
	private: System::Windows::Forms::GroupBox^  grpTable8;
	private: System::Windows::Forms::GroupBox^  grpTable7;
	private: System::Windows::Forms::GroupBox^  grpTable10;
	private: System::Windows::Forms::GroupBox^  grpTable15;
	private: System::Windows::Forms::GroupBox^  grpTable12;
	private: System::Windows::Forms::GroupBox^  grpTable13;
	private: System::Windows::Forms::GroupBox^  grpTable11;
	private: System::Windows::Forms::GroupBox^  grpTable14;
	private: System::Windows::Forms::GroupBox^  grpTable16;
	private: System::Windows::Forms::GroupBox^  grpTable17;
	private: System::Windows::Forms::ListView^  lstTable3;
	private: System::Windows::Forms::ListView^  lstTable4;
	private: System::Windows::Forms::ListView^  lstTable5;
	private: System::Windows::Forms::ListView^  lstTable6;
	private: System::Windows::Forms::ListView^  lstTable9;
	private: System::Windows::Forms::ListView^  lstTable8;
	private: System::Windows::Forms::ListView^  lstTable7;
	private: System::Windows::Forms::ListView^  lstTable10;
	private: System::Windows::Forms::ListView^  lstTable15;
	private: System::Windows::Forms::ListView^  lstTable12;
	private: System::Windows::Forms::ListView^  lstTable13;
	private: System::Windows::Forms::ListView^  lstTable11;
	private: System::Windows::Forms::ListView^  lstTable14;
	private: System::Windows::Forms::ListView^  lstTable16;
	private: System::Windows::Forms::ListView^  lstTable17;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFile;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuQuit;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOptions;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuShowAllCharms;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFAQ;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuAbout;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuShowCursedTables;
	private: System::Windows::Forms::NumericUpDown^  nudSlots;
	private: System::Windows::Forms::GroupBox^  grpCriteria;
	private: System::Windows::Forms::Label^  lblSlots;
	private: System::Windows::Forms::NumericUpDown^  nudSkill2;
	private: System::Windows::Forms::ComboBox^  cmbSkill2;
	private: System::Windows::Forms::NumericUpDown^  nudSkill1;
	private: System::Windows::Forms::ComboBox^  cmbSkill1;
	private: System::Windows::Forms::Label^  lblSkill2;
	private: System::Windows::Forms::Label^  lblSkill1;
	private: System::Windows::Forms::ListView^  lstTable1;
	private: System::Windows::Forms::GroupBox^  grpTable1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuWhatAre;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHowKnow;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHowChange;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuWhatCursed;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuDoesItMatter;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuWhatShowAll;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuWhatToDo;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuGetCharmTable;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHowHard;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuWhereCharms;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCharmTime;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHowFarmCharms;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuAboutCharms;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuBestCharms;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuBestTable;
	private: System::Windows::Forms::Button^  btnWTF;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuUpdate;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCurrent;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuEnglish;
	private: System::Windows::Forms::ContextMenuStrip^  cxtCharmData;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCharmColors;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSortBySkill;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSortByRNG;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuExport;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuExportAll;
			 private: System::Windows::Forms::ToolStripMenuItem^  mnuSortAlpha;
#pragma endregion
			 array< GroupBox^ >^ groups;
			 array< ListView^ >^ lists;
			 array< unsigned >^ skill_index_to_alpha, ^skill_alpha_to_index;
			 static array< unsigned >^ cursed = { 11, 12, 15, 16, 17 };
			 static System::String^ SETTINGS_FILE = L"settings.txt";
			 String^ result_string;
			 String^ results_string;
			 String^ rngno_string;
			 String^ seed_string;
			 String^ none_string;
			 String^ close_string;
			 String^ table_string;
			 String^ translation_credits;
			 String^ save_filetype_string, ^save_filenameall_string, ^save_format_string, ^save_formatall_string;
			 bool sort_by_skill;
			 unsigned items_before_languages, lock_results;
			 Generic::List< String^ > language_names;
	public:
		Form1(void)
		{
			InitializeComponent();
			items_before_languages = mnuOptions->DropDownItems->Count;
			lock_results = 0;
			sort_by_skill = true;

			InitExportMenuItems();
			GenerateCharmTable();
			SetupGroupsAndLists();
			array< String^ >^ files = IO::Directory::GetFiles( L"." );
			skill_alpha_to_index = gcnew array< unsigned >( CharmDatabase::ability_names->Length );
			skill_index_to_alpha = gcnew array< unsigned >( CharmDatabase::ability_names->Length );
			for( int i = 0; i < CharmDatabase::ability_names->Length; ++i )
			{
				skill_alpha_to_index[ i ] = i;
				skill_index_to_alpha[ i ] = i;
			}

			Text += L" v" + STRINGIZE( VERSION_NO );

			LoadLanguages();
			LoadSettings();

			cmbSkill1->SelectedIndex = 0;
			cmbSkill2->SelectedIndex = 0;

			this->Resize += gcnew EventHandler( this, &Form1::WindowResized );
		}

		void LoadLanguages()
		{
			array< String^ >^ files = IO::Directory::GetFiles( L"Languages", L"*.txt" );
			for( int i = 0; i < files->Length; ++i )
			{
				String^ name = files[ i ];
				const int slash = name->IndexOf( L'\\' );
				if( slash != -1 )
					name = name->Substring( slash + 1 );
				name = name->Substring( 0, name->Length - 4 );
				language_names.Add( name );

				ToolStripMenuItem^ item = gcnew ToolStripMenuItem( L"&" + name );
				item->Name = name;
				item->Click += gcnew EventHandler( this, &Form1::LanguageChanged );
				mnuOptions->DropDownItems->Add( item );
			}
		}

		bool LoadSettingLanguage( String^ lang )
		{
			for( int i = 0; i < language_names.Count; ++i )
			{
				if( language_names[ i ]->IndexOf( lang ) != -1 )
				{
					mnuCurrent = safe_cast< ToolStripMenuItem^ >( mnuOptions->DropDownItems[ items_before_languages + i ] );
					LanguageChanged( lang );
					return true;
				}
			}
			return false;
		}

		void LoadSettings()
		{
			try
			{
				array< String^ >^ lines = IO::File::ReadAllLines( SETTINGS_FILE );
				if( lines->Length > 1 && lines[ 0 ] == L"1" )
				{
					if( LoadSettingLanguage( lines[ 1 ] ) )
						return;
				}
			}
			catch( Exception^ )
			{
				//carry on
			}
			//no settings file, or file is corrupt
			String^ native = Globalization::CultureInfo::CurrentCulture->NativeName;
			const int spaceloc = native->IndexOf( L" " );
			if( spaceloc > 0 )
				native = native->Substring( 0, spaceloc );

			if( !LoadSettingLanguage( native ) &&
				!LoadSettingLanguage( L"English" ) )
			{
				mnuCurrent = safe_cast< ToolStripMenuItem^ >( mnuOptions->DropDownItems[ items_before_languages ] );
				LanguageChanged( mnuCurrent->Text );
			}
			SaveSettings();
		}

		void SaveSettings()
		{
			array< String^ >^ lines =
			{
				L"1",
				mnuCurrent->Text->Substring( 1 )
			};
			IO::File::WriteAllLines( SETTINGS_FILE, lines );
		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^  components;
protected: 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->nudSlots = (gcnew System::Windows::Forms::NumericUpDown());
			this->grpCriteria = (gcnew System::Windows::Forms::GroupBox());
			this->nudSkill2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->cmbSkill2 = (gcnew System::Windows::Forms::ComboBox());
			this->nudSkill1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->cmbSkill1 = (gcnew System::Windows::Forms::ComboBox());
			this->lblSkill2 = (gcnew System::Windows::Forms::Label());
			this->lblSkill1 = (gcnew System::Windows::Forms::Label());
			this->lblSlots = (gcnew System::Windows::Forms::Label());
			this->lstTable1 = (gcnew System::Windows::Forms::ListView());
			this->grpTable1 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable2 = (gcnew System::Windows::Forms::ListView());
			this->grpTable2 = (gcnew System::Windows::Forms::GroupBox());
			this->grpTable3 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable3 = (gcnew System::Windows::Forms::ListView());
			this->grpTable4 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable4 = (gcnew System::Windows::Forms::ListView());
			this->grpTable5 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable5 = (gcnew System::Windows::Forms::ListView());
			this->grpTable6 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable6 = (gcnew System::Windows::Forms::ListView());
			this->grpTable9 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable9 = (gcnew System::Windows::Forms::ListView());
			this->grpTable8 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable8 = (gcnew System::Windows::Forms::ListView());
			this->grpTable7 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable7 = (gcnew System::Windows::Forms::ListView());
			this->grpTable10 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable10 = (gcnew System::Windows::Forms::ListView());
			this->grpTable15 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable15 = (gcnew System::Windows::Forms::ListView());
			this->grpTable12 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable12 = (gcnew System::Windows::Forms::ListView());
			this->grpTable13 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable13 = (gcnew System::Windows::Forms::ListView());
			this->grpTable11 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable11 = (gcnew System::Windows::Forms::ListView());
			this->grpTable14 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable14 = (gcnew System::Windows::Forms::ListView());
			this->grpTable16 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable16 = (gcnew System::Windows::Forms::ListView());
			this->grpTable17 = (gcnew System::Windows::Forms::GroupBox());
			this->lstTable17 = (gcnew System::Windows::Forms::ListView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuExport = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuExportAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuQuit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOptions = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuShowAllCharms = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuShowCursedTables = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuSortBySkill = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSortByRNG = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSortAlpha = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFAQ = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuWhatAre = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHowKnow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuDoesItMatter = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuWhatCursed = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuBestTable = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHowChange = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuGetCharmTable = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuWhatShowAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCharmColors = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuAboutCharms = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuWhereCharms = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuBestCharms = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCharmTime = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHowFarmCharms = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHowHard = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuWhatToDo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuUpdate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnWTF = (gcnew System::Windows::Forms::Button());
			this->cxtCharmData = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSlots))->BeginInit();
			this->grpCriteria->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSkill2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSkill1))->BeginInit();
			this->grpTable1->SuspendLayout();
			this->grpTable2->SuspendLayout();
			this->grpTable3->SuspendLayout();
			this->grpTable4->SuspendLayout();
			this->grpTable5->SuspendLayout();
			this->grpTable6->SuspendLayout();
			this->grpTable9->SuspendLayout();
			this->grpTable8->SuspendLayout();
			this->grpTable7->SuspendLayout();
			this->grpTable10->SuspendLayout();
			this->grpTable15->SuspendLayout();
			this->grpTable12->SuspendLayout();
			this->grpTable13->SuspendLayout();
			this->grpTable11->SuspendLayout();
			this->grpTable14->SuspendLayout();
			this->grpTable16->SuspendLayout();
			this->grpTable17->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// nudSlots
			// 
			this->nudSlots->Location = System::Drawing::Point(45, 19);
			this->nudSlots->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->nudSlots->Name = L"nudSlots";
			this->nudSlots->Size = System::Drawing::Size(29, 20);
			this->nudSlots->TabIndex = 0;
			this->nudSlots->ValueChanged += gcnew System::EventHandler(this, &Form1::SettingsChanged);
			// 
			// grpCriteria
			// 
			this->grpCriteria->Controls->Add(this->nudSkill2);
			this->grpCriteria->Controls->Add(this->cmbSkill2);
			this->grpCriteria->Controls->Add(this->nudSkill1);
			this->grpCriteria->Controls->Add(this->cmbSkill1);
			this->grpCriteria->Controls->Add(this->lblSkill2);
			this->grpCriteria->Controls->Add(this->lblSkill1);
			this->grpCriteria->Controls->Add(this->lblSlots);
			this->grpCriteria->Controls->Add(this->nudSlots);
			this->grpCriteria->Location = System::Drawing::Point(12, 27);
			this->grpCriteria->Name = L"grpCriteria";
			this->grpCriteria->Size = System::Drawing::Size(498, 51);
			this->grpCriteria->TabIndex = 1;
			this->grpCriteria->TabStop = false;
			this->grpCriteria->Text = L"Search Criteria";
			// 
			// nudSkill2
			// 
			this->nudSkill2->Location = System::Drawing::Point(328, 19);
			this->nudSkill2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {13, 0, 0, 0});
			this->nudSkill2->Name = L"nudSkill2";
			this->nudSkill2->Size = System::Drawing::Size(33, 20);
			this->nudSkill2->TabIndex = 7;
			this->nudSkill2->ValueChanged += gcnew System::EventHandler(this, &Form1::SettingsChanged);
			// 
			// cmbSkill2
			// 
			this->cmbSkill2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSkill2->FormattingEnabled = true;
			this->cmbSkill2->Location = System::Drawing::Point(367, 19);
			this->cmbSkill2->Name = L"cmbSkill2";
			this->cmbSkill2->Size = System::Drawing::Size(121, 21);
			this->cmbSkill2->TabIndex = 6;
			this->cmbSkill2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::SettingsChanged);
			// 
			// nudSkill1
			// 
			this->nudSkill1->Location = System::Drawing::Point(121, 19);
			this->nudSkill1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {13, 0, 0, 0});
			this->nudSkill1->Name = L"nudSkill1";
			this->nudSkill1->Size = System::Drawing::Size(33, 20);
			this->nudSkill1->TabIndex = 5;
			this->nudSkill1->ValueChanged += gcnew System::EventHandler(this, &Form1::SettingsChanged);
			// 
			// cmbSkill1
			// 
			this->cmbSkill1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSkill1->FormattingEnabled = true;
			this->cmbSkill1->Location = System::Drawing::Point(160, 19);
			this->cmbSkill1->Name = L"cmbSkill1";
			this->cmbSkill1->Size = System::Drawing::Size(121, 21);
			this->cmbSkill1->TabIndex = 4;
			this->cmbSkill1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::SettingsChanged);
			// 
			// lblSkill2
			// 
			this->lblSkill2->AutoSize = true;
			this->lblSkill2->Location = System::Drawing::Point(287, 22);
			this->lblSkill2->Name = L"lblSkill2";
			this->lblSkill2->Size = System::Drawing::Size(35, 13);
			this->lblSkill2->TabIndex = 3;
			this->lblSkill2->Text = L"Skill 2";
			// 
			// lblSkill1
			// 
			this->lblSkill1->AutoSize = true;
			this->lblSkill1->Location = System::Drawing::Point(80, 22);
			this->lblSkill1->Name = L"lblSkill1";
			this->lblSkill1->Size = System::Drawing::Size(35, 13);
			this->lblSkill1->TabIndex = 2;
			this->lblSkill1->Text = L"Skill 1";
			// 
			// lblSlots
			// 
			this->lblSlots->AutoSize = true;
			this->lblSlots->Location = System::Drawing::Point(9, 22);
			this->lblSlots->Name = L"lblSlots";
			this->lblSlots->Size = System::Drawing::Size(30, 13);
			this->lblSlots->TabIndex = 1;
			this->lblSlots->Text = L"Slots";
			// 
			// lstTable1
			// 
			this->lstTable1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable1->FullRowSelect = true;
			this->lstTable1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable1->LabelWrap = false;
			this->lstTable1->Location = System::Drawing::Point(6, 19);
			this->lstTable1->MultiSelect = false;
			this->lstTable1->Name = L"lstTable1";
			this->lstTable1->Size = System::Drawing::Size(212, 82);
			this->lstTable1->TabIndex = 2;
			this->lstTable1->UseCompatibleStateImageBehavior = false;
			this->lstTable1->View = System::Windows::Forms::View::Details;
			// 
			// grpTable1
			// 
			this->grpTable1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable1->Controls->Add(this->lstTable1);
			this->grpTable1->Location = System::Drawing::Point(12, 84);
			this->grpTable1->Name = L"grpTable1";
			this->grpTable1->Size = System::Drawing::Size(224, 111);
			this->grpTable1->TabIndex = 3;
			this->grpTable1->TabStop = false;
			this->grpTable1->Text = L"Table 1";
			// 
			// lstTable2
			// 
			this->lstTable2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable2->FullRowSelect = true;
			this->lstTable2->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable2->LabelWrap = false;
			this->lstTable2->Location = System::Drawing::Point(6, 19);
			this->lstTable2->MultiSelect = false;
			this->lstTable2->Name = L"lstTable2";
			this->lstTable2->Size = System::Drawing::Size(212, 82);
			this->lstTable2->TabIndex = 2;
			this->lstTable2->UseCompatibleStateImageBehavior = false;
			this->lstTable2->View = System::Windows::Forms::View::Details;
			// 
			// grpTable2
			// 
			this->grpTable2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable2->Controls->Add(this->lstTable2);
			this->grpTable2->Location = System::Drawing::Point(242, 84);
			this->grpTable2->Name = L"grpTable2";
			this->grpTable2->Size = System::Drawing::Size(224, 111);
			this->grpTable2->TabIndex = 4;
			this->grpTable2->TabStop = false;
			this->grpTable2->Text = L"Table 2";
			// 
			// grpTable3
			// 
			this->grpTable3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable3->Controls->Add(this->lstTable3);
			this->grpTable3->Location = System::Drawing::Point(472, 84);
			this->grpTable3->Name = L"grpTable3";
			this->grpTable3->Size = System::Drawing::Size(224, 111);
			this->grpTable3->TabIndex = 5;
			this->grpTable3->TabStop = false;
			this->grpTable3->Text = L"Table 3";
			// 
			// lstTable3
			// 
			this->lstTable3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable3->FullRowSelect = true;
			this->lstTable3->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable3->LabelWrap = false;
			this->lstTable3->Location = System::Drawing::Point(6, 19);
			this->lstTable3->MultiSelect = false;
			this->lstTable3->Name = L"lstTable3";
			this->lstTable3->Size = System::Drawing::Size(212, 82);
			this->lstTable3->TabIndex = 3;
			this->lstTable3->UseCompatibleStateImageBehavior = false;
			this->lstTable3->View = System::Windows::Forms::View::Details;
			// 
			// grpTable4
			// 
			this->grpTable4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable4->Controls->Add(this->lstTable4);
			this->grpTable4->Location = System::Drawing::Point(702, 84);
			this->grpTable4->Name = L"grpTable4";
			this->grpTable4->Size = System::Drawing::Size(224, 111);
			this->grpTable4->TabIndex = 6;
			this->grpTable4->TabStop = false;
			this->grpTable4->Text = L"Table 4";
			// 
			// lstTable4
			// 
			this->lstTable4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable4->FullRowSelect = true;
			this->lstTable4->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable4->LabelWrap = false;
			this->lstTable4->Location = System::Drawing::Point(6, 19);
			this->lstTable4->MultiSelect = false;
			this->lstTable4->Name = L"lstTable4";
			this->lstTable4->Size = System::Drawing::Size(212, 82);
			this->lstTable4->TabIndex = 4;
			this->lstTable4->UseCompatibleStateImageBehavior = false;
			this->lstTable4->View = System::Windows::Forms::View::Details;
			// 
			// grpTable5
			// 
			this->grpTable5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable5->Controls->Add(this->lstTable5);
			this->grpTable5->Location = System::Drawing::Point(12, 201);
			this->grpTable5->Name = L"grpTable5";
			this->grpTable5->Size = System::Drawing::Size(224, 111);
			this->grpTable5->TabIndex = 6;
			this->grpTable5->TabStop = false;
			this->grpTable5->Text = L"Table 5";
			// 
			// lstTable5
			// 
			this->lstTable5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable5->FullRowSelect = true;
			this->lstTable5->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable5->LabelWrap = false;
			this->lstTable5->Location = System::Drawing::Point(6, 19);
			this->lstTable5->MultiSelect = false;
			this->lstTable5->Name = L"lstTable5";
			this->lstTable5->Size = System::Drawing::Size(212, 82);
			this->lstTable5->TabIndex = 5;
			this->lstTable5->UseCompatibleStateImageBehavior = false;
			this->lstTable5->View = System::Windows::Forms::View::Details;
			// 
			// grpTable6
			// 
			this->grpTable6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable6->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable6->Controls->Add(this->lstTable6);
			this->grpTable6->Location = System::Drawing::Point(242, 201);
			this->grpTable6->Name = L"grpTable6";
			this->grpTable6->Size = System::Drawing::Size(224, 111);
			this->grpTable6->TabIndex = 6;
			this->grpTable6->TabStop = false;
			this->grpTable6->Text = L"Table 6";
			// 
			// lstTable6
			// 
			this->lstTable6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable6->FullRowSelect = true;
			this->lstTable6->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable6->LabelWrap = false;
			this->lstTable6->Location = System::Drawing::Point(6, 19);
			this->lstTable6->MultiSelect = false;
			this->lstTable6->Name = L"lstTable6";
			this->lstTable6->Size = System::Drawing::Size(212, 82);
			this->lstTable6->TabIndex = 6;
			this->lstTable6->UseCompatibleStateImageBehavior = false;
			this->lstTable6->View = System::Windows::Forms::View::Details;
			// 
			// grpTable9
			// 
			this->grpTable9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable9->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable9->Controls->Add(this->lstTable9);
			this->grpTable9->Location = System::Drawing::Point(12, 318);
			this->grpTable9->Name = L"grpTable9";
			this->grpTable9->Size = System::Drawing::Size(224, 111);
			this->grpTable9->TabIndex = 8;
			this->grpTable9->TabStop = false;
			this->grpTable9->Text = L"Table 9";
			// 
			// lstTable9
			// 
			this->lstTable9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable9->FullRowSelect = true;
			this->lstTable9->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable9->LabelWrap = false;
			this->lstTable9->Location = System::Drawing::Point(6, 14);
			this->lstTable9->MultiSelect = false;
			this->lstTable9->Name = L"lstTable9";
			this->lstTable9->Size = System::Drawing::Size(212, 82);
			this->lstTable9->TabIndex = 9;
			this->lstTable9->UseCompatibleStateImageBehavior = false;
			this->lstTable9->View = System::Windows::Forms::View::Details;
			// 
			// grpTable8
			// 
			this->grpTable8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable8->Controls->Add(this->lstTable8);
			this->grpTable8->Location = System::Drawing::Point(702, 201);
			this->grpTable8->Name = L"grpTable8";
			this->grpTable8->Size = System::Drawing::Size(224, 111);
			this->grpTable8->TabIndex = 9;
			this->grpTable8->TabStop = false;
			this->grpTable8->Text = L"Table 8";
			// 
			// lstTable8
			// 
			this->lstTable8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable8->FullRowSelect = true;
			this->lstTable8->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable8->LabelWrap = false;
			this->lstTable8->Location = System::Drawing::Point(6, 19);
			this->lstTable8->MultiSelect = false;
			this->lstTable8->Name = L"lstTable8";
			this->lstTable8->Size = System::Drawing::Size(212, 82);
			this->lstTable8->TabIndex = 8;
			this->lstTable8->UseCompatibleStateImageBehavior = false;
			this->lstTable8->View = System::Windows::Forms::View::Details;
			// 
			// grpTable7
			// 
			this->grpTable7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable7->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable7->Controls->Add(this->lstTable7);
			this->grpTable7->Location = System::Drawing::Point(472, 201);
			this->grpTable7->Name = L"grpTable7";
			this->grpTable7->Size = System::Drawing::Size(224, 111);
			this->grpTable7->TabIndex = 7;
			this->grpTable7->TabStop = false;
			this->grpTable7->Text = L"Table 7";
			// 
			// lstTable7
			// 
			this->lstTable7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable7->FullRowSelect = true;
			this->lstTable7->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable7->LabelWrap = false;
			this->lstTable7->Location = System::Drawing::Point(6, 19);
			this->lstTable7->MultiSelect = false;
			this->lstTable7->Name = L"lstTable7";
			this->lstTable7->Size = System::Drawing::Size(212, 82);
			this->lstTable7->TabIndex = 7;
			this->lstTable7->UseCompatibleStateImageBehavior = false;
			this->lstTable7->View = System::Windows::Forms::View::Details;
			// 
			// grpTable10
			// 
			this->grpTable10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable10->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable10->Controls->Add(this->lstTable10);
			this->grpTable10->Location = System::Drawing::Point(242, 318);
			this->grpTable10->Name = L"grpTable10";
			this->grpTable10->Size = System::Drawing::Size(224, 111);
			this->grpTable10->TabIndex = 9;
			this->grpTable10->TabStop = false;
			this->grpTable10->Text = L"Table 10";
			// 
			// lstTable10
			// 
			this->lstTable10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable10->FullRowSelect = true;
			this->lstTable10->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable10->LabelWrap = false;
			this->lstTable10->Location = System::Drawing::Point(6, 14);
			this->lstTable10->MultiSelect = false;
			this->lstTable10->Name = L"lstTable10";
			this->lstTable10->Size = System::Drawing::Size(212, 82);
			this->lstTable10->TabIndex = 9;
			this->lstTable10->UseCompatibleStateImageBehavior = false;
			this->lstTable10->View = System::Windows::Forms::View::Details;
			// 
			// grpTable15
			// 
			this->grpTable15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable15->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable15->Controls->Add(this->lstTable15);
			this->grpTable15->ForeColor = System::Drawing::Color::Red;
			this->grpTable15->Location = System::Drawing::Point(380, 435);
			this->grpTable15->Name = L"grpTable15";
			this->grpTable15->Size = System::Drawing::Size(178, 111);
			this->grpTable15->TabIndex = 13;
			this->grpTable15->TabStop = false;
			this->grpTable15->Text = L"Table 15";
			// 
			// lstTable15
			// 
			this->lstTable15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable15->FullRowSelect = true;
			this->lstTable15->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable15->LabelWrap = false;
			this->lstTable15->Location = System::Drawing::Point(6, 14);
			this->lstTable15->MultiSelect = false;
			this->lstTable15->Name = L"lstTable15";
			this->lstTable15->Size = System::Drawing::Size(166, 82);
			this->lstTable15->TabIndex = 9;
			this->lstTable15->UseCompatibleStateImageBehavior = false;
			this->lstTable15->View = System::Windows::Forms::View::Details;
			// 
			// grpTable12
			// 
			this->grpTable12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable12->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable12->Controls->Add(this->lstTable12);
			this->grpTable12->ForeColor = System::Drawing::Color::Red;
			this->grpTable12->Location = System::Drawing::Point(196, 435);
			this->grpTable12->Name = L"grpTable12";
			this->grpTable12->Size = System::Drawing::Size(178, 111);
			this->grpTable12->TabIndex = 12;
			this->grpTable12->TabStop = false;
			this->grpTable12->Text = L"Table 12";
			// 
			// lstTable12
			// 
			this->lstTable12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable12->FullRowSelect = true;
			this->lstTable12->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable12->LabelWrap = false;
			this->lstTable12->Location = System::Drawing::Point(6, 14);
			this->lstTable12->MultiSelect = false;
			this->lstTable12->Name = L"lstTable12";
			this->lstTable12->Size = System::Drawing::Size(166, 82);
			this->lstTable12->TabIndex = 9;
			this->lstTable12->UseCompatibleStateImageBehavior = false;
			this->lstTable12->View = System::Windows::Forms::View::Details;
			// 
			// grpTable13
			// 
			this->grpTable13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable13->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable13->Controls->Add(this->lstTable13);
			this->grpTable13->Location = System::Drawing::Point(472, 318);
			this->grpTable13->Name = L"grpTable13";
			this->grpTable13->Size = System::Drawing::Size(224, 111);
			this->grpTable13->TabIndex = 10;
			this->grpTable13->TabStop = false;
			this->grpTable13->Text = L"Table 13";
			// 
			// lstTable13
			// 
			this->lstTable13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable13->FullRowSelect = true;
			this->lstTable13->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable13->LabelWrap = false;
			this->lstTable13->Location = System::Drawing::Point(6, 14);
			this->lstTable13->MultiSelect = false;
			this->lstTable13->Name = L"lstTable13";
			this->lstTable13->Size = System::Drawing::Size(212, 82);
			this->lstTable13->TabIndex = 9;
			this->lstTable13->UseCompatibleStateImageBehavior = false;
			this->lstTable13->View = System::Windows::Forms::View::Details;
			// 
			// grpTable11
			// 
			this->grpTable11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable11->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable11->Controls->Add(this->lstTable11);
			this->grpTable11->ForeColor = System::Drawing::Color::Red;
			this->grpTable11->Location = System::Drawing::Point(12, 435);
			this->grpTable11->Name = L"grpTable11";
			this->grpTable11->Size = System::Drawing::Size(178, 111);
			this->grpTable11->TabIndex = 14;
			this->grpTable11->TabStop = false;
			this->grpTable11->Text = L"Table 11";
			// 
			// lstTable11
			// 
			this->lstTable11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable11->FullRowSelect = true;
			this->lstTable11->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable11->LabelWrap = false;
			this->lstTable11->Location = System::Drawing::Point(6, 14);
			this->lstTable11->MultiSelect = false;
			this->lstTable11->Name = L"lstTable11";
			this->lstTable11->Size = System::Drawing::Size(166, 82);
			this->lstTable11->TabIndex = 9;
			this->lstTable11->UseCompatibleStateImageBehavior = false;
			this->lstTable11->View = System::Windows::Forms::View::Details;
			// 
			// grpTable14
			// 
			this->grpTable14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable14->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable14->Controls->Add(this->lstTable14);
			this->grpTable14->Location = System::Drawing::Point(702, 318);
			this->grpTable14->Name = L"grpTable14";
			this->grpTable14->Size = System::Drawing::Size(224, 111);
			this->grpTable14->TabIndex = 11;
			this->grpTable14->TabStop = false;
			this->grpTable14->Text = L"Table 14";
			// 
			// lstTable14
			// 
			this->lstTable14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable14->FullRowSelect = true;
			this->lstTable14->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable14->LabelWrap = false;
			this->lstTable14->Location = System::Drawing::Point(6, 14);
			this->lstTable14->MultiSelect = false;
			this->lstTable14->Name = L"lstTable14";
			this->lstTable14->Size = System::Drawing::Size(212, 82);
			this->lstTable14->TabIndex = 9;
			this->lstTable14->UseCompatibleStateImageBehavior = false;
			this->lstTable14->View = System::Windows::Forms::View::Details;
			// 
			// grpTable16
			// 
			this->grpTable16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable16->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable16->Controls->Add(this->lstTable16);
			this->grpTable16->ForeColor = System::Drawing::Color::Red;
			this->grpTable16->Location = System::Drawing::Point(564, 435);
			this->grpTable16->Name = L"grpTable16";
			this->grpTable16->Size = System::Drawing::Size(178, 111);
			this->grpTable16->TabIndex = 12;
			this->grpTable16->TabStop = false;
			this->grpTable16->Text = L"Table 16";
			// 
			// lstTable16
			// 
			this->lstTable16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable16->FullRowSelect = true;
			this->lstTable16->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable16->LabelWrap = false;
			this->lstTable16->Location = System::Drawing::Point(6, 14);
			this->lstTable16->MultiSelect = false;
			this->lstTable16->Name = L"lstTable16";
			this->lstTable16->Size = System::Drawing::Size(166, 82);
			this->lstTable16->TabIndex = 9;
			this->lstTable16->UseCompatibleStateImageBehavior = false;
			this->lstTable16->View = System::Windows::Forms::View::Details;
			// 
			// grpTable17
			// 
			this->grpTable17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpTable17->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grpTable17->Controls->Add(this->lstTable17);
			this->grpTable17->ForeColor = System::Drawing::Color::Red;
			this->grpTable17->Location = System::Drawing::Point(748, 435);
			this->grpTable17->Name = L"grpTable17";
			this->grpTable17->Size = System::Drawing::Size(178, 111);
			this->grpTable17->TabIndex = 17;
			this->grpTable17->TabStop = false;
			this->grpTable17->Text = L"Table 17";
			// 
			// lstTable17
			// 
			this->lstTable17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstTable17->FullRowSelect = true;
			this->lstTable17->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lstTable17->LabelWrap = false;
			this->lstTable17->Location = System::Drawing::Point(6, 14);
			this->lstTable17->MultiSelect = false;
			this->lstTable17->Name = L"lstTable17";
			this->lstTable17->Size = System::Drawing::Size(166, 82);
			this->lstTable17->TabIndex = 9;
			this->lstTable17->UseCompatibleStateImageBehavior = false;
			this->lstTable17->View = System::Windows::Forms::View::Details;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuFile, this->mnuOptions, 
				this->mnuHelp});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(938, 24);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mnuFile
			// 
			this->mnuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mnuExport, this->mnuQuit});
			this->mnuFile->Name = L"mnuFile";
			this->mnuFile->Size = System::Drawing::Size(37, 20);
			this->mnuFile->Text = L"&File";
			// 
			// mnuExport
			// 
			this->mnuExport->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mnuExportAll});
			this->mnuExport->Name = L"mnuExport";
			this->mnuExport->Size = System::Drawing::Size(143, 22);
			this->mnuExport->Text = L"&Export to text";
			// 
			// mnuExportAll
			// 
			this->mnuExportAll->Name = L"mnuExportAll";
			this->mnuExportAll->Size = System::Drawing::Size(125, 22);
			this->mnuExportAll->Text = L"&All Tables";
			this->mnuExportAll->Click += gcnew System::EventHandler(this, &Form1::mnuExportAll_Click);
			// 
			// mnuQuit
			// 
			this->mnuQuit->Name = L"mnuQuit";
			this->mnuQuit->Size = System::Drawing::Size(143, 22);
			this->mnuQuit->Text = L"&Quit";
			this->mnuQuit->Click += gcnew System::EventHandler(this, &Form1::mnuQuit_Click);
			// 
			// mnuOptions
			// 
			this->mnuOptions->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->mnuShowAllCharms, 
				this->mnuShowCursedTables, this->toolStripSeparator1, this->mnuSortBySkill, this->mnuSortByRNG, this->mnuSortAlpha, this->toolStripMenuItem1});
			this->mnuOptions->Name = L"mnuOptions";
			this->mnuOptions->Size = System::Drawing::Size(61, 20);
			this->mnuOptions->Text = L"&Options";
			// 
			// mnuShowAllCharms
			// 
			this->mnuShowAllCharms->Name = L"mnuShowAllCharms";
			this->mnuShowAllCharms->Size = System::Drawing::Size(202, 22);
			this->mnuShowAllCharms->Text = L"Show &All Charms";
			this->mnuShowAllCharms->Click += gcnew System::EventHandler(this, &Form1::mnuShowAllCharms_Click);
			// 
			// mnuShowCursedTables
			// 
			this->mnuShowCursedTables->Checked = true;
			this->mnuShowCursedTables->CheckState = System::Windows::Forms::CheckState::Checked;
			this->mnuShowCursedTables->ForeColor = System::Drawing::Color::Red;
			this->mnuShowCursedTables->Name = L"mnuShowCursedTables";
			this->mnuShowCursedTables->Size = System::Drawing::Size(202, 22);
			this->mnuShowCursedTables->Text = L"Show &Cursed Tables";
			this->mnuShowCursedTables->Click += gcnew System::EventHandler(this, &Form1::mnuShowCursedTables_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(199, 6);
			// 
			// mnuSortBySkill
			// 
			this->mnuSortBySkill->Checked = true;
			this->mnuSortBySkill->CheckState = System::Windows::Forms::CheckState::Checked;
			this->mnuSortBySkill->Name = L"mnuSortBySkill";
			this->mnuSortBySkill->Size = System::Drawing::Size(202, 22);
			this->mnuSortBySkill->Text = L"Sort charms by &Skill";
			this->mnuSortBySkill->Click += gcnew System::EventHandler(this, &Form1::SortOptionClicked);
			// 
			// mnuSortByRNG
			// 
			this->mnuSortByRNG->Name = L"mnuSortByRNG";
			this->mnuSortByRNG->Size = System::Drawing::Size(202, 22);
			this->mnuSortByRNG->Text = L"Sort charms by &RNG";
			this->mnuSortByRNG->Click += gcnew System::EventHandler(this, &Form1::SortOptionClicked);
			// 
			// mnuSortAlpha
			// 
			this->mnuSortAlpha->Checked = true;
			this->mnuSortAlpha->CheckOnClick = true;
			this->mnuSortAlpha->CheckState = System::Windows::Forms::CheckState::Checked;
			this->mnuSortAlpha->Name = L"mnuSortAlpha";
			this->mnuSortAlpha->Size = System::Drawing::Size(202, 22);
			this->mnuSortAlpha->Text = L"Sort Skills &Alphabetically";
			this->mnuSortAlpha->Click += gcnew System::EventHandler(this, &Form1::mnuSortAlpha_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(199, 6);
			// 
			// mnuHelp
			// 
			this->mnuHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuFAQ, this->mnuUpdate, 
				this->mnuAbout});
			this->mnuHelp->Name = L"mnuHelp";
			this->mnuHelp->Size = System::Drawing::Size(44, 20);
			this->mnuHelp->Text = L"&Help";
			// 
			// mnuFAQ
			// 
			this->mnuFAQ->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(17) {this->mnuWhatAre, this->mnuHowKnow, 
				this->mnuDoesItMatter, this->mnuWhatCursed, this->mnuBestTable, this->mnuHowChange, this->mnuGetCharmTable, this->toolStripSeparator2, 
				this->mnuWhatShowAll, this->mnuCharmColors, this->mnuAboutCharms, this->mnuWhereCharms, this->mnuBestCharms, this->mnuCharmTime, 
				this->mnuHowFarmCharms, this->mnuHowHard, this->mnuWhatToDo});
			this->mnuFAQ->Name = L"mnuFAQ";
			this->mnuFAQ->Size = System::Drawing::Size(171, 22);
			this->mnuFAQ->Text = L"FAQ";
			// 
			// mnuWhatAre
			// 
			this->mnuWhatAre->Name = L"mnuWhatAre";
			this->mnuWhatAre->Size = System::Drawing::Size(343, 22);
			this->mnuWhatAre->Text = L"What are charm tables\?";
			this->mnuWhatAre->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuHowKnow
			// 
			this->mnuHowKnow->Name = L"mnuHowKnow";
			this->mnuHowKnow->Size = System::Drawing::Size(343, 22);
			this->mnuHowKnow->Text = L"How do I know which charm table I\'m on\?";
			this->mnuHowKnow->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuDoesItMatter
			// 
			this->mnuDoesItMatter->Name = L"mnuDoesItMatter";
			this->mnuDoesItMatter->Size = System::Drawing::Size(343, 22);
			this->mnuDoesItMatter->Text = L"Does it matter which charm table I\'m on\?";
			this->mnuDoesItMatter->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuWhatCursed
			// 
			this->mnuWhatCursed->Name = L"mnuWhatCursed";
			this->mnuWhatCursed->Size = System::Drawing::Size(343, 22);
			this->mnuWhatCursed->Text = L"What are the \"cursed\" charm tables\?";
			this->mnuWhatCursed->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuBestTable
			// 
			this->mnuBestTable->Name = L"mnuBestTable";
			this->mnuBestTable->Size = System::Drawing::Size(343, 22);
			this->mnuBestTable->Text = L"What is the best charm table\?";
			this->mnuBestTable->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuHowChange
			// 
			this->mnuHowChange->Name = L"mnuHowChange";
			this->mnuHowChange->Size = System::Drawing::Size(343, 22);
			this->mnuHowChange->Text = L"How do I change charm tables\?";
			this->mnuHowChange->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuGetCharmTable
			// 
			this->mnuGetCharmTable->Name = L"mnuGetCharmTable";
			this->mnuGetCharmTable->Size = System::Drawing::Size(343, 22);
			this->mnuGetCharmTable->Text = L"How do I get the charm table I want\?";
			this->mnuGetCharmTable->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(340, 6);
			// 
			// mnuWhatShowAll
			// 
			this->mnuWhatShowAll->Name = L"mnuWhatShowAll";
			this->mnuWhatShowAll->Size = System::Drawing::Size(343, 22);
			this->mnuWhatShowAll->Text = L"What does \"Show All Charms\" do\?";
			this->mnuWhatShowAll->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuCharmColors
			// 
			this->mnuCharmColors->Name = L"mnuCharmColors";
			this->mnuCharmColors->Size = System::Drawing::Size(343, 22);
			this->mnuCharmColors->Text = L"What do the different charm colors mean\?";
			this->mnuCharmColors->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuAboutCharms
			// 
			this->mnuAboutCharms->Name = L"mnuAboutCharms";
			this->mnuAboutCharms->Size = System::Drawing::Size(343, 22);
			this->mnuAboutCharms->Text = L"What are charms, and why should I care\?";
			this->mnuAboutCharms->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuWhereCharms
			// 
			this->mnuWhereCharms->Name = L"mnuWhereCharms";
			this->mnuWhereCharms->Size = System::Drawing::Size(343, 22);
			this->mnuWhereCharms->Text = L"Where do I find charms in-game\?";
			this->mnuWhereCharms->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuBestCharms
			// 
			this->mnuBestCharms->Name = L"mnuBestCharms";
			this->mnuBestCharms->Size = System::Drawing::Size(343, 22);
			this->mnuBestCharms->Text = L"What are the best charms\?";
			this->mnuBestCharms->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuCharmTime
			// 
			this->mnuCharmTime->Name = L"mnuCharmTime";
			this->mnuCharmTime->Size = System::Drawing::Size(343, 22);
			this->mnuCharmTime->Text = L"Do I have to spend much time farming for charms\?";
			this->mnuCharmTime->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuHowFarmCharms
			// 
			this->mnuHowFarmCharms->Name = L"mnuHowFarmCharms";
			this->mnuHowFarmCharms->Size = System::Drawing::Size(343, 22);
			this->mnuHowFarmCharms->Text = L"What\'s the best way to farm for charms\?";
			this->mnuHowFarmCharms->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuHowHard
			// 
			this->mnuHowHard->Name = L"mnuHowHard";
			this->mnuHowHard->Size = System::Drawing::Size(343, 22);
			this->mnuHowHard->Text = L"How hard is it to get a specific charm\?";
			this->mnuHowHard->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuWhatToDo
			// 
			this->mnuWhatToDo->Name = L"mnuWhatToDo";
			this->mnuWhatToDo->Size = System::Drawing::Size(343, 22);
			this->mnuWhatToDo->Text = L"What should I do with my charms\?";
			this->mnuWhatToDo->Click += gcnew System::EventHandler(this, &Form1::ShowFAQ);
			// 
			// mnuUpdate
			// 
			this->mnuUpdate->Name = L"mnuUpdate";
			this->mnuUpdate->Size = System::Drawing::Size(171, 22);
			this->mnuUpdate->Text = L"Check for &Updates";
			this->mnuUpdate->Click += gcnew System::EventHandler(this, &Form1::mnuUpdate_Click);
			// 
			// mnuAbout
			// 
			this->mnuAbout->Name = L"mnuAbout";
			this->mnuAbout->Size = System::Drawing::Size(171, 22);
			this->mnuAbout->Text = L"&About";
			this->mnuAbout->Click += gcnew System::EventHandler(this, &Form1::mnuAbout_Click);
			// 
			// btnWTF
			// 
			this->btnWTF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnWTF->Location = System::Drawing::Point(516, 44);
			this->btnWTF->Name = L"btnWTF";
			this->btnWTF->Size = System::Drawing::Size(31, 23);
			this->btnWTF->TabIndex = 19;
			this->btnWTF->Text = L"\?";
			this->btnWTF->UseVisualStyleBackColor = true;
			this->btnWTF->Click += gcnew System::EventHandler(this, &Form1::btnWTF_Click);
			// 
			// cxtCharmData
			// 
			this->cxtCharmData->Name = L"cxtCharmData";
			this->cxtCharmData->Size = System::Drawing::Size(61, 4);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 563);
			this->Controls->Add(this->btnWTF);
			this->Controls->Add(this->grpTable10);
			this->Controls->Add(this->grpTable16);
			this->Controls->Add(this->grpTable11);
			this->Controls->Add(this->grpTable17);
			this->Controls->Add(this->grpTable15);
			this->Controls->Add(this->grpTable9);
			this->Controls->Add(this->grpTable12);
			this->Controls->Add(this->grpTable13);
			this->Controls->Add(this->grpTable6);
			this->Controls->Add(this->grpTable8);
			this->Controls->Add(this->grpTable5);
			this->Controls->Add(this->grpTable14);
			this->Controls->Add(this->grpTable4);
			this->Controls->Add(this->grpTable7);
			this->Controls->Add(this->grpTable3);
			this->Controls->Add(this->grpTable2);
			this->Controls->Add(this->grpTable1);
			this->Controls->Add(this->grpCriteria);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Athena\'s MH3G/U Charm Table Search";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSlots))->EndInit();
			this->grpCriteria->ResumeLayout(false);
			this->grpCriteria->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSkill2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSkill1))->EndInit();
			this->grpTable1->ResumeLayout(false);
			this->grpTable2->ResumeLayout(false);
			this->grpTable3->ResumeLayout(false);
			this->grpTable4->ResumeLayout(false);
			this->grpTable5->ResumeLayout(false);
			this->grpTable6->ResumeLayout(false);
			this->grpTable9->ResumeLayout(false);
			this->grpTable8->ResumeLayout(false);
			this->grpTable7->ResumeLayout(false);
			this->grpTable10->ResumeLayout(false);
			this->grpTable15->ResumeLayout(false);
			this->grpTable12->ResumeLayout(false);
			this->grpTable13->ResumeLayout(false);
			this->grpTable11->ResumeLayout(false);
			this->grpTable14->ResumeLayout(false);
			this->grpTable16->ResumeLayout(false);
			this->grpTable17->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void InitExportMenuItems()
		{
			for( unsigned i = 1; i <= 17; ++i )
			{
				ToolStripMenuItem^ item = gcnew ToolStripMenuItem( L"Table " + i );
				item->Tag = i;
				item->Click += gcnew EventHandler( this, &Form1::ExportSpecificTable );
				if( IsCursed( i ) )
					item->ForeColor = Color::Red;
				mnuExport->DropDownItems->Add( item );
			}
		}

		void SetupGroupsAndLists()
		{
			groups = gcnew array< GroupBox^ >( 17 );
			lists = gcnew array< ListView^ >( 17 );

			groups[ 0 ]  = grpTable1;  lists[ 0 ]  = lstTable1;
 			groups[ 1 ]  = grpTable2;  lists[ 1 ]  = lstTable2;
 			groups[ 2 ]  = grpTable3;  lists[ 2 ]  = lstTable3;
 			groups[ 3 ]  = grpTable4;  lists[ 3 ]  = lstTable4;
 			groups[ 4 ]  = grpTable5;  lists[ 4 ]  = lstTable5;
 			groups[ 5 ]  = grpTable6;  lists[ 5 ]  = lstTable6;
 			groups[ 6 ]  = grpTable7;  lists[ 6 ]  = lstTable7;
 			groups[ 7 ]  = grpTable8;  lists[ 7 ]  = lstTable8;
 			groups[ 8 ]  = grpTable9;  lists[ 8 ]  = lstTable9;
 			groups[ 9 ]  = grpTable10; lists[ 9 ]  = lstTable10;
 			groups[ 10 ] = grpTable11; lists[ 10 ] = lstTable11;
 			groups[ 11 ] = grpTable12; lists[ 11 ] = lstTable12;
 			groups[ 12 ] = grpTable13; lists[ 12 ] = lstTable13;
 			groups[ 13 ] = grpTable14; lists[ 13 ] = lstTable14;
 			groups[ 14 ] = grpTable15; lists[ 14 ] = lstTable15;
 			groups[ 15 ] = grpTable16; lists[ 15 ] = lstTable16;
 			groups[ 16 ] = grpTable17; lists[ 16 ] = lstTable17;

			for( int i = 0; i < lists->Length; ++i )
			{
				lists[ i ]->Columns->Add( L"col1" );
				lists[ i ]->MouseClick += gcnew MouseEventHandler( this, &Form1::ListViewMouseClick );
			}
		}

		void ListViewMouseClick( System::Object^ sender, MouseEventArgs^ e )
		{
			if( e->Button != System::Windows::Forms::MouseButtons::Right )
				return;
			ListView^ lv = safe_cast< ListView^ >( sender );
			ListViewItem^ item = lv->GetItemAt( e->X, e->Y );
			if( item )
			{
				CharmDatum^ data = safe_cast< CharmDatum^ >( item->Tag );
				cxtCharmData->Items->Clear();
				cxtCharmData->Items->Add( rngno_string + L" = " + data->num );
				cxtCharmData->Items->Add( seed_string + L" = " + data->seed );
				cxtCharmData->Show( lv, e->Location );
			}
		}

		String^ GetCharmString( const unsigned charm_hash )
		{
			const unsigned num_slots = GetCharmSlots( charm_hash );
			const unsigned skill1 = GetCharmAbility1Index( charm_hash );
			const unsigned skill2 = GetCharmAbility2Index( charm_hash );
			const unsigned point1 = GetCharmAbility1Points( charm_hash );
			const int point2 = GetCharmAbility2Points( charm_hash );

			System::Text::StringBuilder sb;
			if( point1 > 0 )
			{
				sb.Append( L"+" );
				sb.Append( point1 );
				sb.Append( L" " );
				sb.Append( CharmDatabase::ability_names[ skill1 ] );
			}
			if( point2 != 0 )
			{
				sb.Append( L", " );
				if( point2 > 0 )
					sb.Append( L"+" );
				sb.Append( point2 );
				sb.Append( L" " );
				sb.Append( CharmDatabase::ability_names[ skill2 ] );
			}
			sb.Append( L" " );
			array< String^ >^ slot_strings = { L"---", L"O--", L"OO-", L"OOO" };
			sb.Append( slot_strings[ num_slots ] );

			return sb.ToString();
		}

		void UpdateTableResults( const unsigned i, System::Object^ sender )
		{
			Generic::List< CharmDatum^ >^ charms = CharmDatabase::charm_hashes[ i ];
			int skill1_index = Math::Max( cmbSkill1->SelectedIndex - 1, -1 );
			int skill2_index = Math::Max( cmbSkill2->SelectedIndex - 1, -1 );
			if( mnuSortAlpha->Checked )
			{
				if( skill1_index != -1 )
					skill1_index = skill_alpha_to_index[ skill1_index ];
				if( skill2_index != -1 )
					skill2_index = skill_alpha_to_index[ skill2_index ];
			}

			if( skill1_index != -1 )
			{
				if( skill2_index != -1 )
				{
					charms = CharmDatabase::skill2_hashes[ i, skill1_index, skill2_index ];
				}
				else
				{
					charms = CharmDatabase::skill1_hashes[ i, skill1_index ];
					if( sender == cmbSkill1 || sender == cmbSkill2 )
					{
						sort_by_ability = skill1_index;
						if( sort_by_skill )
							charms->Sort( gcnew Comparison< CharmDatum^ >( CompareCharmsByAbility ) );
						else
							charms->Sort( gcnew Comparison< CharmDatum^ >( CompareCharmsByRNG ) );
					}
				}
			}

			lists[ i ]->BeginUpdate();
			lists[ i ]->Items->Clear();

			if( charms )
			{
				if( sender && sender != cmbSkill1 && sender != cmbSkill2 )
				{
					if( sort_by_skill  )
						charms->Sort( gcnew Comparison< CharmDatum^ >( CompareCharmsByAbility ) );
					else
						charms->Sort( gcnew Comparison< CharmDatum^ >( CompareCharmsByRNG ) );
				}

				for each( CharmDatum^ datum in charms )
				{
					const unsigned charm_hash = datum->hash;
					const unsigned num_slots = GetCharmSlots( charm_hash );
					const unsigned skill1 = GetCharmAbility1Index( charm_hash );
					const unsigned skill2 = GetCharmAbility2Index( charm_hash );
					const unsigned point1 = GetCharmAbility1Points( charm_hash );
					const int point2 = GetCharmAbility2Points( charm_hash );

					if( num_slots < nudSlots->Value )
						continue;

					if( skill1_index != -1 )
					{
						if( skill2_index != -1 )
						{
							if( skill1_index == skill1 && skill2_index == skill2 )
							{
								if( nudSkill1->Value != 0 && point1 < nudSkill1->Value ||
									nudSkill2->Value != 0 && point2 < nudSkill2->Value )
									continue;
							}
							else if( skill1_index == skill2 && skill2_index == skill1 )
							{
								if( nudSkill1->Value != 0 && point2 < nudSkill1->Value ||
									nudSkill2->Value != 0 && point1 < nudSkill2->Value )
									continue;
							}
							else continue;
						}
						else
						{
							if( skill1_index == skill1 )
							{
								if( nudSkill1->Value != 0 && point1 < nudSkill1->Value )
									continue;
							}
							else if( skill1_index == skill2 )
							{
								if( nudSkill1->Value != 0 && point2 < nudSkill1->Value )
									continue;
							}
							else continue;
						}
					}
					else if( skill2_index != -1 )
					{
						if( skill2_index == skill1 )
						{
							if( nudSkill2->Value != 0 && point1 < nudSkill2->Value )
								continue;
						}
						else if( skill2_index == skill2 )
						{
							if( nudSkill2->Value != 0 && point2 < nudSkill2->Value )
								continue;
						}
						else continue;
					}
					else if( !mnuShowAllCharms->Checked && nudSlots->Value < 3 )
						continue;
					
					ListViewItem^ item = gcnew ListViewItem( GetCharmString( charm_hash ) );
					item->ForeColor = CharmDatabase::charm_colors[ GetCharmType( charm_hash ) ];
					item->Tag = datum;
					lists[ i ]->Items->Add( item );
				}
			}

			int max_width = 0;
			for each( ListViewItem^ item in lists[ i ]->Items )
				max_width = Math::Max( max_width, TextRenderer::MeasureText( item->Text, item->Font ).Width );
			lists[ i ]->Columns[ 0 ]->Width = max_width + 20;
			lists[ i ]->EndUpdate();
			UpdateResultString( i );
		}

		void UpdateResultString( const unsigned i )
		{
			groups[ i ]->Text = table_string + L" " + (i+1) + L" (" + lists[ i ]->Items->Count + L" " + ( lists[ i ]->Items->Count == 1 ? result_string : results_string ) + L")";
		}

		bool IsCursed( const unsigned table )
		{
			for each( const unsigned t in cursed )
			{
				if( t == table )
					return true;
			}
			return false;
		}

		void SettingsChanged( System::Object^ sender, System::EventArgs^ e )
		{
			if( lock_results ||
				sender == nudSkill1 && cmbSkill1->SelectedIndex < 1 ||
				sender == nudSkill2 && cmbSkill2->SelectedIndex < 1 ||
				sender == nudSlots && cmbSkill1->SelectedIndex < 1 && cmbSkill2->SelectedIndex < 1 && nudSlots->Value < 2 )
				return;

			if( mnuShowCursedTables->Checked )
			{
				for( unsigned i = 0; i < 17; ++i )
				{
					UpdateTableResults( i, sender );
				}
			}
			else
			{
				for( unsigned i = 0; i < 17; ++i )
				{
					if( !IsCursed( i + 1 ) )
						UpdateTableResults( i, sender );
				}
			}
			
		}
	
		System::Void mnuShowAllCharms_Click(System::Object^  sender, System::EventArgs^  e)
		{
			mnuShowAllCharms->Checked = !mnuShowAllCharms->Checked;
			if( nudSlots->Value < 3 && cmbSkill1->SelectedIndex < 1 && cmbSkill2->SelectedIndex < 1 )
				SettingsChanged( nullptr, nullptr );
		}

		System::Void mnuQuit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Close();
		}

		System::Void mnuShowCursedTables_Click(System::Object^  sender, System::EventArgs^  e)
		{
			mnuShowCursedTables->Checked = !mnuShowCursedTables->Checked;
			for( int i = 0; i < cursed->Length; ++i )
			{
				const unsigned cursed_table = cursed[ i ] - 1;
				if( mnuShowCursedTables->Checked )
					UpdateTableResults( cursed_table, sender );
				lists[ cursed_table ]->Visible = mnuShowCursedTables->Checked;
				groups[ cursed_table ]->Visible = mnuShowCursedTables->Checked;
			}
		}

		System::Void LanguageChanged(System::Object^  sender, System::EventArgs^  e)
		{
			ToolStripMenuItem^ item = safe_cast< ToolStripMenuItem^ >( sender );
			if( item && !item->Checked )
			{
				mnuCurrent = item;
				LanguageChanged( item->Text );
				SaveSettings();
			}
		}

		void OffsetUI( Control^ to_move, Control^ to_left, const int extra )
		{
			to_move->Location = Point( to_left->Location.X + to_left->Width + extra, to_move->Location.Y );
		}

		System::Void LanguageChanged( String^ language )
		{
			SuspendLayout();
			lock_results++;

			for( int i = items_before_languages; i < mnuOptions->DropDownItems->Count; ++i )
			{
				((ToolStripMenuItem^)mnuOptions->DropDownItems[ i ])->Checked = false;
			}
			mnuCurrent->Checked = true;

			language = language->Replace( L"&", L"" );
			array< String^ >^ lines = IO::File::ReadAllLines( L"Languages/" + language + L".txt" );
			int i = 0;
			if( lines[ 0 ] != L"-" )
				translation_credits = lines[ 0 ];
			else translation_credits = nullptr;
			for( i = 1; i <= CharmDatabase::ability_names->Length; ++i )
				CharmDatabase::ability_names[ i-1 ] = lines[ i ];
			mnuFile->Text = lines[ i++ ];
			mnuQuit->Text = lines[ i++ ];
			mnuOptions->Text = lines[ i++ ];
			mnuShowAllCharms->Text = lines[ i++ ];
			mnuShowCursedTables->Text = lines[ i++ ];
			mnuHelp->Text = lines[ i++ ];
			mnuFAQ->Text = lines[ i++ ];
			mnuUpdate->Text = lines[ i++ ];
			mnuAbout->Text = lines[ i++ ];
			grpCriteria->Text = lines[ i++ ];
			lblSlots->Text = lines[ i++ ];
			lblSkill1->Text = lines[ i++ ];
			lblSkill2->Text = lines[ i++ ];
			table_string = lines[ i++ ];
			result_string = lines[ i++ ];
			results_string = lines[ i++ ];
			for( unsigned j = 1; j <= 17; ++j )
				UpdateResultString( j - 1 );
			rngno_string = lines[ i++ ];
			seed_string = lines[ i++ ];
			none_string = lines[ i++ ];
			close_string = lines[ i++ ];
			mnuSortBySkill->Text = lines[ i++ ];
			mnuSortByRNG->Text = lines[ i++ ];
			mnuSortAlpha->Text = lines[ i++ ];
			mnuExport->Text = lines[ i++ ];
			save_filetype_string = lines[ i++ ];
			save_filenameall_string = lines[ i++ ];
			mnuExportAll->Text = save_filenameall_string;
			save_format_string = lines[ i++ ];
			save_formatall_string = lines[ i++ ];
			mnuFAQ->DropDownItems->Clear();
			while( i < lines->Length )
			{
				if( lines[ i++ ]->StartsWith( L"???" ) )
				{
					ToolStripMenuItem^ item = gcnew ToolStripMenuItem( lines[ i-1 ]->Substring( 3 ) );
					if( item->Text == L"-" )
					{
						mnuFAQ->DropDownItems->Add( L"-" );
						continue;
					}
					item->Click += gcnew EventHandler( this, &Form1::ShowFAQ );
					String^ t = L"";
					while( i < lines->Length && !lines[ i ]->StartsWith( L"???" ) )
					{
						t += lines[ i++ ] + L"\n";
					}
					item->Tag = t;
					mnuFAQ->DropDownItems->Add( item );
				}
			}

			int old_skill1 = cmbSkill1->SelectedIndex;
			int old_skill2 = cmbSkill2->SelectedIndex;
			if( mnuSortAlpha->Checked )
			{
				if( old_skill1 > 0 )
					old_skill1 = skill_alpha_to_index[ old_skill1 - 1 ] + 1;
				if( old_skill2 > 0 )
					old_skill2 = skill_alpha_to_index[ old_skill2 - 1 ] + 1;
			}

			skill_alpha_to_index->Sort( skill_alpha_to_index, gcnew Comparison< unsigned >( CompareSkillIndices ) );
			for( int i = 0; i < skill_alpha_to_index->Length; ++i )
			{
				skill_index_to_alpha[ skill_alpha_to_index[ i ] ] = i;
			}

			UpdateSkillList( old_skill1, old_skill2 );
			
			int max_skill_width = 0;
			for( int j = 0; j < cmbSkill1->Items->Count; ++j )
				max_skill_width = Math::Max( max_skill_width, TextRenderer::MeasureText( cmbSkill1->Items[ j ]->ToString(), cmbSkill1->Font ).Width );
			cmbSkill1->Width = max_skill_width + 25;
			cmbSkill2->Width = max_skill_width + 25;

			OffsetUI( nudSlots, lblSlots, 6 );
			OffsetUI( lblSkill1, nudSlots, 6 );
			OffsetUI( nudSkill1, lblSkill1, 6 );
			OffsetUI( cmbSkill1, nudSkill1, 6 );
			OffsetUI( lblSkill2, cmbSkill1, 6 );
			OffsetUI( nudSkill2, lblSkill2, 6 );
			OffsetUI( cmbSkill2, nudSkill2, 6 );
			grpCriteria->Size = Drawing::Size( cmbSkill2->Location.X + cmbSkill2->Width + 10, grpCriteria->Size.Height );
			OffsetUI( btnWTF, grpCriteria, 6 );

			lock_results--;

			if( mnuShowAllCharms->Checked ||
				nudSlots->Value == 3 ||
				cmbSkill1->SelectedIndex > 0 ||
				cmbSkill2->SelectedIndex > 0 )
				SettingsChanged( nullptr, nullptr );

			ResumeLayout();
		}

		System::Void mnuAbout_Click(System::Object^  sender, System::EventArgs^  e)
		{
			frmAbout about( mnuAbout->Text, close_string, translation_credits );
			about.ShowDialog( this );
		}

		System::Void ShowFAQ(System::Object^  sender, System::EventArgs^  e)
		{
			Object^ tag = safe_cast< ToolStripMenuItem^ >( sender )->Tag;
			if( tag )
			{
				FAQ faq( mnuFAQ->Text, sender->ToString(), tag->ToString(), close_string );
				faq.ShowDialog( this );
			}
		}

		System::Void WindowResized( System::Object^ sender, System::EventArgs^ args )
		{
			SuspendLayout();
		
			const unsigned cx1 = 12;
			const unsigned cx2 = 12 + 1 * ( Width - 34 ) / 5;
			const unsigned cx3 = 12 + 2 * ( Width - 34 ) / 5;
			const unsigned cx4 = 12 + 3 * ( Width - 34 ) / 5;
			const unsigned cx5 = 12 + 4 * ( Width - 34 ) / 5;

			const unsigned nx1 = 12;
			const unsigned nx2 = 12 + 1 * ( Width - 34 ) / 4;
			const unsigned nx3 = 12 + 2 * ( Width - 34 ) / 4;
			const unsigned nx4 = 12 + 3 * ( Width - 34 ) / 4;
			
			const unsigned y1 = 84;
			const unsigned y2 = 84 + 1 * ( Height - 133 ) / 4;
			const unsigned y3 = 84 + 2 * ( Height - 133 ) / 4;
			const unsigned y4 = 84 + 3 * ( Height - 133 ) / 4;

			const unsigned nszx = ( Width - 34 ) / 4 - 5;
			const unsigned cszx = ( Width - 34 ) / 5 - 5;
			const unsigned szy = ( Height - 133 ) / 4 - 6;
			
			grpTable1->Location = Point( nx1, y1 ); grpTable1->Size = Drawing::Size( nszx, szy );
			grpTable2->Location = Point( nx2, y1 ); grpTable2->Size = Drawing::Size( nszx, szy );
			grpTable3->Location = Point( nx3, y1 ); grpTable3->Size = Drawing::Size( nszx, szy );
			grpTable4->Location = Point( nx4, y1 ); grpTable4->Size = Drawing::Size( nszx, szy );

			grpTable5->Location = Point( nx1, y2 ); grpTable5->Size = Drawing::Size( nszx, szy );
			grpTable6->Location = Point( nx2, y2 ); grpTable6->Size = Drawing::Size( nszx, szy );
			grpTable7->Location = Point( nx3, y2 ); grpTable7->Size = Drawing::Size( nszx, szy );
			grpTable8->Location = Point( nx4, y2 ); grpTable8->Size = Drawing::Size( nszx, szy );

			grpTable9->Location = Point( nx1, y3 ); grpTable9->Size = Drawing::Size( nszx, szy );
			grpTable10->Location = Point( nx2, y3 ); grpTable10->Size = Drawing::Size( nszx, szy );
			grpTable13->Location = Point( nx3, y3 ); grpTable13->Size = Drawing::Size( nszx, szy );
			grpTable14->Location = Point( nx4, y3 ); grpTable14->Size = Drawing::Size( nszx, szy );

			grpTable11->Location = Point( cx1, y4 ); grpTable11->Size = Drawing::Size( cszx, szy );
			grpTable12->Location = Point( cx2, y4 ); grpTable12->Size = Drawing::Size( cszx, szy );
			grpTable15->Location = Point( cx3, y4 ); grpTable15->Size = Drawing::Size( cszx, szy );
			grpTable16->Location = Point( cx4, y4 ); grpTable16->Size = Drawing::Size( cszx, szy );
			grpTable17->Location = Point( cx5, y4 ); grpTable17->Size = Drawing::Size( cszx, szy );

			ResumeLayout();
		}

		System::Void btnWTF_Click(System::Object^  sender, System::EventArgs^  e)
		{
			mnuHelp->ShowDropDown();
			mnuFAQ->ShowDropDown();
		}

		System::Void mnuUpdate_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Diagnostics::Process::Start( "http://forums.minegarde.com/topic/6766-athenas-charm-table-search-for-monster-hunter-3g-monster-hunter-3u/" );
		}

		System::Void SortOptionClicked(System::Object^  sender, System::EventArgs^  e)
		{
			if( sort_by_skill )
			{
				if( sender == mnuSortByRNG )
				{
					sort_by_skill = false;
					mnuSortBySkill->Checked = false;
					mnuSortByRNG->Checked = true;
					SettingsChanged( sender, nullptr );
				}
			}
			else
			{
				if( sender == mnuSortBySkill )
				{
					sort_by_skill = true;
					mnuSortByRNG->Checked = false;
					mnuSortBySkill->Checked = true;
					SettingsChanged( sender, nullptr );
				}
			}
		}

		String^ GetSaveFilename( const unsigned table )
		{
			SaveFileDialog dlg;
			dlg.InitialDirectory = System::Environment::CurrentDirectory;
			dlg.DefaultExt = L".txt";
			dlg.AddExtension = true;
			dlg.Filter = save_filetype_string + L" (*.txt)|*.txt";
			dlg.FilterIndex = 0;
			if( table == 0 )
				dlg.FileName = save_filenameall_string + L".txt";
			else dlg.FileName = table_string + L" " + table + L".txt";
			::DialogResult res = dlg.ShowDialog();
			if( res == ::DialogResult::OK )
				return dlg.FileName;
			else return nullptr;
		}

		System::Void ExportTableData( const unsigned table, const bool print_table, IO::StreamWriter% fout ) //1-based
		{
			for each( ListViewItem^ item in lists[ table - 1 ]->Items )
			{
				CharmDatum^ d = (CharmDatum^)item->Tag;
				if( print_table )
				{
					fout.Write( Convert::ToString( table ) );
					fout.Write( L"," );
				}
				fout.Write( Convert::ToString( GetCharmType( d->hash ) ) );
				fout.Write( L"," );
				fout.Write( Convert::ToString( d->num ) );
				fout.Write( L"," );
				fout.Write( Convert::ToString( d->seed ) );
				fout.Write( L"," );
				fout.WriteLine( item->Text );
			}
		}

		System::Void mnuExportAll_Click( System::Object^  sender, System::EventArgs^ e )
		{
			String^ filename = GetSaveFilename( 0 );
			if( filename == nullptr )
				return;

			IO::StreamWriter fout( filename );
			fout.WriteLine( save_formatall_string );
			for( unsigned i = 1; i <= 17; ++i )
			{
				ExportTableData( i, true, fout );
			}
		}

		System::Void ExportSpecificTable( System::Object^  sender, System::EventArgs^ e )
		{
			const unsigned table = Convert::ToUInt32( safe_cast< ToolStripMenuItem^ >( sender )->Tag );
			if( lists[ table - 1]->Items->Count == 0 )
				return;

			String^ filename = GetSaveFilename( table );
			if( filename == nullptr )
				return;

			IO::StreamWriter fout( filename );
			fout.WriteLine( save_format_string );
			ExportTableData( table, false, fout );
		}

		void UpdateSkillList( int selected1, int selected2 )
		{
			cmbSkill1->BeginUpdate();
			cmbSkill2->BeginUpdate();

			cmbSkill1->Items->Clear();
			cmbSkill2->Items->Clear();

			cmbSkill1->Items->Add( none_string );
			cmbSkill2->Items->Add( none_string );

			if( mnuSortAlpha->Checked )
			{
				for( int i = 0; i < CharmDatabase::ability_names->Length; ++i )
				{
					cmbSkill1->Items->Add( CharmDatabase::ability_names[ skill_alpha_to_index[ i ] ] );
					cmbSkill2->Items->Add( CharmDatabase::ability_names[ skill_alpha_to_index[ i ] ] );
				}
				if( selected1 > 0 )
					selected1 = skill_index_to_alpha[ selected1 - 1 ] + 1;
				if( selected2 > 0 )
					selected2 = skill_index_to_alpha[ selected2 - 1 ] + 1;
			}
			else
			{
				cmbSkill1->Items->AddRange( CharmDatabase::ability_names );
				cmbSkill2->Items->AddRange( CharmDatabase::ability_names );
			}
			cmbSkill1->SelectedIndex = selected1;
			cmbSkill2->SelectedIndex = selected2;

			cmbSkill1->EndUpdate();
			cmbSkill2->EndUpdate();
		}

		System::Void mnuSortAlpha_Click(System::Object^  sender, System::EventArgs^  e)
		{
			lock_results++;

			int selected1 = cmbSkill1->SelectedIndex;
			int selected2 = cmbSkill2->SelectedIndex;

			if( !mnuSortAlpha->Checked )
			{
				if( selected1 > 0 )
					selected1 = skill_alpha_to_index[ selected1 - 1 ] + 1;
				if( selected2 > 0 )
					selected2 = skill_alpha_to_index[ selected2 - 1 ] + 1;
			}

			UpdateSkillList( selected1, selected2 );

			lock_results--;
		}
};
}