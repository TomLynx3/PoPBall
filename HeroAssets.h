#pragma once


ref class HeroAssets {


public: HeroAssets(int lastAssetIndex, String^ heroName) {
		_heroName = heroName;
		_lastAssetIndex = lastAssetIndex;
	}

public:List<Bitmap^>^ getAssetsByState(CreatureState state) {
		List<Bitmap^> ^ assets = gcnew List<Bitmap^>();
		String^ preffix = _getPreffix(state);
		
		for (int i = 0; i < _lastAssetIndex; i++) {
			String^ assetName = _heroName + preffix + i.ToString();
			assets->Add(loadBitmap(assetName));
		}

		return assets;
	}

public: int getLastImageIndex() {
	return _lastAssetIndex;
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
	int _lastAssetIndex;
	String^ _heroName = gcnew String("");

	Bitmap^ loadBitmap(String^ bitmapName) {
	Reflection::Assembly^ assembly = Reflection::Assembly::GetExecutingAssembly();
	ResourceManager^ resman = gcnew ResourceManager("OOPZerebkovs.Pictures", assembly);
	return (Bitmap^)resman->GetObject(bitmapName);
	}
};