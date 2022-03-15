#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Resources;
using namespace System::Collections;
using namespace System::Collections::Generic;
enum CreatureState { WALK, DYING, IDLE, ATTACK,NOSTATE };
#include "HeroAssets.h"


public ref class Pictures {

public:
	static Bitmap^ bgImage = LoadBitmap("battleground");
private:	

	static List<HeroAssets^>^ _assetConfigs = gcnew List<HeroAssets^>();

	static Dictionary<String^, List<Bitmap^>^>^ _creatureWalkingAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureIdleAssets = gcnew Dictionary<String^, List<Bitmap^>^>();
	static Dictionary<String^, List<Bitmap^>^>^ _creatureAttackAssets = gcnew Dictionary<String^, List<Bitmap^>^>();

public:static void loadAssets() {

	_assetConfigs->Add(gcnew HeroAssets(17, 0, 0,0, "Minotaur"));
	_assetConfigs->Add(gcnew HeroAssets(6, 0, 6,0,"Pirate"));
		
		for (int i = 0; i < 2; i++) {
			HeroAssets^ config = _assetConfigs[i];

			_creatureWalkingAssets->Add(config->getName(), config->getAssetsByState(CreatureState::WALK));
			_creatureIdleAssets->Add(config->getName(), config->getAssetsByState(CreatureState::IDLE));
			_creatureAttackAssets->Add(config->getName(), config->getAssetsByState(CreatureState::ATTACK));
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
	}
		
}
public:static int getHeroAssetLastImageIndex(String^ heroName, CreatureState state) {
	switch (state) {
	case CreatureState::WALK:
		return _creatureWalkingAssets[heroName]->Count;
	case CreatureState::IDLE:
		return _creatureIdleAssets[heroName]->Count;
	case CreatureState::ATTACK:
		return _creatureAttackAssets[heroName]->Count;
	}
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