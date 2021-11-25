#include <iostream>
#include"mystack.h"
#include <stack>
struct Node{
    int data;
    struct Node* child;
    struct Node* parent;
    Node(int data){
        this->data = data;
        child = NULL;
        parent = NULL;
    }
};

class DBLL{
private:

    Node* head = nullptr;

    Node* insertREC(Node* node, Node* parent, int x){
        if(node == NULL){
            node = new Node(x);
            node -> child = NULL;
            node -> parent = parent;
            return node;
        }
        else{
            node -> child = insertREC(node -> child, node, x);
            return node;
        }
    }

    void traversal(Node* node){
        if(node == NULL){
            return;
        }
        else{
            std::cout << "Current Node: " << node -> data << " ";
            if(node -> parent != NULL){
                std::cout << "Node Parent: " << node -> parent -> data << " ";
            }
            if(node -> child != NULL){
                std::cout << "Node Child: " << node -> child -> data << " ";
            }
            std::cout << std::endl;
            traversal(node -> child);
        }
    }

    Node *removeREC(Node* node, Node* nodeParent, int x){
        if(node == NULL){
            std::cout << "value not in list" << std::endl;
            return NULL;
        }
        else if(node -> data != x){
            node -> child = removeREC(node -> child, node, x);
            return node;
        }
        else{
            Node* tmp = node -> child;
            node -> child -> parent = nodeParent;
            delete node;
            return tmp;
        }
    }

public:
    DBLL(){ head = nullptr; }

    void insert(int x){ head = insertREC(head, NULL, x); }

    void print(){ traversal(head); }

    void remove(int x){ head = removeREC(head, NULL, x); }

    bool isEmpty(){
        return head == NULL;
    }

};

int main()
{
    DBLL test;
    test.insert(1);
    test.insert(2);
    test.insert(5);
    test.insert(6);
    test.remove(5);
    test.remove(18);
    test.print();
}
