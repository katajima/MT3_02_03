#include<Functions.h>

#include<imgui.h>

float K;

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;


	return result;
};

Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;


	return result;
};

float Dot(const Vector3& v1, const Vector3& v2) {
	float result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;


	return result;
};

float Length(const Vector3& v) {
	float result;

	result = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return result;
};
float Length(const float& v) {
	float result;

	result = sqrtf((v * v));

	return result;
};

float Clanp(float t) {

	if (1.0f <= t) {
		t = 1.0f;
	}
	if (0.0f >= t) {
		t = 0.0f;
	}

	return t;
}

Vector3 Nomalize(const Vector3& v) {
	Vector3 result{};
	float length;

	length = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	if (length != 0.0f) {
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	};

	return result;
};
//行列の積
Matrix4x4 Multiply(const Matrix4x4& v1, const Matrix4x4& v2) {
	Matrix4x4 result{};

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			for (int z = 0; z < 4; z++) {
				result.m[y][x] += v1.m[y][z] * v2.m[z][x];
			}
		}
	}

	return result;
};
// Vector3同士
Vector3 Multiply(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = v1.x* v2.x;
	result.y = v1.y* v2.y;
	result.z = v1.z* v2.z;

	return result;
}
// floatとVector3
Vector3 Multiply(const float& v , const Vector3& v1) {
	Vector3 result{};

	result.x = v1.x* v;
	result.y = v1.y* v;
	result.z = v1.z* v;

	return result;
}

