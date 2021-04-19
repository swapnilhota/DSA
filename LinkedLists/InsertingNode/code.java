public class code {

	class Node {
		int data;
		Node next;

		Node(int val) {
			data=val;
			next=null;
		}
	}

	public void push(Node head, int newData) {
		Node newNode = new Node(newData);
		newNode.next=head;
		head=newNode;
	}

	public void insertAfter(Node prevNode, int newData) {
		if(prevNode==null) {
			return;
		}

		Node newNode = new Node(newData);
		newNode.next = prevNode.next;
		prevNode.next = newNode;
	}

	public void append(Node head, int newData) {
		Node newNode = new Node(newData);

		if(head==null) {
			head = newNode;
			return;
		}

		Node last = head;
		while(last.next!=null) {
			last=last.next;
		}
		last.next=newNode;
		return;
	}

	public void printList(Node head) {
		Node temp = head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
	}

	public static void main(String[] args) {
		
		Node head = null;

		push(head, 1);
		push(head, 2);
		push(head, 3);
		push(head, 4);
		push(head, 5);

		printList(head);

	}
}