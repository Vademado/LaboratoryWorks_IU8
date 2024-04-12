#include "sources.hpp"

int main() {

	try {
		//Time time_negativ(12, -34, 65);
		//Time time_incorrect_number_hours(26, 12, 34);
		//Time time_incorrect_number_minutes(23, 67, 34);
		//Time time_incorrect_number_seconds(14, 12, 78);
		Time time_corr(8, 36, 0);
		time_corr.print();
		Time time_incorrect(26, -12, 94);
		time_incorrect.print();
	}
	catch (const TimeException& ex) {
		ex.printException();
	}


	return 0;
}