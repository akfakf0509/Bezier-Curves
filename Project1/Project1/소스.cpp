#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
class MyVector {
private:
	float x;
	float y;
public:
	MyVector() : x(0), y(0) {};
	MyVector(float x, float y) : x(x), y(y) {};
	~MyVector() {};

	float GetX() {
		return x;
	}

	void SetX(float _x) {
		this->x = _x;
	}
	
	float GetY() {
		return y;
	}

	void SetY(float _y) {
		this->y = _y;
	}

	MyVector operator*(const MyVector& vec) {
		MyVector tmp(this->x * vec.x, this->y * vec.y);
		
		return tmp;
	}

	MyVector operator*(const float& target) {
		MyVector tmp(this->x * target, this->y * target);

		return tmp;
	}

	MyVector operator+(const MyVector& vec) {
		MyVector tmp(this->x + vec.x, this->y + vec.y);

		return tmp;
	}

	MyVector operator+(const float& target) {
		MyVector tmp(this->x + target, this->y + target);

		return tmp;
	}

	void operator=(const MyVector& vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	void operator=(const float& target) {
		this->x = target;
		this->y = target;
	}
};

int main() {
	float t = 0;

	MyVector vecs[3];

	cout << "3개의 점의 좌표를 입력" << endl;

	for (int a = 0; a < 3; a++) {
		float x = 0, y = 0;

		cin >> x;
		cin >> y;

		vecs[a].SetX(x);
		vecs[a].SetY(y);
	}

	for (t; t <= 1; t += 0.01) {
		MyVector E, F, G;

		E = vecs[0] * (1.0 - t) + vecs[1] * t;
		F = vecs[1] * (1.0 - t) + vecs[2] * t;

		G = E * (1.0 - t) + F * t;

		printf("(%f, %f)\n", G.GetX(), G.GetY());
	}
}

//https://www.desmos.com/calculator