//移動行列
Matrix4x4 MakeTranslateMatrix(const  Vector3& translate) {
	Matrix4x4 result{};

	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;
	result.m[2][3] = 0;

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1;

	return result;
}
//拡大縮小行列
Matrix4x4 MakeScaleMatrix(const  Vector3& scale) {
	Matrix4x4 result{};

	result.m[0][0] = scale.x;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = scale.z;
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}
//回転行列X
Matrix4x4 MakeRotateXMatrix(float rotate) {
	Matrix4x4 result{};

	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = std::cos(rotate);
	result.m[1][2] = std::sin(rotate);
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = -std::sin(rotate);
	result.m[2][2] = std::cos(rotate);
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;


	return result;
}
//回転行列Y
Matrix4x4 MakeRotateYMatrix(float rotate) {
	Matrix4x4 result{};

	result.m[0][0] = std::cos(rotate);
	result.m[0][1] = 0;
	result.m[0][2] = -std::sin(rotate);;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = std::sin(rotate);
	result.m[2][1] = 0;
	result.m[2][2] = std::cos(rotate);
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;


	return result;
}
//回転行列Z
Matrix4x4 MakeRotateZMatrix(float rotate) {
	Matrix4x4 result{};

	result.m[0][0] = std::cos(rotate);
	result.m[0][1] = std::sin(rotate);
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = -std::sin(rotate);
	result.m[1][1] = std::cos(rotate);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;


	return result;
}
//逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 result{};
	float result2;

	result2 =
		1 / ((m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3])
			+ (m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1])
			+ (m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2])

			- (m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1])
			- (m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3])
			- (m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2])

			- (m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3])
			- (m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1])
			- (m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2])

			+ (m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1])
			+ (m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3])
			+ (m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2])

			+ (m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3])
			+ (m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1])
			+ (m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2])

			- (m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1])
			- (m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3])
			- (m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2])

			- (m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0])
			- (m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0])
			- (m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0])


			+ (m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0])
			+ (m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0])
			+ (m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0]));


	//一行目一列目
	result.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3]) + (m.m[1][2] * m.m[2][3] * m.m[3][1]) + (m.m[1][3] * m.m[2][1] * m.m[3][2])
		- (m.m[1][3] * m.m[2][2] * m.m[3][1]) - (m.m[1][2] * m.m[2][1] * m.m[3][3]) - (m.m[1][1] * m.m[2][3] * m.m[3][2]);
	//一行目二列目
	result.m[0][1] = -(m.m[0][1] * m.m[2][2] * m.m[3][3]) - (m.m[0][2] * m.m[2][3] * m.m[3][1]) - (m.m[0][3] * m.m[2][1] * m.m[3][2])
		+ (m.m[0][3] * m.m[2][2] * m.m[3][1]) + (m.m[0][2] * m.m[2][1] * m.m[3][3]) + (m.m[0][1] * m.m[2][3] * m.m[3][2]);
	//一行目三列目
	result.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3]) + (m.m[0][2] * m.m[1][3] * m.m[3][1]) + (m.m[0][3] * m.m[1][1] * m.m[3][2])
		- (m.m[0][3] * m.m[1][2] * m.m[3][1]) - (m.m[0][2] * m.m[1][1] * m.m[3][3]) - (m.m[0][1] * m.m[1][3] * m.m[3][2]);
	//一行目四列目
	result.m[0][3] = -(m.m[0][1] * m.m[1][2] * m.m[2][3]) - (m.m[0][2] * m.m[1][3] * m.m[2][1]) - (m.m[0][3] * m.m[1][1] * m.m[2][2])
		+ (m.m[0][3] * m.m[1][2] * m.m[2][1]) + (m.m[0][2] * m.m[1][1] * m.m[2][3]) + (m.m[0][1] * m.m[1][3] * m.m[2][2]);


	//二行目一列目
	result.m[1][0] = -(m.m[1][0] * m.m[2][2] * m.m[3][3]) - (m.m[1][2] * m.m[2][3] * m.m[3][0]) - (m.m[1][3] * m.m[2][0] * m.m[3][2])
		+ (m.m[1][3] * m.m[2][2] * m.m[3][0]) + (m.m[1][2] * m.m[2][0] * m.m[3][3]) + (m.m[1][0] * m.m[2][3] * m.m[3][2]);
	//二行目二列目
	result.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3]) + (m.m[0][2] * m.m[2][3] * m.m[3][0]) + (m.m[0][3] * m.m[2][0] * m.m[3][2])
		- (m.m[0][3] * m.m[2][2] * m.m[3][0]) - (m.m[0][2] * m.m[2][0] * m.m[3][3]) - (m.m[0][0] * m.m[2][3] * m.m[3][2]);
	//二行目三列目
	result.m[1][2] = -(m.m[0][0] * m.m[1][2] * m.m[3][3]) - (m.m[0][2] * m.m[1][3] * m.m[3][0]) - (m.m[0][3] * m.m[1][0] * m.m[3][2])
		+ (m.m[0][3] * m.m[1][2] * m.m[3][0]) + (m.m[0][2] * m.m[1][0] * m.m[3][3]) + (m.m[0][0] * m.m[1][3] * m.m[3][2]);

	//二行目四列目
	result.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3]) + (m.m[0][2] * m.m[1][3] * m.m[2][0]) + (m.m[0][3] * m.m[1][0] * m.m[2][2])
		- (m.m[0][3] * m.m[1][2] * m.m[2][0]) - (m.m[0][2] * m.m[1][0] * m.m[2][3]) - (m.m[0][0] * m.m[1][3] * m.m[2][2]);


	//三行目一列目
	result.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3]) + (m.m[1][1] * m.m[2][3] * m.m[3][0]) + (m.m[1][3] * m.m[2][0] * m.m[3][1])
		- (m.m[1][3] * m.m[2][1] * m.m[3][0]) - (m.m[1][1] * m.m[2][0] * m.m[3][3]) - (m.m[1][0] * m.m[2][3] * m.m[3][1]);
	//三行目二列目
	result.m[2][1] = -(m.m[0][0] * m.m[2][1] * m.m[3][3]) - (m.m[0][1] * m.m[2][3] * m.m[3][0]) - (m.m[0][3] * m.m[2][0] * m.m[3][1])
		+ (m.m[0][3] * m.m[2][1] * m.m[3][0]) + (m.m[0][1] * m.m[2][0] * m.m[3][3]) + (m.m[0][0] * m.m[2][3] * m.m[3][1]);
	//三行目三列目
	result.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3]) + (m.m[0][1] * m.m[1][3] * m.m[3][0]) + (m.m[0][3] * m.m[1][0] * m.m[3][1])
		- (m.m[0][3] * m.m[1][1] * m.m[3][0]) - (m.m[0][1] * m.m[1][0] * m.m[3][3]) - (m.m[0][0] * m.m[1][3] * m.m[3][1]);
	//三行目四列目
	result.m[2][3] = -(m.m[0][0] * m.m[1][1] * m.m[2][3]) - (m.m[0][1] * m.m[1][3] * m.m[2][0]) - (m.m[0][3] * m.m[1][0] * m.m[2][1])
		+ (m.m[0][3] * m.m[1][1] * m.m[2][0]) + (m.m[0][1] * m.m[1][0] * m.m[2][3]) + (m.m[0][0] * m.m[1][3] * m.m[2][1]);


	//四行目一列目
	result.m[3][0] = -(m.m[1][0] * m.m[2][1] * m.m[3][2]) - (m.m[1][1] * m.m[2][2] * m.m[3][0]) - (m.m[1][2] * m.m[2][0] * m.m[3][1])
		+ (m.m[1][2] * m.m[2][1] * m.m[3][0]) + (m.m[1][1] * m.m[2][0] * m.m[3][2]) + (m.m[1][0] * m.m[2][2] * m.m[3][1]);
	//四行目二列目
	result.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2]) + (m.m[0][1] * m.m[2][2] * m.m[3][0]) + (m.m[0][2] * m.m[2][0] * m.m[3][1])
		- (m.m[0][2] * m.m[2][1] * m.m[3][0]) - (m.m[0][1] * m.m[2][0] * m.m[3][2]) - (m.m[0][0] * m.m[2][2] * m.m[3][1]);
	//四行目三列目
	result.m[3][2] = -(m.m[0][0] * m.m[1][1] * m.m[3][2]) - (m.m[0][1] * m.m[1][2] * m.m[3][0]) - (m.m[0][2] * m.m[1][0] * m.m[3][1])
		+ (m.m[0][2] * m.m[1][1] * m.m[3][0]) + (m.m[0][1] * m.m[1][0] * m.m[3][2]) + (m.m[0][0] * m.m[1][2] * m.m[3][1]);
	//四行目四列目
	result.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2]) + (m.m[0][1] * m.m[1][2] * m.m[2][0]) + (m.m[0][2] * m.m[1][0] * m.m[2][1])
		- (m.m[0][2] * m.m[1][1] * m.m[2][0]) - (m.m[0][1] * m.m[1][0] * m.m[2][2]) - (m.m[0][0] * m.m[1][2] * m.m[2][1]);

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {

			result.m[y][x] = result.m[y][x] * result2;

		}
	}


	return result;
}
//転置行列
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 result{};


	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			result.m[y][x] = m.m[x][y];
		}
	}
	return result;
}
//単位行列
Matrix4x4 Identity() {
	Matrix4x4 result{};


	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (x == y) {
				result.m[y][x] = 1.0f;
			}
			else {
				result.m[y][x] = 0.0f;
			}
		}
	}
	return result;
}
//アフィン変換
Matrix4x4 MakeAffineMatrixMatrix(const  Vector3& scale, const  Vector3& rotate, const  Vector3& translate) {
	Matrix4x4 result{};

	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));


	result.m[0][0] = scale.x * rotateXYZMatrix.m[0][0];
	result.m[0][1] = scale.x * rotateXYZMatrix.m[0][1];
	result.m[0][2] = scale.x * rotateXYZMatrix.m[0][2];
	result.m[0][3] = 0;
	result.m[1][0] = scale.y * rotateXYZMatrix.m[1][0];
	result.m[1][1] = scale.y * rotateXYZMatrix.m[1][1];
	result.m[1][2] = scale.y * rotateXYZMatrix.m[1][2];
	result.m[1][3] = 0;
	result.m[2][0] = scale.z * rotateXYZMatrix.m[2][0];
	result.m[2][1] = scale.z * rotateXYZMatrix.m[2][1];
	result.m[2][2] = scale.z * rotateXYZMatrix.m[2][2];
	result.m[2][3] = 0;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1;



	return result;
};
//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 result{};

	result.m[0][0] = 2 / (right - left);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 2 / (top - bottom);
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1 / (farClip - nearClip);
	result.m[2][3] = 0;

	result.m[3][0] = (left + right) / (left - right);
	result.m[3][1] = (top + bottom) / (bottom - top);
	result.m[3][2] = nearClip / (nearClip - farClip);
	result.m[3][3] = 1;





	return result;
}
//透視射影行列
Matrix4x4 MakePerspectiveFovMatrix(float forY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 result{};

	result.m[0][0] = (1 / aspectRatio) * 1 / std::tan(forY / 2);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 1 / std::tan(forY / 2);
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);
	result.m[3][3] = 0;

	return result;
}
//ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float leht, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 result{};

	result.m[0][0] = width / 2;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = (-height) / 2;
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = maxDepth - minDepth;
	result.m[2][3] = 0;

	result.m[3][0] = leht + (width / 2);
	result.m[3][1] = top + (height / 2);
	result.m[3][2] = minDepth;
	result.m[3][3] = 1;

	return result;
};
//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result{};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];

	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
};

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 1, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {

			Novice::ScreenPrintf(x + column * kColumnWidth, 20 + y + row * kRowHeight, "%6.02f", matrix.m[row][column]);

		}
	}

}

