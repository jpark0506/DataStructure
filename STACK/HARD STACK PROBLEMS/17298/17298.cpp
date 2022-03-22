#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int> s;
	stack<int> tmp;
	vector<int> output;
	//역순 정렬
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		s.push(input);
	}
	tmp.push(-1);
	while (!s.empty()) {
		while (s.top() >= tmp.top()) {
			if (tmp.top() == -1) {
				break;
			}
			tmp.pop();
		}
		output.push_back(tmp.top());
		tmp.push(s.top());
		s.pop();
	}
	
	for (int i = output.size()-1; i>=0; i--) {
		cout << output[i] << " ";
	}

}