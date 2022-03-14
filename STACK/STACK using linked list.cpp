#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
class Stack {
public:
	Node* head;
	Node* tail;
	int size;
	Stack() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	bool empty() {
		return size == 0;
	}
	void push(int data) {
		Node* temp = new Node(data);
		if (empty()) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	int pop() {
		Node* temp = head;

		if (empty()) {
			return -1;
		}

		if (size == 1) {
			int d = temp->data;
			head = NULL;
			tail = NULL;
			delete temp;
			size--;
			return d;

		}

		while (!(temp->next == tail)) {
			temp = temp->next;
		}
		Node* del = temp->next;
		int d2 = del->data;
		tail = temp;
		delete del;
		size--;
		return d2;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return tail->data;
	}
};

int main() {
	int n;
	cin >> n;
	Stack s;
	for (int i = 0; i < n; i++) {
		string c;
		cin >> c;
		if (c == "push") {
			int a;
			cin >> a;
			s.push(a);
		}
		else if (c == "top") {
			cout << s.top() << "\n";
		}
		else if (c == "size") {
			cout << s.size << "\n";
		}
		else if (c == "empty") {
			if (s.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (c == "pop") {
			cout << s.pop() << "\n";
		}
	}
}