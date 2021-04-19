class LinkedList {


		Node head;

		class Node {

			int data;
			Node next;

			Node(int val) {
				data=val;
				next=null;
			}
		}

		public void push(int newData) {
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

		public void append(int newData) {
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

		public void printList() {
			Node temp = head;
			while(temp!=null) {
				System.out.print(temp.data+" ");
				temp=temp.next;
			}
		}	

	

	public static void main(String[] args) {
		
		LinkedList list = new LinkedList();

		list.append(1);
		list.append(2);
		list.append(3);
		list.append(4);
		list.append(5);


		list.printList();

	}
}