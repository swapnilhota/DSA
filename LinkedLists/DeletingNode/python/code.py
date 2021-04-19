class Node:

	def __init__(self, data):

		self.next=None
		self.data=data

class LinkedList:

	def __init__(self):
		self.head=None

	def push(self, newData):
		newNode = Node(newData)
		newNode.next = self.head
		self.head = newNode