class Code {

	static class Queue {
		Stack<Integer> s1;
		Stack<Integer> s2;
	}

	static void enQueue(Queue q, int x) {
		q.s1.push(x);
	}

	static void deQueue(Queue q) {
		int x;

		if(q.s1.isEmpty() && q.s2.isEmpty()) {
			System.out.println("Q is Empty");
			return;
		}

		if(q.s2.isEmpty()) {
			while(!q.s1.isEmpty()) {
				q.s2.push(q.s1.pop());
			}
		}

		return q.s2.pop();
	}

	public static void main(String[] args) {
		
	}
}