class LinkedList {

	Node head;

	public class Node {
		Node next;
		int data;
		Node(int val) {
			next=null;
			data=val;
		}
	}

	public void push(int newData) {
		Node newNode = new Node(newData);
		if(head==null) {
			head=newNode;
			return;
		}
		newNode.next = head;
		head = newNode;
		return;
	}

	public void printList() {
		Node temp = head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
	}

	public void deleteNode(int key) {
		Node temp=head;
		Node prev=null;

		if(temp!=null && temp.data==key) {
			head=temp.next;
			return;
		}

		while(temp.data!=key) {
			prev=temp;
			temp=temp.next;
		}

		prev.next=temp.next;

	}

	public static void main(String[] args) {

		LinkedList list = new LinkedList();

		list.push(1);
		list.push(2);
		list.push(3);
		list.push(4);

		list.printList();

		list.deleteNode(2);

		list.printList();
		
	}

}