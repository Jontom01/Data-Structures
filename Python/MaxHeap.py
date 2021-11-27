#This heap works for integer arrays only
class MaxHeap:
    def __init__(self, arr):
        self.arr = []
        self.arr.append(len(arr))
        for data in arr:
            self.arr.append(data)
        self._createMaxHeap()

    def _createMaxHeap(self):
        start = int(self.arr[0] / 2)
        while(start > 0):
            self._swap(start)
            start -= 1


    def _swap(self, current):
        while True:
            greaterChild = self._greaterChild(current)
            if(greaterChild == -1):
                break
            if self.arr[greaterChild] > self.arr[current]:
                tmp = self.arr[greaterChild]
                self.arr[greaterChild] = self.arr[current]
                self.arr[current] = tmp
                current = greaterChild
            else:
                break

    def _greaterChild(self, objIndex):
        objLeftChild = int(objIndex * 2)
        objRightChild = objLeftChild + 1
        if objLeftChild < len(self.arr) and objRightChild < len(self.arr):
            greaterChild = max(self.arr[objLeftChild], self.arr[objRightChild])
            if greaterChild == self.arr[objLeftChild]:
                return objLeftChild
            else:
                return objRightChild

        elif objLeftChild > len(self.arr) and objRightChild > len(self.arr):
            return -1

        elif objLeftChild > len(self.arr):
            return objRightChild

        else:
            return objLeftChild
    
    def insert(self, obj):
        self.arr[0] += 1
        self.arr.append(obj)
        self._createMaxHeap()
    
    def remove(self):
        self.arr[0] -= 1
        out = self.arr[1]
        self.arr.pop(1)
        self._createMaxHeap()
        return out

    def print(self):
        print(self.arr)

x = [2,3,34,4,5,6,7,3]
test = MaxHeap(x)
test.insert(5)
test.print()
print(test.remove())
