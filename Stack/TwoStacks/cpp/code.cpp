#include <bits/stdc++.h>
using namespace std;

class twoStacks {
		int* arr;
		int size;
		int top1, top2;

	public:
		twoStacks(int n) {
			size = n;
			arr = new int[n];
			top1 = -1;
			top2 = size;
		}

		void push1(int x) {
			if(top1<top2-1) {
				top1++;
				arr[top1]=x;
			} else {
				cout << "Stack Overflow" << endl;
				exit(1);
			}
		}

		void push2(int x) {
			if(top2>top1+1) {
				top2--;
				arr[top2]=x;
			} else {
				cout << "Stack Overflow" << endl;
				exit(1);
			}
		}

		int pop1() {
			if(top1>=0) {
				int x = arr[top1];
				top1--;
				return x;
			} else {
				cout << "Stack Underflow" << endl;
				exit(1);
			}
		}

		int pop2() {
			if(top2<size) {
				int x = arr[top2];
				top2++;
				return x;
			} else {
				cout << "Stack Underflow" << endl;
				exit(1);
			}
		}
	};

int main() {

	twoStacks ts(5);
	ts.push1(1);
	ts.push1(2);
	ts.push2(3);
	ts.push2(4);
	ts.push2(5);

	//ts.push1(6);

	cout << ts.pop1() << endl;
	cout << ts.pop2() << endl;

	return 0;
}