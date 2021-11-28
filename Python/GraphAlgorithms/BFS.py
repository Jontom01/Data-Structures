class Node:
    #Basic node class with exception that is sourcePointer
    #sourcePointer explained further down in the code
    def __init__(self, data, next=None, sourcePointer=None):
        self.data = data
        self.next = next
        self.color = None
    def getData(self):
        return self.data
    def clone(self):
        clone = Node(self.data)
        clone.color = self.color
        return clone
    def sourcePointer(self, node):
        self.sourcePointer = node
        
class ALGraph:
    def __init__(self):
        self.table = []

    def insertVertex(self, data):
        temp = Node(data) 
        self.table.append(temp)
    def search(self, target):
        counter = 0
        for i in self.table: 
            if i.data == target:
                return counter
            counter += 1
    def find(self, target):
        vertexIndex = self.search(target)
        return self.table[vertexIndex]

    #flag values specifies whether the edge of a vertex is going to be directed or undirected
    def adjacentTo(self, vertex, neighbor, flag):
        tableIndex = self.search(vertex)
        neighborNode = Node(neighbor)
        #flag = 0 means undirected. Every node in an undirected adjacency list that isnt the head has a second pointer, sourcePointer, that points to
        #the nodes counterpart that is a head of a linked list at a different index
        if flag == 0:
            neighborNode.sourcePointer(self.find(neighbor))
        curr = self.table[tableIndex]
        while curr.next:
            curr = curr.next
        curr.next = neighborNode

    def pointUndirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor, 0)
        self.adjacentTo(neighbor, vertex, 0)
        
    def pointDirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor, 1)
    
    def printGraph(self):
        for node in self.table:
            curr = node
            while curr:
                print(curr.data, end="->")
                curr = curr.next
            print()

#Breadth First Search graph implementation
class BFS:
    def __init__(self, ALGraph):
        self.graph = ALGraph
    
    def BFS(self, vertex):
        #creates queue and the BFSTree
        queue = []
        BFSTree = ALGraph()
        #adds the source vertex to the queue and BFSTree. Becomes BFSTree root
        queue.append(vertex)
        BFSTree.insertVertex(vertex)
        while queue: 
            #parent vertex is the head of the queue
            parent = self.graph.find(queue[0]) 
            #parent vertex color is grey
            parent.color = 0
            #next node in adjacency list address for parent. One of the vertices that is adjacent to parent
            node = parent.next
            #remove parent from queue
            queue.pop(0)
            #runs through all the vertexes that are adjacent to the parent vertex
            while node:
                #checks if the sourcePointer of the current vertex is white
                if node.sourcePointer.color == None:
                    #add every adjacent vertex to the queue and make it adjacent to parent in the BFSTree
                    queue.append(node.data)
                    BFSTree.insertVertex(node.data)
                    BFSTree.pointDirected(parent.data, node.data)
                    #change the color of the vertex's sourcePointer vertex to grey
                    node.sourcePointer.color = 0
                node = node.next
            #change color of the parent vertex to Black. The parent vertex is always a head of a list, therefore a sourcePointer to other vertices
            parent.color = 1
        return BFSTree

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
InitializeBFS = BFS(test)
BFSTree = InitializeBFS.BFS('A')
BFSTree.printGraph()
