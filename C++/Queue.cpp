#include <iostream>
using namespace std;

class Queue{
private:
    struct Node {
        int data;
        struct Node *child;
        Node(int data)
        {
            this->data = data;
            child = NULL;
        }
    };
    Node* head = NULL;

    Node* enqueueREC(Node* node, int x){
        if(node == NULL){
            node = new Node(x);
            return node;
        }
        else{
            node -> child = enqueueREC(node -> child, x);
            return node;
        }
    }

    Node* dequeueREC(Node* node){
        if(node == NULL){
            return node;
        }
        else{
            head = head -> child;
            return node;
        }
    }

    void traversal(Node* node){
        if(node == NULL){
            return;
        }
        else{
            cout << node -> data << " ";
            traversal(node -> child);
        }
    }
public:
    void enqueue(int x){
        head = enqueueREC(head, x);
    }
    int dequeue(){
        Node* tmp = dequeueREC(head);
        if(tmp != NULL){
            return tmp -> data;
        }
        else{
            cout << "queue is empty" << endl;
        }
    }
    void print(){
        traversal(head);
    }
    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    Queue test;
    test.dequeue();
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(4);
    test.enqueue(8);
    test.enqueue(11);
    test.print();
    return 0;
}
