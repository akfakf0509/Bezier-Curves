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

	void operator=(const MyVector& vec) {
		this->x = vec.x;
		this->y = vec.y;
	}

	MyVector operator*(const MyVector& vec) {
		MyVector tmp(this->x * vec.x, this->y * vec.y);
		
		return tmp;
	}

	MyVector operator*(const float target) {
		MyVector tmp(this->x * target, this->y * target);

		return tmp;
	}

	MyVector operator+(const MyVector& vec) {
		MyVector tmp(this->x + vec.x, this->y + vec.y);

		return tmp;
	}

	MyVector operator+(const float target) {
		MyVector tmp(this->x + target, this->y + target);

		return tmp;
	}
};
int main() {
	float t = 0;

	MyVector A(-5, -3), B(-2, 3), C(5, 3);

	while (t < 1) {
		MyVector E(), F();

		E = (A * (1 - t)) + (B * t);

	}
}