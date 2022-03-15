#pragma once


ref class HeroAssets {


public: HeroAssets(int lastWalkingAssetIndex,int lastDyingAssetIndex,int lastIdleAssetIndex,int lastAttackAssetIndex, String^ heroName) {
		_lastWalkingAssetIndex = lastWalkingAssetIndex;
		_lastDyingAssetIndex = lastDyingAssetIndex;
		_heroName = heroName;
		_lastIdleAssetIndex = lastIdleAssetIndex;
		_lastAttackAssetIndex = lastAttackAssetIndex;
		

	}

public:List<Bitmap^>^ getAssetsByState(CreatureState state) {
		List<Bitmap^> ^ assets = gcnew List<Bitmap^>();
		switch (state) {
		case CreatureState::WALK:
			for (int i = 0; i < _lastWalkingAssetIndex; i++) {
				String^ assetName = _heroName + "_Walking_" + i.ToString();

				assets->Add(loadBitmap(assetName));
			}
			break;
		case CreatureState::IDLE:
			for (int i = 0; i < _lastIdleAssetIndex; i++) {
				String^ assetName = _heroName + "_Idle_" + i.ToString();

				assets->Add(loadBitmap(assetName));
			}
			break;
		case CreatureState::ATTACK:
			for (int i = 0; i < _lastIdleAssetIndex; i++) {
				String^ assetName = _heroName + "_Attack_" + i.ToString();

				assets->Add(loadBitmap(assetName));
			}
			break;
		}
		

		return assets;
	}

public: int getLastImageIndexByState(CreatureState state) {
	switch (state) {
	case CreatureState::WALK:
		return _lastWalkingAssetIndex;
	case CreatureState::DYING:
		return _lastDyingAssetIndex;
	case CreatureState::IDLE:
		return _lastIdleAssetIndex;
	case CreatureState::ATTACK:
		return _lastAttackAssetIndex;
	}
}

public: String^ getName() {
		return _heroName;
	}
private:
	int _lastWalkingAssetIndex;
	int _lastDyingAssetIndex;
	int _lastIdleAssetIndex;
	int _lastAttackAssetIndex;
	String^ _heroName = gcnew String("");

	Bitmap^ loadBitmap(String^ bitmapName) {
	Reflection::Assembly^ assembly = Reflection::Assembly::GetExecutingAssembly();
	ResourceManager^ resman = gcnew ResourceManager("OOPZerebkovs.Pictures", assembly);
	return (Bitmap^)resman->GetObject(bitmapName);
	}
};