//線
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;									   // Gridの半分の幅
	const uint32_t kSubdivision = 10;									   // 分割数
	//const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);// 1つ分の長さ
	// 奥から手前への線を順々に引いていく
	Vector3 kLocalGridXS;
	Vector3 kLocalGridXE;
	Vector3 screenGridXS;
	Vector3 screenGridXE;

	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		//上の情報を使ってワールド座標系上の始点と終点を求めて
		kLocalGridXS.x =  (xIndex - kSubdivision/2.0f) * (kGridHalfWidth * 2.0f);
		kLocalGridXE.x =  (xIndex - kSubdivision/2.0f) * (kGridHalfWidth * 2.0f);

		kLocalGridXS.y = 0;//xIndex* (kGridHalfWidth * 2.0f);
		kLocalGridXE.y = 0;// xIndex* (kGridHalfWidth * 2.0f);

		kLocalGridXS.z = -(kSubdivision / 2.0f) * (kGridHalfWidth * 2.0f);//xIndex * (kGridHalfWidth * 2.0f);
		kLocalGridXE.z = (-(kSubdivision / 2.0f) * (kGridHalfWidth * 2.0f))  +(kGridHalfWidth * 2.0f) * (kSubdivision); //* (kSubdivision - 1);; // xIndex * (kGridHalfWidth * 2.0f);

		//スクリーン座標系まで変換をかける
		Vector3 ndcGridXS = Transform(kLocalGridXS, viewProjectionMatrix);
		Vector3 ndcGridXE = Transform(kLocalGridXE, viewProjectionMatrix);

		screenGridXS = Transform(ndcGridXS, viewportMatrix);
		screenGridXE= Transform(ndcGridXE, viewportMatrix);
		//変換した座標を使って表示。色は薄い灰色(0xAAAAAAFF)、原点は黒ぐらいがいいが、何でもいい
		if (xIndex == kSubdivision/2) {
			Novice::DrawLine(int(screenGridXS.x), int(screenGridXS.y), int(screenGridXE.x), int(screenGridXE.y), 0x000000FF);
		}
		else {
			Novice::DrawLine(int(screenGridXS.x), int(screenGridXS.y), int(screenGridXE.x), int(screenGridXE.y), 0xAAAAAAFF);
		}
	}

	//左から右も同じように順々に引いていく
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		//奥から手前が左右に変わるだけ
	
	//上の情報を使ってワールド座標系上の始点と終点を求めて
		kLocalGridXS.x = -(kSubdivision / 2.0f) * (kGridHalfWidth * 2.0f); //zIndex* (kGridHalfWidth * 2.0f);
		kLocalGridXE.x = (-(kSubdivision / 2.0f) * (kGridHalfWidth * 2.0f)) + (kGridHalfWidth * 2.0f) *(kSubdivision);// +kGridEvery * kSubdivision; //zIndex * (kGridHalfWidth * 2.0f);

		kLocalGridXS.y = 0;//xIndex* (kGridHalfWidth * 2.0f);
		kLocalGridXE.y = 0;// xIndex* (kGridHalfWidth * 2.0f);

		kLocalGridXS.z = (zIndex - kSubdivision/2.0f) * (kGridHalfWidth * 2.0f);
		kLocalGridXE.z = (zIndex - kSubdivision/2.0f) * (kGridHalfWidth * 2.0f);

		//スクリーン座標系まで変換をかける
		Vector3 ndcGridXS = Transform(kLocalGridXS, viewProjectionMatrix);
		Vector3 ndcGridXE = Transform(kLocalGridXE, viewProjectionMatrix);

		screenGridXS = Transform(ndcGridXS, viewportMatrix);
		screenGridXE = Transform(ndcGridXE, viewportMatrix);
		//変換した座標を使って表示。色は薄い灰色(0xAAAAAAFF)、原点は黒ぐらいがいいが、何でもいい
		if (zIndex == kSubdivision / 2) {
			Novice::DrawLine(int(screenGridXS.x), int(screenGridXS.y), int(screenGridXE.x), int(screenGridXE.y), 0x000000FF);
		}
		else {
			Novice::DrawLine(int(screenGridXS.x), int(screenGridXS.y), int(screenGridXE.x), int(screenGridXE.y), 0xAAAAAAFF);
		}
	}


}
//円
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	float pi = 3.14f;
	const uint32_t kSubdivision = 16; //分割数
	const float kLonEvery = pi * 2 /float(kSubdivision);      //経度分割1つ分の角度
	const float kLatEvery = pi * 2 / float(kSubdivision);      //緯度分割1つ分の角度



	Vector3 screenGridA;
	Vector3 screenGridB;
	Vector3 screenGridC;
	
	//　緯度の方向に分割　-π/2 ～ π/2
	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
		float lat = -pi / 2.0f + kLatEvery * latIndex;// 現在の緯度
		//　経度の方向に分割　0 ～ 2π
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;// 現在の経度
			//world座標系でのa,b,cを求める
			//Matrix4x4 worldMatrix = 
			Vector3 a, b, c;
			a = { sphere.radius * std::cos(lat) * std::cos(lon)                                 ,sphere.radius * std::sin(lat)                             ,sphere.radius * std::cos(lat) * std::sin(lon) };
			b = { sphere.radius * std::cos(lat + (pi / float(kSubdivision))) * std::cos(lon)    ,sphere.radius * std::sin(lat + (pi / float(kSubdivision))),sphere.radius * std::cos(lat + (pi / float(kSubdivision))) * std::sin(lon) };
			c = { sphere.radius * std::cos(lat) * std::cos(lon + (2 * pi / float(kSubdivision))),sphere.radius * std::sin(lat)                             ,sphere.radius * std::cos(lat) * std::sin(lon + (2 * pi / float(kSubdivision)))};
			a = { a.x + sphere.center.x,a.y + sphere.center.y,a.z + sphere.center.z };
			b = { b.x + sphere.center.x,b.y + sphere.center.y,b.z + sphere.center.z };
			c = { c.x + sphere.center.x,c.y + sphere.center.y,c.z + sphere.center.z };
			
			
			//a,b,cをScureen座標まで変換
			Vector3 ndcGridA = Transform(a, viewProjectionMatrix);
			Vector3 ndcGridB = Transform(b, viewProjectionMatrix);
			Vector3 ndcGridC = Transform(c, viewProjectionMatrix);

			screenGridA = Transform(ndcGridA, viewportMatrix);
			screenGridB = Transform(ndcGridB, viewportMatrix);
			screenGridC = Transform(ndcGridC, viewportMatrix);
			//ac,bcで線を引く
			
			Novice::DrawLine(int(screenGridA.x),int(screenGridA.y),int(screenGridB.x),int(screenGridB.y), color);
			Novice::DrawLine(int(screenGridA.x),int(screenGridA.y),int(screenGridC.x),int(screenGridC.y), color);
			
		}
	}
}
//平面
void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	
	//中心点
	Vector3 center = Multiply(plane.distance, plane.nomal);
	Vector3 perpendiculars[4];

	perpendiculars[0] = Nomalize(Perpendicular(plane.nomal));
	perpendiculars[1] = { -perpendiculars[0].x,-perpendiculars[0].y,-perpendiculars[0].z };
	perpendiculars[2] = Cross(plane.nomal, perpendiculars[0]);
	perpendiculars[3] = { -perpendiculars[2].x,-perpendiculars[2].y,-perpendiculars[2].z };


	//中心点にそれぞれ定数倍してたす
	Vector3 points[4];
	for (int32_t index = 0; index < 4; ++index) {
		Vector3 extend = Multiply(6.0f, perpendiculars[index]);
		Vector3 point = Add(center, extend);
		points[index] = Transform(Transform(point, viewProjectionMatrix), viewportMatrix);
	}

	Novice::DrawLine(int(points[0].x), int(points[0].y), int(points[2].x), int(points[2].y),color);
	Novice::DrawLine(int(points[1].x), int(points[1].y), int(points[3].x), int(points[3].y),RED);
	Novice::DrawLine(int(points[2].x), int(points[2].y), int(points[1].x), int(points[1].y),GREEN);
	Novice::DrawLine(int(points[3].x), int(points[3].y), int(points[0].x), int(points[0].y),BLACK);

}
//ライン
void DrawLine(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) 
{

	Vector3 origin = segment.origin;
	Vector3 diff = segment.diff;

	Vector3 ndcOri = Transform(origin, viewProjectionMatrix);
	Vector3 ndcDiff = Transform(diff, viewProjectionMatrix);

	Vector3 originScr = Transform(ndcOri ,viewportMatrix);
	Vector3 diffScr = Transform(ndcDiff, viewportMatrix);


	Novice::DrawLine(int(originScr.x), int(originScr.y), int(diffScr.x), int(diffScr.y), color);
	DrawSphere({ origin ,0.1f }, viewProjectionMatrix, viewportMatrix, RED);
	DrawSphere({ diff ,0.1f }, viewProjectionMatrix, viewportMatrix, BLUE);
};

