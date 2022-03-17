#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Resources;
using namespace System::Collections;
using namespace System::Collections::Generic;
enum CreatureState { WALK, DYING, IDLE, ATTACK,NOSTATE,HURT };
#include "HeroAssets.h"


public ref class Pictures {

public:
	static Bitmap^ bgImage = LoadBitmap("battleground");
	static Bitmap^ armorIcon = LoadBitmap("armor");
	static Bitmap^ hpIcon = LoadBitmap("heart2");
	static Bitmap^ ammoIcon = LoadBitmap("ammo");
	static Bitmap^ ammoPack = LoadBitmap("ammo_pickup");
	static Bitmap^ lifePoints= LoadBitmap("hp_pickup");

private:	

	static List<HeroAssets^>^ _assetConfigs = gcnew List<HeroAssets^>();

	static Dictionary<String^, List<Bitmap^>^>^ _creatureWalkingAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureIdleAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureAttackAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureDyingAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureHurtAssets = gcnew Dictionary<String^, List<Bitmap^>^>();


public:static void loadAssets() {

	_assetConfigs->Add(gcnew HeroAssets(17, "Minotaur"));
	_assetConfigs->Add(gcnew HeroAssets(6, "Pirate"));
		
		for (int i = 0; i < 2; i++) {
			HeroAssets^ config = _assetConfigs[i];

			_creatureWalkingAssets->Add(config->getName(), config->getAssetsByState(CreatureState::WALK));
			_creatureIdleAssets->Add(config->getName(), config->getAssetsByState(CreatureState::IDLE));
			_creatureAttackAssets->Add(config->getName(), config->getAssetsByState(CreatureState::ATTACK));
			_creatureDyingAssets->Add(config->getName(), config->getAssetsByState(CreatureState::DYING));
			_creatureHurtAssets->Add(config->getName(), config->getAssetsByState(CreatureState::HURT));
		}
	}


public:static List<Bitmap^>^ getHeroAssets(String^ heroName,CreatureState state) {	

	switch (state) {
	case CreatureState::WALK:
		return _creatureWalkingAssets[heroName];
	case CreatureState::IDLE:
		return _creatureIdleAssets[heroName];
	case CreatureState::ATTACK:
		return _creatureAttackAssets[heroName];
	case CreatureState::DYING:
		return _creatureDyingAssets[heroName];
	case CreatureState::HURT:
		return _creatureHurtAssets[heroName];
	}
		
}

public:static Bitmap^ getAssetByName(String^ name) {

	if (name == "AmmoPack") {
		return ammoPack;
	}
	else if (name == "LifePoints") {
		return lifePoints;
	}
}
public:static int getHeroAssetLastImageIndex(String^ heroName) {
	
	for (int i = 0; i < _assetConfigs->Count; i++) {
		HeroAssets^ config = _assetConfigs[i];

		if (config->getName() == heroName) {
			return config->getLastImageIndex();
		}
	}
	return -1;
}
public:static Bitmap^ rotateImage(Bitmap^ img, float angle, Graphics^ grp) {

	Bitmap^ newImg = gcnew Bitmap(img->Width *1.2, img->Height*1.2);

	Graphics^ g = grp->FromImage(newImg);

	g->TranslateTransform((float)newImg->Width / 2, (float)newImg->Height / 2);
	g->RotateTransform(angle);
	g->TranslateTransform(-(float)newImg->Width / 2, -(float)newImg->Height / 2);
	g->DrawImage(img, 0, 0);

	delete g;
	return newImg;

	
}
public:static Bitmap^ LoadBitmap(String^ bitmapName) {
		Reflection::Assembly^ assembly = Reflection::Assembly::GetExecutingAssembly();
		ResourceManager^ resman = gcnew ResourceManager("OOPZerebkovs.Pictures", assembly);
		return (Bitmap^)resman->GetObject(bitmapName);
	}
};