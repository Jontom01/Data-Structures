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
