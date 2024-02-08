#include "RankingDispScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

RankingDispScene::RankingDispScene() :background_image(NULL), ranking(nullptr)
{

}

RankingDispScene::~RankingDispScene()
{

}

//初期化処理
void RankingDispScene::Initialize()
{
	//画像読み込み
	background_image = LoadGraph("Resource/image/Ranking.bmp");

	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/image/Ranking.bmpがありません\n");
	}

	//ランキング情報
	ranking = new RankingData;
	ranking->Initialize();
}

//更新処理
eSceneType RankingDispScene::Update()
{
	//Bボタンが押されたら、タイトルに戻る
	if (InputControl::GetButton(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}

	return GetNowScene();
}

//描画処理
void RankingDispScene::Draw() const
{
	//背景画像の描画
	DrawGraph(0, 0, background_image, FALSE);

	//取得したランキングデータを描画する
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-15s %6d", ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));
	}
}

//終了時処理
void RankingDispScene:: Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);

	//動的メモリの削除
	ranking->Finalize();
	delete ranking;
}

//現在のシーンを取得
eSceneType RankingDispScene::GetNowScene() const
{
	return eSceneType::E_RANKING_DISP;
}