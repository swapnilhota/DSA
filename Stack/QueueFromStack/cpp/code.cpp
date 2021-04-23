#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
	stack<int> s1;
	stack<int> s2;

	void enQueue(int x) {
		s1.push(x);
	}

	int deQueue() {
		if(s1.empty() && s2.empty()) {
			cout << "Queue is empty" << endl;
			exit(0);
		}

		if(s2.empty()) {
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		int x = s2.top();
		s2.pop();
		return x;
	}
}

int main() {

	return 0;
}