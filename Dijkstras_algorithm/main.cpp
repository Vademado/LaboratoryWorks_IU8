#include <iostream>
#include "graph.hpp"


int main() {
	std::string file_name = "test3.txt";
	Graph graph;
	try {
		read_data(graph, file_name);
		std::cout << graph.get_min_distance(0, 6) << std::endl;
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << "Graph:\n" << graph << std::endl;


	return 0;
}
