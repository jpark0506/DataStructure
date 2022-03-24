#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n,k;
	cin >> n >> k;
	queue<int> circle;
	for (int i = 0; i < n; i++) {
		circle.push(i + 1);
	}
	cout << "<";
	while (!circle.empty()) {
		for (int i = 0; i < k-1; i++) {
			int temp = circle.front();
			circle.pop();
			circle.push(temp);
		}
		if (circle.size() != 1) {
			cout << circle.front() << ", ";
		}
		else {
			cout << circle.front();
		}
		circle.pop();
		
	}
	cout << ">";
}