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
	static Bitmap^ scoreIcon = LoadBitmap("score_icon");
	static Bitmap^ greenContainer = LoadBitmap("green_container");
	static Bitmap^ redContainer = LoadBitmap("red_container");
	static Bitmap^ blueContainer = LoadBitmap("blue_container");
	static Bitmap^ yellowContainer = LoadBitmap("yellow_container");
	static Bitmap^ timerIcon = LoadBitmap("hourglass_icon");
private:	

	static List<HeroAssets^>^ _assetConfigs = gcnew List<HeroAssets^>();

	static Dictionary<String^, List<Bitmap^>^>^ _creatureWalkingAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureIdleAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureAttackAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureDyingAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureHurtAssets = gcnew Dictionary<String^, List<Bitmap^>^>();

	

public:static void loadAssets() {

	AssetIndexes^ minotaurAssetsIndexes = gcnew AssetIndexes{};
	AssetIndexes^ pirateAssetIndexes = gcnew AssetIndexes{};
	minotaurAssetsIndexes->lastAttackAssetIndex = 11;
	minotaurAssetsIndexes->lastWalkAssetIndex = 17;
	minotaurAssetsIndexes->lastHurtAssetIndex = 11;
	minotaurAssetsIndexes->lastDieAssetIndex = 14;

	pirateAssetIndexes->lastWalkAssetIndex = 6;
	pirateAssetIndexes->lastDieAssetIndex = 6;
	pirateAssetIndexes->lastHurtAssetIndex = 6;
	pirateAssetIndexes->lastIdleAssetIndex = 6;
	pirateAssetIndexes->lastAttackAssetIndex = 6;

	_assetConfigs->Add(gcnew HeroAssets(minotaurAssetsIndexes, "Minotaur"));
	_assetConfigs->Add(gcnew HeroAssets(pirateAssetIndexes, "Pirate"));
		
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
	else if (name == "GreenContainer") {
		return greenContainer;
	}
	else if (name == "RedContainer") {
		return redContainer;
	}
	else if (name == "YellowContainer") {
		return yellowContainer;
	}
	else if (name == "BlueContainer") {
		return blueContainer;
	}
}
public:static int getHeroAssetLastImageIndex(String^ heroName,CreatureState state) {
	
	for (int i = 0; i < _assetConfigs->Count; i++) {
		HeroAssets^ config = _assetConfigs[i];

		if (config->getName() == heroName) {
			return config->getLastImageIndex(state);
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