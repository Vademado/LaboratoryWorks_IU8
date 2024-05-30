#include <iostream>
#include "graph.hpp"


int main() {
	std::string file_name = "data.txt";
	Graph graph;
	try {
		read_data(graph, file_name);
	}
	catch (...) {
		return 1;
	}
	std::cout << "Graph:\n" << graph << std::endl;


	return 0;
}
