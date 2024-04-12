#pragma once
#include <iostream>

class Time
{
private:
	int hour;
	int minute;
	int second;

public:
	Time();

	Time(int, int, int);

	void print() const noexcept;
};

class TimeException : public std::out_of_range 
{
private:
	int hour;
	int minute;
	int second;

public:
	TimeException(const char*, int, int, int);

	void printException() const noexcept;
};