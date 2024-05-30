#include <Novice.h>
#include <Functions.h>
#include <imgui.h>

const char kWindowTitle[] = "LE2B_06_カタジマ_ロウノシン_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	//移動
	Vector3 translate{};
	//回転
	Vector3 rotate{};
	//カメラポジション
	Vector3 cameraPosition{ 0.0f,0.0f,-61.49f };
	Vector3 cameraRotate{ 0.0f,0.0f,0.0f };

	Plane plane;
	plane.distance = 0.0f;
	plane.nomal = { 0,5,0 };

	Segment segment{};
	segment.origin = { 0,0,0 };
	segment.diff = { 0,5,0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_A]) {
			cameraPosition.x -= 2;

		}
		if (keys[DIK_D]) {
			cameraPosition.x += 2;

		}
		if (keys[DIK_W]) {
			cameraPosition.y += 2;

		}
		if (keys[DIK_S]) {
			cameraPosition.y -= 2;

		}
		if (keys[DIK_UP]) {
			cameraPosition.z += 2;

		}
		if (keys[DIK_DOWN]) {
			cameraPosition.z -= 2;

		}

		Matrix4x4 worldMatrix = MakeAffineMatrixMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);

		Matrix4x4 cameraMatrix = MakeAffineMatrixMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraPosition);

		Matrix4x4 viewMatrix = Inverse(cameraMatrix);

		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(1280) / float(720), 0.1f, 100.0f);

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));

		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(1280), float(720), 0.0f, 1.0f);




		///
		/// ↑更新処理ここまで
		///
		


		///
		/// ↓描画処理ここから
		///



		DrawGrid(worldViewProjectionMatrix, viewportMatrix);


		DrawPlane(plane, worldViewProjectionMatrix, viewportMatrix, WHITE);


		if (IsCollision(segment, plane)) {
			DrawLine(segment, worldViewProjectionMatrix, viewportMatrix, RED);
		}
		else {
			DrawLine(segment, worldViewProjectionMatrix, viewportMatrix, WHITE);
		}


		ImGui::Begin("Win");
		ImGui::DragFloat3("CameraTranslate", &cameraPosition.x, 0.1f);
		ImGui::DragFloat3("cameraRotate", &cameraRotate.x, 0.1f);
		ImGui::DragFloat3("segment.origin", &segment.origin.x, 0.1f);
		ImGui::DragFloat3("segment.diff", &segment.diff.x, 0.1f);
		ImGui::DragFloat3("plane", &plane.nomal.x, 0.1f);
		plane.nomal = Nomalize(plane.nomal);
		ImGui::DragFloat("plane.distance", &plane.distance, 0.1f);
		ImGui::End();



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
