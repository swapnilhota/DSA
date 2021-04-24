#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
private:
	stack<int> s;
	stack<int> s_min;

public:
	void push(int x) {
		s.push(x);
		if(s_min.empty()) {
			s_min.push(x);
		}
		else {
			if(s_min.top()>x) {
				s_min.push(x);
			}
		}
	}

	int top() {
		if(s.empty()) {
			exit(0);
		}
		return s.top();
	}

	void pop() {
		if(s.empty()) {
			exit(0);
		}
		s.pop();
	}

	bool isEmpty() {
		if(s.empty()) {
			return true;
		}
		return false;
	}

	int min() {
		if(s_min.empty()) {
			return -1;
		}
		else {
			return s_min.top();
		}
	}
};

int main() {

	SpecialStack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << s.min() << endl;
	cout << s.top() << endl;

	return 0;
}