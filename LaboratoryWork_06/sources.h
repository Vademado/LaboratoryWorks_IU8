#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Student {
	std::string full_name;
	unsigned short int study_group;
	unsigned int credit_card_number;
	std::vector<unsigned short int> grades;
	//std::vector<unsigned char> grades[4]; спросить!!!
};

void fileManager(const std::string mode, const std::string representation, const std::string fileName);