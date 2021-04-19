class Node:

#function to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:

	def __init__(self):
		self.head=None


	def push(self, newData):
		newNode = Node(newData)
		newNode.next=self.head
		self.head=newNode

	def insertAfter(self, prevNode, newData):
		if prevNode is None:
			return

		newNode = Node(newData)
		newNode.next=prevNode.next
		prevNode.next=newNode

	def append(self, newData):
		newNode = Node(newData)

		if self.head is None:
			self.head=newNode
			return

		last = self.head

		while(last.next):
			last=last.next

		last.next=newNode

	def printList(self):
		temp=self.head
		while(temp):
			print(temp.data, end=" ")
			temp=temp.next


if __name__ =='__main__':

		llist = LinkedList()

		llist.append(1)
		llist.append(2)
		llist.append(3)
		llist.append(4)
		llist.append(5)
		llist.push(2)

		llist.printList()

