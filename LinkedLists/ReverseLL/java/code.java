class LinkedList {

	Node head;

	class Node {
		Node next;
		int data;
		Node(int val) {
			next=null;
			data=val;
		}
	}

	void push(int newData) {
		Node newNode = new Node(newData);
		if(head==null) {
			head=newNode;
			return;
		}
		newNode.next=head;
		head=newNode;
		return;
	}

	void printList() {
		if(head==null) {
			return;
		}
		Node temp=head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
		System.out.println("");
	}

	void reverse() {
		Node prev=null;
		Node next=null;
		Node curr=head;

		while(curr!=null) {
			next=curr.next;
			curr.next=prev;
			prev=curr;
			curr=next;
		}

		head=prev;
	}

	public static void main(String[] args) {

		LinkedList llist = new LinkedList();

		Node head=null;

		llist.push(1);
		llist.push(2);
		llist.push(3);
		llist.push(4);

		llist.printList();

		llist.reverse();

		llist.printList();
	}
}