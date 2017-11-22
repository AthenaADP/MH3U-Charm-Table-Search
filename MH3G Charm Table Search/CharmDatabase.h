#pragma once

ref struct CharmDatum
{
	unsigned hash, seed, num;
};

ref struct CharmDatabase
{
	static array< System::Collections::Generic::List< CharmDatum^ >^ >^ charm_hashes;
	static array< System::Collections::Generic::List< CharmDatum^ >^, 2 >^ skill1_hashes;
	static array< System::Collections::Generic::List< CharmDatum^ >^, 3 >^ skill2_hashes;
	static array< System::String^ >^ ability_names;

	static array< System::Drawing::Color >^ charm_colors =
	{ 
		System::Drawing::Color::Gray,
		System::Drawing::Color::Goldenrod,
		System::Drawing::Color::Red,
		System::Drawing::Color::Blue
	};
};

void GenerateCharmTable();

unsigned GetCharmSlots( const unsigned charm_hash );
unsigned GetCharmAbility1Index( const unsigned charm_hash );
unsigned GetCharmAbility2Index( const unsigned charm_hash );
unsigned GetCharmAbility1Points( const unsigned charm_hash );
int GetCharmAbility2Points( const unsigned charm_hash );
unsigned GetCharmType( const unsigned charm_hash );
unsigned GetCharmTable( const unsigned charm_hash );
