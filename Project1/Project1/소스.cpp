#pragma warning(disable:4996)
#include <iostream>
#include <Windows.h>

using namespace std;
class MyVector {
private:
	float x;
	float y;
public:
	MyVector() : x(0), y(0) {};
	MyVector(int x, int y) : x(x), y(y) {};
	~MyVector() {};

	float GetX() {
		return x;
	}
	
	float GetY() {
		return y;
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

	MyVector A(-5, -3), B(-2, 3), C(5, 3);

	for (t; t <= 1; t += 0.01) {
		MyVector P;

		P = A * ((1 - t) * (1 - t)) + B * t * (1 - t) * 2 + C * ((1 - t)*(1 - t));

		printf("%f, %f\n", P.GetX(), P.GetY());
	}
}