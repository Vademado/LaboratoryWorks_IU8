#include "sources.hpp"

int main()
{
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	Vector vector1, vector2;
	inputFile >> vector1;  // ������ ������� ���� Vector �� ������ �����
	outputFile << vector1; // ����� ������� ���� Vector � ����� ������

	inputFile >> vector2;  // ������ ������� ���� Vector �� ������ �����
	outputFile << vector2; // ����� ������� ���� Vector � ����� ������

	Vector vector = vector1 + vector2; // ������������� �������� ��������
	outputFile << vector;

	vector2 = vector1;					// ����������� �����������
	Vector vector3(std::move(vector1)); // ����������� �����������

	vector2[0] = 10; // ��������� � �������� ������� �� �������

	vector3 = vector2; // �������� ������������ � ������������
	Vector vector4;
	vector4 = std::move(vector3); // �������� ������������ � ������������

	outputFile << vector2; // ������� ������� � ����� ������
	outputFile << vector4; // ������� ������� � ����� ������

	inputFile.close();
	outputFile.close();

	return 0;
}