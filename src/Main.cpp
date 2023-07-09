# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include"Game.h"

void Main()
{
	//ウィンドウを初期化
	Scene::Resize(fr::ScnSize.x, fr::ScnSize.y);
	Scene::SetBackground(ColorF{ 0.5f,0.8f,0.9f });
	//Gameインスタンス生成
	fr::Game* game = new fr::Game();
	//更新頻度を60fpsに固定
	const int FPS = 60;
	Stopwatch sw;
	sw.start();
	//メインループ
	while (System::Update()) {
		game->update();

		while (sw.msF() < 1000.0f / FPS);
		sw.restart();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
