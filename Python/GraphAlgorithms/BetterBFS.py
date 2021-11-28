class ALGraph:
    def __init__(self):
        self.hashTable = {}

    def insertVertex(self, data):
        self.hashTable[data] = [None]
    def search(self, target):
        if target in self.hashTable:
            return target
        else:
            raise Exception("vertex not in graph")

    def adjacentTo(self, vertex, neighbor):
        key = self.search(vertex)
        self.hashTable[key].append(neighbor)
        
    def pointUndirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor)
        self.adjacentTo(neighbor, vertex)
        
    def pointDirected(self, vertex, neighbor):
        self.adjacentTo(vertex, neighbor)
    
    def printGraph(self):
        for key in self.hashTable:
            print(key, " ", self.hashTable[key])
        print()

class BFS:
    def __init__(self, ALGraph):
        self.graph = ALGraph
    
    def BFS(self, vertex):
        queue = []
        BFSTree = ALGraph()
        queue.append(vertex)
        BFSTree.insertVertex(vertex)
        while queue: 
            parent = self.graph.search(queue[0])
            self.graph.hashTable[parent][0] = 0
            queue.pop(0)
            for i in range(1, len(self.graph.hashTable[parent])):
                if self.graph.hashTable[self.graph.search(self.graph.hashTable[parent][i])][0] == None:
                    queue.append(self.graph.hashTable[parent][i])
                    BFSTree.insertVertex(self.graph.hashTable[parent][i])
                    BFSTree.pointDirected(parent, self.graph.hashTable[parent][i])
                    self.graph.hashTable[self.graph.search(self.graph.hashTable[parent][i])][0] = 0
            self.graph.hashTable[parent][0] = 1
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
