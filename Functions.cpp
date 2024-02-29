#include <iostream>
using namespace std;

float Area_triangle(float vector1[2], float vector2[2], float vector3[2]);

int main()
{
	float vertexA[2] = {}; //each vector represents the x, y coordinates of the vertices of a triangle
	float vertexB[2] = {};
	float vertexC[2] = {};

	cout << "Enter the x coordinate of vertex A ";
	cin >> vertexA[0];

	cout << "Enter the y coordinate of vertex A ";
	cin >> vertexA[1];

	cout << "Enter the x coordinate of vertex B ";
	cin >> vertexB[0];

	cout << "Enter the y coordinate of vertex B ";
	cin >> vertexB[1];

	cout << "Enter the x coordinate of vertex C ";
	cin >> vertexC[0];

	cout << "Enter the y coordinate of vertex C ";
	cin >> vertexC[1];

	cout << "Area is: " << Area_triangle(vertexA, vertexB, vertexC) << endl;

	return 0;
}

float Area_triangle(float vector1[2], float vector2[2], float vector3[2])
{
	float normvector1[2] = {};
	float normvector2[2] = {};

	normvector1[0] = vector2[0] - vector1[0];
	normvector1[1] = vector2[1] - vector1[1];
	normvector2[0] = vector3[0] - vector1[0];
	normvector2[1] = vector3[1] - vector1[1];

	float determinate = 0;

	determinate = normvector1[0] * normvector2[1] - normvector2[0] * normvector1[1];

	float area = 0;
	if (determinate > 0)
		area = determinate / 2;
	else area = -determinate / 2;

	return area;

}
