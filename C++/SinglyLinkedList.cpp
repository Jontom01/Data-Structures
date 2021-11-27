#include <iostream>
#include <stack>
//needs comments and revise algorithms
struct Node{
    int data;
    struct Node* child;
    Node(int data){
        this->data = data;
        child = NULL;
    }
};

class LinkedList{
private:
    Node *head = NULL;
private:
    Node *insertREC(Node *node, int x){
        if(node == NULL){
            node = new Node(x);
            return node;
        }
        else{
            node -> child = insertREC(node -> child, x);
            return node;
        }
    }

    void traversal(Node* node){
        if(node == NULL){
            return;
        }
        else{
            std::cout << node -> data << " ";
            traversal(node -> child);
        }
    }

    Node *removeREC(Node *node, int x){
        if(node == NULL){
            return node;
        }
        else if(node -> data == x){
            Node *tmp = node -> child;
            delete node;
            return tmp;
        }
        else{
            node -> child = removeREC(node -> child, x);
            return node;
        }
    }

    void reverseREC(Node *node){
        Node* current = node;
        std::stack<Node*> myStack;
        myStack.push(current);
        while(current -> child != NULL){
            current = current -> child;
            myStack.push(current);
        }
        head = current;
        while(!myStack.empty()){
            current = myStack.top();
            myStack.pop();
            current -> child = myStack.top();
        }
    }
public:
    void insert(int x){
        head = insertREC(head, x);
    }
    void print(){
        traversal(head);
        std::cout << std::endl;
    }
    void remove(int x){
        head = removeREC(head, x);
    }
    void reverse(){
        reverseREC(head);
    }
};

int main()
{
    LinkedList test;
    test.insert(5);
    test.insert(4);
    test.insert(3);
    test.remove(4);
    test.insert(7);
    test.remove(7);
    test.insert(8);
    test.print();
    test.reverse();
    test.print();
}
