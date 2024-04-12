#include "sources.hpp"

Time::Time() : hour(0), minute(0), second(0) {}

Time::Time(int hour, int minute, int second)
{
	if (hour < 0 || minute < 0 || second < 0) {
		throw TimeException("Time_error: Time cannot be negative", hour, minute, second);
	}
	else if (hour > 23) {
		throw TimeException("Time_error: The number of hours in a day cannot be more than 24", hour, minute, second);
	}
	else if (minute > 59) {
		throw TimeException("Time_error: The number of minutes cannot be more than 59", hour, minute, second);
	}
	else if (second > 59) {
		throw TimeException("Time_error: The number of seconds cannot be more than 59", hour, minute, second);
	}
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

void Time::print() const noexcept
{
	std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
}

TimeException::TimeException(const char* message, int hour, int minute, int second) : std::out_of_range(message), hour(hour), minute(minute), second(second) {}

void TimeException::printException() const noexcept
{
	std::cerr << what() << std::endl;
	std::cerr << "Time: " << hour << ":" << minute << ":" << second << std::endl;
}