Vector3 Project(const Vector3& v1, const Vector3& v2)
{
	Vector3 result{};
	float v2length = Dot(v2,v2);

	float dot = Dot(v1,v2);


	result.x = dot / v2length * v2.x;
	result.y = dot / v2length * v2.y;
	result.z = dot / v2length * v2.z;


	return result;
}


Vector3 ClosestPoint(const Vector3& point, const Segment& segment)
{
	Vector3 result{};
	Vector3 d = { 
		segment.diff.x - segment.origin.x,
		segment.diff.y - segment.origin.y,
		segment.diff.z - segment.origin.z };
	Vector3 v = {
		point.x - segment.origin.x,
		point.y - segment.origin.y,
		point.z - segment.origin.z};


	float dot = Dot(d, d);
	if (dot == 0.0f) {
		return segment.origin;
	}

	float t = Dot(v, d) / dot;

	t = Clanp(t);

	result.x = segment.origin.x + d.x * t;
	result.y = segment.origin.y + d.y * t;
	result.z = segment.origin.z + d.z * t;

	return result;
}
//衝突判定(球と球)
bool IsCollision(const Sphere& s1, const Sphere& s2)
{
	Vector3 result{};
	float isDistance = false;

	result.x = s2.center.x - s1.center.x;
	result.y = s2.center.y - s1.center.y;
	result.z = s2.center.z - s1.center.z;

	float distance = Length(result);

	if (distance <= s2.radius + s1.radius) {

		isDistance = true;

	}
	else {

		isDistance = false;

	}

	return isDistance;
}
//衝突判定(球と平面)
bool IsCollision(const Sphere& sphere, const Plane& plane)
{
	//フラグ
	//float isDistance = false;

	Vector3 dis = Nomalize(plane.nomal);

	float distance = Dot(sphere.center, dis) - plane.distance;
	//float d = plane.distance;

	//法線と平面上の任意の1点から求める
	//float d = Dot(sphere.center,plane.nomal) - plane.distance;

	//float k = Dot(plane.nomal, sphere.center) - d;

	//float kLength = Length(k);

	//K = kLength;

	//if (kLength <= sphere.radius) {
	//	isDistance = true;
	//}
	//else {
	//	isDistance = false;
	//}
	//return isDistance;

	
	return std::abs(distance) < sphere.radius;
}
//衝突判定(線と平面)
bool IsCollision(const Segment& segment, const Plane& plane)
{
	Vector3 diff = Subtract(segment.diff, segment.origin);
	
	
	//まず垂直判定を行うために、法線と線の内積を求める
	float dot = Dot(plane.nomal, diff);
	
	// 垂直=平行であるので、衝突しているはずがない
	if (dot == 0.0f) {
		return false;
	}

	float t = (plane.distance - Dot(segment.origin, plane.nomal)) / dot;
	

	//Vector3 v;
	// tの値と線の種類によって衝突しているかを判断する
	//v = Multiply(Add(segment.origin, { t,t,t }), segment.diff);

	ImGui::Begin("t");
	ImGui::DragFloat("t", &t);
	ImGui::End();

	
	if (t >= 0.0f && t<=1.0f) {
		return true;
	}
	return false;
}
//
Vector3 Perpendicular(const Vector3& vector) {
	if (vector.x != 0.0f || vector.y != 0.0f) {
		return { -vector.y,vector.x,0.0f };
	}
	return { 0.0f,-vector.z,vector.y };
}

//マウス
void Mouse(Vector3& cameraPosition)
{
	Vector3 came = cameraPosition;
	
	
	
	

	if(0 !=  Novice::IsTriggerMouse(0)){
		//int sx, sy ;
		//Novice::GetMousePosition(&sx, &sy);
	}
	if (Novice::IsTriggerMouse(0)) {
		//int x, y;
		//Novice::GetMousePosition(&x, &y);

		/*int px = sx - x;
		int py = sx - x;

		cameraPosition.x  = came.x + px;
		cameraPosition.x = came.y + py;*/
	}
	else if (Novice::IsTriggerMouse(1)) {
	}
	
}
