/*

Given an directed graph, check if there exists a back-edge or not.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<vector>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// add a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

	void dfsHelper(T s, unordered_set<T>& visited, vector<T>& out) {

		// 1. mark s as visited

		visited.insert(s);

		// 2. recursively visit unvisited neighbours of s

		list<T> neighbourList = neighbourMap[s];
		for (T neighbour : neighbourList) {
			if (visited.find(neighbour) == visited.end()) {
				// neighbour is not yet visited
				dfsHelper(neighbour, visited, out);
			}
		}

		out.push_back(s);

	}

	void topologicalSort() {

		unordered_map<T, int> inDegMap; // to store the mapping b/w the
		// vertices and their in-degrees

		// populate the inDegMap

		for (pair<T, list<T>> vertex : neighbourMap) {
			list<T> neighbourList = vertex.second;
			for (T neighbour : neighbourList) {
				// account for directed edge from 'vertex' to 'neighbour'
				inDegMap[neighbour]++;
			}
		}

		unordered_set<T> visited;
		vector<T> out;

		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			if (inDegMap.find(vertexLabel) == inDegMap.end()) {
				// vertex with 'vertexLabel' has no dependency (i.e. 0 inDegree)
				dfsHelper(vertexLabel, visited, out);
			}
		}

		reverse(out.begin(), out.end());

		for (int i = 0; i < out.size(); i++) {
			cout << out[i] << " ";
		}

		cout << endl;

	}

};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('D', 'C');
	g.addEdge('D', 'E');
	g.addEdge('D', 'F');
	g.addEdge('D', 'G');
	g.addEdge('D', 'H');
	g.addEdge('E', 'G');
	g.addEdge('F', 'C');
	g.addEdge('G', 'H');
	g.addEdge('H', 'F');

	g.topologicalSort();

	return 0;
}