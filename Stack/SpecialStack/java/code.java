import java.util.Stack;

class Stack {

	class SpecialStack {
		Stack<Integer> s;
		int min;

		SpecialStack() {
			s = new Stack<Integer>();
			min=-1;
		}

		void push(int x) {
			s.push(x);
			if(min==-1) {
				min=x;
			}
			else {
				if(min>x) {
					min=x;
				}
			}
		}

		void pop() {
			s.pop();
		}

		bool isEmpty() {
			return s.isEmpty();
		}

		int minVal() {
			return min;
		}

		int top() {
			return s.top();
		}
	}

	public static void main(String[] args) {

		SpecialStack s;

		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		System.out.println(s.min());
		System.out.println(s.top());
		
	}
}