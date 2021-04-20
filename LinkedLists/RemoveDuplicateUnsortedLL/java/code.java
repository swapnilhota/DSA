import java.util.HashSet;

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

	void push(int new_data) {
		Node new_node = new Node(new_data);
		if(head==null) {
			head=new_node;
			return;
		}
		new_node.next=head;
		head=new_node;
		return;
	}

	void printList() {
		Node temp=head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
		System.out.println("");
	}

	void removeDuplicate() {
		HashSet<Integer> hs = new HashSet<>();

		Node curr = head;
		Node prev = null;

		while(curr!=null ){
			int currval = curr.data;

			if(hs.contains(currval)) {
				prev.next=curr.next;
			} else {
				hs.add(currval);
				prev=curr;
			}
			curr=curr.next;
		}
	}

	public static void main(String[] args) {

		LinkedList llist = new LinkedList();

		llist.push(1);
		llist.push(2);
		llist.push(4);
		llist.push(3);
		llist.push(1);
		llist.push(2);
		llist.push(3);

		llist.printList();

		llist.removeDuplicate();

		llist.printList();
		
	}
}