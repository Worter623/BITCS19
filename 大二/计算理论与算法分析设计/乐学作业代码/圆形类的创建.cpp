#include <iostream>
#include <string>
#include <iomanip>
#define pi 3.14
using namespace std;

class Circle
{
public:
	float CalculateArea();
	float CalculateCircumference();
	void Initialize(float, float, float);
private:
	float x, y, r;
};

float Circle::CalculateArea()
{
	float ans = pi * r * r;
	return ans;
}

float Circle::CalculateCircumference()
{
	float ans = 2 * pi * r;
	return ans;
}

void Circle::Initialize(float x1, float y1, float r1)
{
	x = x1; y = y1; r = r1;
}

int main()
{
	float x, y, r;
	cin >> x >> y >> r;
	Circle c;
	c.Initialize(x, y, r);
	cout.setf(ios::fixed);
	cout << fixed << setprecision(4)<< c.CalculateArea()<<endl;
	cout << fixed << setprecision(4) << c.CalculateCircumference() << endl;
}

