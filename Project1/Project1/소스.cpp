#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vector2 {
public:
	float x;
	float y;

	Vector2(float _x, float _y) : x(_x), y(_y) {
	};
	~Vector2() {
	};

	Vector2 operator*(const float& _p) {
		return Vector2(x * _p, y * _p);
	}
	Vector2 operator+(const Vector2& v) {
		return Vector2(x + v.x, y + v.y);
	}
};

Vector2 GetBezier(float t, vector<Vector2>* _vec) {
	if (_vec->size() == 1) {
		return (*_vec)[0];
	}
	
	vector<Vector2>* tmp = new vector<Vector2>;

	for (auto iter = _vec->begin(); iter != _vec->end() - 1; iter++) {
		tmp->push_back(iter->operator*(1 - t) + (iter + 1)->operator*(t));
	}

	return GetBezier(t, tmp);
}

int main() {
	vector<Vector2>* vec = new vector<Vector2>;

	int dot_count = 0;

	cout << "How many dots" << endl;

	cin >> dot_count;

	cout << "Input x, y" << endl;

	for (int a = 0; a < dot_count; a++) {
		float x, y;

		cin >> x;
		cin >> y;

		vec->push_back(Vector2(x, y));
	}

	for (float a = 0; a < 1; a += 0.01f) {
		Vector2 v = GetBezier(a, vec);
		cout << "(" << v.x << ", " << v.y << ")" << endl;
	}
}

//https://www.desmos.com/calculator