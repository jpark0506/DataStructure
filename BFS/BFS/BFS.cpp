#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void BFS(int start, vector<int> graph[],bool visited[]) {
	
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp;
		for (int i = 0; i < graph[tmp].size(); i++) {
			if (visited[graph[tmp][i]]==false) {
				q.push(graph[tmp][i]);
				visited[graph[tmp][i]]=true;
			}
		}
	}

	
}
int main() {
	int vertex, edge, start;
	cin >> vertex >> edge >> start;
	bool* visited = new bool[vertex]{false};
	vector<int>* graph = new vector<int>[vertex+1];
	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	BFS(start,graph,visited);
}