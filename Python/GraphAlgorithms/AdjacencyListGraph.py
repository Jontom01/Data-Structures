#Needs more comments
#Node class
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
    def getData(self):
        return self.data
#Adjanceny List graph implementation        
class ALGraph:
    #initialize list
    def __init__(self):
        self.table = []
    #add a vertex to the graph
    def insertVertex(self, data):
        temp = Node(data) 
        self.table.append(temp)
    #search the graph for a certain vertex, returns the List index of the target
    def search(self, target):
        counter = 0
        for i in self.table: 
            if i.data == target:
                return counter
            counter += 1
        return None
    #links
    def adjacentTo(self, vertex, neighbor):
        tableIndex = self.search(vertex)
        neighborNode = Node(neighbor)
        curr = self.table[tableIndex]
        while curr.next != None:
            curr = curr.next
        curr.next = neighborNode

    def pointUndirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor)
        self.adjacentTo(neighbor, vertex)
        
    def pointDirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor)
    
    def printGraph(self):
        for node in self.table:
            curr = node
            while(curr != None):
                print(curr.data, end="->")
                curr = curr.next
            print()

test = ALGraph()
test.insertVertex('A') 
test.insertVertex('B')
test.insertVertex('C')
test.insertVertex('D')
test.insertVertex('E')
test.pointUndirected('A', 'B')
test.pointUndirected('A', 'C')
test.pointUndirected('B', 'D')
test.pointUndirected('D', 'E')
test.pointUndirected('C', 'E')
test.pointUndirected('B', 'E')
test.printGraph()
