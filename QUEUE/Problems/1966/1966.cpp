#include<iostream>
#include<queue>
using namespace std;
class document {
public:
	int num;
	int importance;
	document(int num, int importance) {
		this->num = num;
		this->importance = importance;
	}
};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		queue<document> q;
		int cap;
		int target;
		cin >> cap >> target;
		for (int j = 0; j < cap; j++) {
			int importance;
			cin >> importance;
			document d(j, importance);
			q.push(d);
		}
		int cnt = 0;
		while (true) {
			document t = q.front();
			int temp_num = t.num;
			int temp_imp = t.importance;
			int max_imp = temp_imp;
			q.pop();
			q.push(t);
			
			bool flag = false;
			//check max
			while (q.front().num != temp_num) {
				if (q.front().importance > max_imp) {
					max_imp = q.front().importance;
					flag = true;
				}
				document temp = q.front();
				q.pop();
				q.push(temp);
			}

			if (!flag) {
				cnt++;
				if (q.front().num == target) {
					break;
				}
				q.pop();
			}
			else {
				while (q.front().importance != max_imp) {
					document temp = q.front();
					q.pop();
					q.push(temp);
				}
				cnt++;
				if (q.front().num == target) {
					break;
				}
				q.pop();
			}
		}
		cout << cnt << '\n';
	}
}