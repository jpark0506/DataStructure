#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int> s;
	int cnt = 1;
	vector<char> str;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (flag) {
			if (cnt <= input) {
				while (cnt < input) {
					s.push(cnt);
					str.push_back('+');
					cnt++;
				}
				s.push(cnt);
				str.push_back('+');
				cnt++;
				s.pop();
				str.push_back('-');

			}
			else if (cnt > input) {
				if (s.top() == input) {
					s.pop();
					str.push_back('-');
				}
				else {
					str.clear();
					flag = false;
				}
			}
		}
	}
	//endl 때문에 시간 초과 발생
	//C++에서는 endl 쓰지 말것
	if (flag) {
		for (int i = 0; i < str.size(); i++) {
			cout << str[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}
	
	return 0;
}