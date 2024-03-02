#include "sources.hpp"

int main()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    Vector vector1, vector2;
    std::cin >> vector1;  // ������ ������� ���� Vector �� ������ �����
    std::cout << vector1; // ����� ������� ���� Vector � ����� ������

    std::cin >> vector2;  // ������ ������� ���� Vector �� ������ �����
    std::cout << vector2; // ����� ������� ���� Vector � ����� ������

    Vector vector = vector1 + vector2; // ������������� �������� ��������
    std::cout << vector;

    vector2 = vector1;                  // ����������� �����������
    Vector vector3(std::move(vector1)); // ����������� �����������

    vector2[0] = 10; // ��������� � �������� ������� �� �������

    vector3 = vector2; // �������� ������������ � ������������
    Vector vector4;
    vector4 = std::move(vector3); // �������� ������������ � ������������

    outputFile << vector2 << std::endl; // ������� ������� � ����� ������
    outputFile << vector4 << std::endl; // ������� ������� � ����� ������

    inputFile.close();
    outputFile.close();

    return 0;
}