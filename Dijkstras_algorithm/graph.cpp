#include "graph.hpp"

Graph::Graph() {
	size = 0;
	oriented = false;
}

Graph::Graph(std::vector<std::vector<int>> graph) {
	this->graph = graph;
	size = graph.size();
	oriented = false;
}

Graph::Graph(size_t size, bool oriented, std::vector<std::vector<int>> graph) {
	this->size = size;
	this->oriented = oriented;
	this->graph = graph;
}

Graph::Graph(const Graph& oth) {
	size = oth.size;
	oriented = oth.oriented;
	graph = oth.graph;
}

Graph::Graph(Graph&& oth) {
	size = oth.size;
	oth.size = 0;
	oriented = oth.oriented;
	oth.oriented = false;
	graph = oth.graph;
	oth.graph.clear();
}

void Graph::set_size(size_t size) {
	this->size = size;
}

void Graph::set_oriented(bool oriented) {
	this->oriented = oriented;
}

void Graph::set_graph(std::vector<std::vector<int>> graph) {
	this->graph = graph;
}

void Graph::set(size_t size, bool oriented, std::vector<std::vector<int>> graph) {
	this->size = size;
	this->oriented = oriented;
	this->graph = graph;
}

size_t Graph::get_size() {
	return size;
}

bool Graph::get_oriented() {
	return oriented;
}

std::vector<std::vector<int>> Graph::get_graph() {
	return graph;
}

bool Graph::is_valid() {
	if (graph.size() != size)
		return false;
	if (!std::all_of(graph.begin(), graph.end(), [this](std::vector<int> line) {
		return size == line.size();
		}))
		return false;
	if (!oriented) {
		for (size_t i = 0; i < size; i++)
			for (size_t j = 0; j < size; j++) {
				if (graph[i][j] < 0)
					return false;
				if (graph[i][j] != graph[j][i])
					return false;
			}
	}
	return true;
}

void Graph::add_vertex() {
	size++;
	graph.push_back(std::vector<int>(size, 0));
	for (size_t i = 0; i < size - 1; i++)
		graph[i].resize(size);
}

void Graph::delete_vertex(size_t index) {
	for (size_t i = 0; i < size; i++)
		graph[i].erase(graph[i].begin() + index);
	graph.erase(graph.begin() + index);
	size--;
}

void Graph::add_edge(size_t start, size_t end, int weight = 1) {
	graph[start][end] = weight;
	if (!oriented)
		graph[end][start] = weight;
}

void Graph::delete_edge(size_t start, size_t end) {
	graph[start][end] = 0;
	if (!oriented)
		graph[end][start] = 0;
}

void Graph::dijkstra() {
	size_t vertex = start;
	int min_distance = 0;
	distances[start] = 0;
	while (min_distance < INT32_MAX) {
		size_t i = vertex;
		min_distance = INT32_MAX;
		visited[i] = true;
		for (size_t j = 0; j < size; j++) {
			if (graph[i][j] && !visited[j] && distances[j] > distances[i] + graph[i][j])
				distances[j] = distances[i] + graph[i][j];
			if (!visited[j] && distances[j] < min_distance) {
				min_distance = distances[j];
				vertex = j;
			}
		}
	}
}

void Graph::prepare_dijkstra(size_t start) {
	visited = std::vector<bool>(size, false);
	distances = std::vector<int>(size, INT32_MAX);
	this->start = start;
}

int Graph::get_min_distance(size_t start, size_t end) {
	prepare_dijkstra(start);
	dijkstra();
	return distances[end];
}

std::vector<int> split(const std::string& line) {
	std::vector<int> res;
	size_t index = 0;
	while (line.find(" ", index) != std::string::npos) {
		size_t new_index = line.find(" ", index);
		std::string word = line.substr(index, new_index - index);
		if (word.length())
			res.push_back(std::stoi(word));
		index = new_index + 1;
	}
	if (index < line.length())
		res.push_back(std::stoi(line.substr(index)));
	return res;
}

void read_data(Graph& obj, std::string file_name) {
	std::ifstream fin(file_name);
	if (!fin)
		throw std::invalid_argument("wrong file");
	std::string line;
	std::getline(fin, line);
	size_t size = std::stoi(line);
	std::getline(fin, line);
	bool oriented = std::stoi(line);
	std::vector<std::vector<int>> graph;
	while (!fin.eof()) {
		std::getline(fin, line);
		std::vector<int> arr = split(line);
		graph.push_back(arr);
	}
	fin.close();
	obj.set(size, oriented, graph);
	if (!obj.is_valid())
		throw std::overflow_error("wrong data");
}

std::ostream& operator<<(std::ostream& out, const Graph& graph) {
	for (size_t i = 0; i < graph.size; i++) {
		for (size_t j = 0; j < graph.size; j++)
			out << graph.graph[i][j] << " ";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Graph& graph) {
	size_t n = graph.size;
	graph.graph = std::vector<std::vector<int>>(n, std::vector<int>(n));
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			in >> graph.graph[i][j];
	return in;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> arr) {
	for (T item : arr)
		out << item << " ";
	return out;
}
