#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Discipline
{
    std::string title;
    unsigned mark;
};

struct Student
{
    std::string full_name;
    unsigned group_number;
    std::vector<Discipline> disciplines;
};

void quickSort(Student* array, int left, int right);
void laba_4();
void laba_4_map();
