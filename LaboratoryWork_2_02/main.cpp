#include "sources.hpp"

int main()
{
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	Vector vector1, vector2;
	inputFile >> vector1;  // Чтение объекта типа Vector из потока ввода
	outputFile << vector1; // Вывод объекта типа Vector в поток вывода

	inputFile >> vector2;  // Чтение объекта типа Vector из потока ввода
	outputFile << vector2; // Вывод объекта типа Vector в поток вывода

	Vector vector = vector1 + vector2; // Перегруженная операция сложения
	outputFile << vector;

	vector2 = vector1;					// Конструктор копирования
	Vector vector3(std::move(vector1)); // Конструктор перемещения

	vector2[0] = 10; // Обращение к элементу вектора по индексу

	vector3 = vector2; // Операция присваивания с копированием
	Vector vector4;
	vector4 = std::move(vector3); // Операция присваивания с перемещением

	outputFile << vector2; // Вставка объекта в поток вывода
	outputFile << vector4; // Вставка объекта в поток вывода

	inputFile.close();
	outputFile.close();

	return 0;
}