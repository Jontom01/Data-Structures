#Node class
class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

    def getNext(self):
        return self.next

    def setNext(self, node):
        self.next = node

    def getData(self):
        return self.data

    def setData(self, data):
        self.data = data

#Linked List Implementation
class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            curr = self.head
            while curr.next:
                curr = curr.getNext()
            curr.setNext(Node(data))

    def print(self):
        curr = self.head
        while curr != None:
            print(curr.getData())
            curr = curr.getNext()
  
#main method
test = LinkedList()
test.insert(6)
test.insert(4)
test.print()
