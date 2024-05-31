#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>


class Graph {
private:
	std::vector<std::vector<int>> graph;
	size_t size;
	bool oriented;

	std::vector<bool> visited;
	std::vector<int> distances;
	size_t start;

public:
	Graph();
	Graph(std::vector<std::vector<int>>);
	Graph(size_t, bool, std::vector<std::vector<int>>);
	Graph(const Graph&);
	Graph(Graph&&);

	void set_size(size_t);
	void set_oriented(bool);
	void set_graph(std::vector<std::vector<int>>);
	void set(size_t, bool, std::vector<std::vector<int>>);

	size_t get_size();
	bool get_oriented();
	std::vector<std::vector<int>> get_graph();

	bool is_valid();
	void add_vertex();
	void delete_vertex(size_t);
	void add_edge(size_t, size_t, int);
	void delete_edge(size_t, size_t);

	void dijkstra();
	void prepare_dijkstra(size_t);
	int get_min_distance(size_t, size_t);

	friend void read_data(Graph&, std::string);
	friend std::ostream& operator << (std::ostream&, const Graph&);
	friend std::istream& operator >> (std::istream&, Graph&);
};

std::vector<int> split(const std::string&);

void read_data(Graph&, std::string);

template <typename T>
std::ostream& operator << (std::ostream&, const std::vector<T>);

std::ostream& operator << (std::ostream&, const Graph&);

std::istream& operator >> (std::istream&, Graph&);
