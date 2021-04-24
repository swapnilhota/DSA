#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
private:
	stack<int> s;
	stack<int> s_min;

public:
	push(int x) {
		s.push(x);
		if(s_min.Empty()) {
			s_min.push(x);
		}
		else {
			if(s_min.top()>x) {
				s_min.push(x);
			}
		}
	}
}

int main() {

	SpecialStack spl_stack;

	push(spl_stack, 1);
	push(spl_stack, 2);
	push(spl_stack, 3);
	push(spl_stack, 4);

	return 0;
}