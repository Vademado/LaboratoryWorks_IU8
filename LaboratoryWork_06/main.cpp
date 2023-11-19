#include "sources.h"

std::string mode, representation, fileName;


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");

	//mode = argv[1];
	//representation = argv[2];
	//fileName = argv[3];

	fileManager("-r", "bi", "teta.txt");

	return 0;
}
