#include <iostream>
//revise algorithms
class Stack{
//stack created using a linked list, where the top of the stack is the end of the list
//and the bottom of the stack is the front of the list
private:
    int popValue;
    struct Node {
        int data;
        struct Node *child;
        Node(int data)
        {
            this->data = data;
            child = NULL;
        }
    };
    //Initial node of the new stack
    Node* bottom = NULL;

    /*
    insertREC recurs throughout the linked list until it finds a NULL node AKA the child of the last node of the list.
    Once it reaches this position, it creates a new Node with value x.
    */
    Node* insertREC(Node* node, int x){
        if(node != NULL){
            node -> child = insertREC(node -> child, x);
            return node;
        }
        else{
            node = new Node(x);
        }
    }
    /*
    popREC recurs throughout the linked list until it finds the node at the very end of the list
    After, the node at the end of the list is set to NULL
    */
    Node* popREC(Node* node){
        if(node->child != NULL){
            node -> child = popREC(node -> child);
        }
        else{
            //NodeData(node -> data);
            //Node* tmp = node;
            popValue = node -> data;
            node = NULL;
            delete node;
            return node;
        }
    }
    /*
    recurs through the list printing the value of every node in the list
    */
    void traversal(Node* node){
        if(node == NULL){
            return;
        }
        else{
            std::cout << node -> data << " ";
            traversal(node -> child);
        }
    }
public:
    //calls the insertREC method
    void push(int x){
        bottom = insertREC(bottom, x);
    }
    //calls the traversal method
    void print(){
        traversal(bottom);
        std::cout << std::endl;
    }
    //calls the popREC method
    int pop(){
        bottom = popREC(bottom);
        return popValue;
    }
    //returns 1 or 0 whether the stack is empty or not. The stack is empty if the bottom node is NULL
    bool isEmpty(){
        return bottom == NULL;
    }
};
int main()
{
  Stack test;
  test.push(1);
  test.push(5);
  test.push(6);
  test.pop();
  test.print();
  return 0;
}
