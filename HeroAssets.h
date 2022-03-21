#pragma once

ref struct AssetIndexes
{
int lastAttackAssetIndex;
int lastIdleAssetIndex;
int lastHurtAssetIndex;
int lastWalkAssetIndex;
int lastDieAssetIndex;
};

ref class HeroAssets {


public: HeroAssets(AssetIndexes^ assetIndexes,String^ heroName) {
		_heroName = heroName;

		_assetIndexes = assetIndexes;
	
	}

public:List<Bitmap^>^ getAssetsByState(CreatureState state) {
		List<Bitmap^> ^ assets = gcnew List<Bitmap^>();
		String^ preffix = _getPreffix(state);
		int lastAssetIndex = getLastImageIndex(state);
		
		for (int i = 0; i <= lastAssetIndex; i++) {
			String^ assetName = _heroName + preffix + i.ToString();
			assets->Add(loadBitmap(assetName));
		}

		return assets;
	}


public: int getLastImageIndex(CreatureState state) {

	switch (state)
	{
	case CreatureState::WALK:
		return _assetIndexes->lastWalkAssetIndex;
	case CreatureState::ATTACK:
		return _assetIndexes->lastAttackAssetIndex;
	case CreatureState::DYING:
		return _assetIndexes->lastDieAssetIndex;
	case CreatureState::HURT:
		return _assetIndexes->lastHurtAssetIndex;
	case CreatureState::IDLE:
		return _assetIndexes->lastIdleAssetIndex;
	default:
		return -1;
		break;
	}
}

public: String^ getName() {
		return _heroName;
	}
private:String^ _getPreffix(CreatureState state) {
	switch (state) {
	case CreatureState::WALK:
		return "_Walking_";
	case CreatureState::IDLE:
		return "_Idle_";
	case CreatureState::ATTACK:
		return  "_Attack_";
	case CreatureState::DYING:
		return "_Die_";
	case CreatureState::HURT:
		return "_Hurt_";
	}

}
private:
	AssetIndexes^ _assetIndexes;
	String^ _heroName = gcnew String("");

	Bitmap^ loadBitmap(String^ bitmapName) {
	Reflection::Assembly^ assembly = Reflection::Assembly::GetExecutingAssembly();
	ResourceManager^ resman = gcnew ResourceManager("OOPZerebkovs.Pictures", assembly);
	return (Bitmap^)resman->GetObject(bitmapName);
	}
};