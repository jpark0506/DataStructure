#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
//algorithm 헤더는 sort 함수를 내장하고 있음
using namespace std;
//recursion형 DFS
void DFS(int start, vector<int> graph[], bool visited[]) {
	visited[start] = true;
	cout << start;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == false) {
			DFS(next, graph, visited);
		}
	}
}
void DFS(int start, vector<int> graph[], bool visited[]) {
	stack<int> s;
	s.push(start);
	visited[start] = true;
	cout << start;
	while (!s.empty()) {
		int curr_node = s.top;
		s.pop();

	}

}
int main() {
	int vertex, edge, start;
	cin >> vertex >> edge>> start;

	bool* visited = new bool[vertex+1]{};
	vector<int>* graph = new vector<int>[vertex+1];

	for (int i = 0; i < edge; i++) {
		int a,b;
		cin >> a>> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i < vertex+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(start, graph, visited);

}