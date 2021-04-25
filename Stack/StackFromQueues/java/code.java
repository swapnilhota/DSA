import java.util.*;

class Stack {

	Queue<Integer> q1 = new LinkedList<Integer>();
	Queue<Integer> q2 = new LinkedList<Integer>();

	int curr_size;

	Stack() {
		curr_size=0;
	}

	void push(int x) {
		curr_size++;
		q2.add(x);

		while(!q1.isEmpty()) {
			q2.add(q1.peek());
			q1.remove();
		}

		Queue<Integer> q = q1;
		q1 = q2;
		q2 = q;
	}

	int top() {
		if(q1.isEmpty()) {
			return -1;
		}
		return q1.peek();
	}

	void pop() {
		if(q1.isEmpty()) {
			return;
		}
		q1.remove();
		curr_size--;
	}

	int size() {
		return curr_size;
	}

	public static void main(String[] args) {
		Stack s = new Stack();
        s.push(1);
        s.push(2);
        s.push(3);
  
        System.out.println("current size: " + s.size());
        System.out.println(s.top());
        s.pop();
        System.out.println(s.top());
        s.pop();
        System.out.println(s.top());
  
        System.out.println("current size: " + s.size());
	}
}