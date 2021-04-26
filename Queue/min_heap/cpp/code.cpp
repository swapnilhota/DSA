#include <bits/stdc++.h>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int> > gquiz) {
	priority_queue<int, vector<int>, greater<int> > g = gquiz;
	while(!g.empty()) {
		cout << "\t" << g.top();
		g.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int, vector<int>, greater<int> > gquiz;

	gquiz.push(1);
	gquiz.push(2);
	gquiz.push(3);
	gquiz.push(4);

	cout << "The priority queue gquiz is : ";
    showpq(gquiz);
  
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
  
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz); 

	return 0;
}