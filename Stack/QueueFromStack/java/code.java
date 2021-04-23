import java.util.Stack;

class Code {

	static class Queue {
		Stack<Integer> s1;
		Stack<Integer> s2;

		Queue() {
			s1 = new Stack<Integer>();
			s2 = new Stack<Integer>();
		}
	}

	static void enQueue(Queue q, int x) {
		q.s1.push(x);
	}

	static int deQueue(Queue q) {
		int x;

		if(q.s1.isEmpty() && q.s2.isEmpty()) {
			System.out.println("Q is Empty");
			System.exit(0);
		}

		if(q.s2.isEmpty()) {
			while(!q.s1.isEmpty()) {
				q.s2.push(q.s1.pop());
			}
		}

		return q.s2.pop();
	}

	public static void main(String[] args) {

		Queue q = new Queue();

		enQueue(q, 1);
		enQueue(q, 2);
		enQueue(q, 3);

		for(int i=0; i<3; i++) {
			System.out.println(deQueue(q));
		}
		
	}
}