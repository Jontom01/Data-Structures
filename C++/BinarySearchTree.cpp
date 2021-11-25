#include <iostream>
#include <stdlib.h>

/**
Node structure implementation with left and right child pointers
**/
struct Node {
    int data;
    bool mark;
    struct Node *left, *right;
    Node(int data)
    {
        this->mark = false;
        this->data = data;
        left = right = NULL;
    }
};


class BST{
private:
     Node* root = NULL;
private:
    /**
    Attributes:
    @param root - the root node of the binary tree instance
    @param heightnnum -
    **/
    int heightnum = 0;
    /**
    Recursively searches for the node with data that equals target value x
    @param node
    @param x
    @return the target node
    **/
    Node* searchREC(Node* node, int x){
        if(node == NULL){
            return node;
        }
        else{
            if(node -> data == x){
                return node;
            }
            else if(node -> data < x){
                return searchREC(node -> right, x);
            }
            else{
                return searchREC(node -> left, x);
            }
        }
    }
    /**
    Recursively searches for an appropriate
    @param node
    @param x
    @return the node of every call that isnt the target spot
    **/
    Node * insertREC(Node * node, int x){
        if(node == NULL){
            node = new Node(x);
            node -> left = NULL;
            node -> right = NULL;
        }
        else if(x <= node -> data){
            node -> left = insertREC(node -> left, x);
        }
        else{
            node -> right = insertREC(node -> right, x);
        }
        return node;
    }
    /**
    Implementation of post-order traversal
    **/
    void postOrderRec(struct Node* node){
        if (node == NULL){
            return;
        }
        postOrderRec(node->right);
        std::cout << node->data << " ";
        postOrderRec(node->left);

    }

    /**
    Recursively calculates the height of the tree by finding the length of the longest stem
    @param node
    @param counter
    **/
    void heightREC(Node* node, int counter){
        if(node == NULL){
            return;
        }
        else{
            counter++;
            if(counter >= heightnum){
                heightnum = counter;
            }
            heightREC(node -> left, counter);
            heightREC(node -> right, counter);
        }
    }
    /**
    Recursively search for the target node to be deleted
    @param node
    @param x
    @return target node
    **/
    Node * removeREC(Node* node, int x){
        if(node == NULL){
            return node;
        }

        else if(node->data < x){
            node->right = removeREC(node->right, x);
            return node;
        }

        else if(node->data > x){
            node->left = removeREC(node->left, x);
            return node;
        }
        else{
            if(node->left == NULL){
                return node->right;
            }
            else if(node->right == NULL){
                return node->left;
            }
            else{
                Node* tmp = fixLeftSubTree(node);
                tmp->right = node->right;
                node -> left = NULL;
                node -> right = NULL;
                delete node;
                return tmp;
            }
        }
    }
    /**
    fixes the left subtree after removeREC is called
    @param node
    @return node
    **/
    Node* fixLeftSubTree(Node* node){
        Node* temp = node->left;
        if(temp->right == NULL){
            return temp;
        }
        else{
            Node* parent = NULL;
            Node* current = temp;
            while(current->right != NULL){
                parent = current;
                current = current->right;
            }
            parent->right = current->left;
            current->left = temp;
            return current;
        }
    }
    /**
    Calculates the amount of nodes in a tree
    @param node
    @return integer value number of nodes
    **/
    int lengthREC(Node* node){
        if(node == NULL){
            return 0;
        }
        else{
            return 1 + lengthREC(node -> left) + lengthREC(node -> right);
        }
    }

  

public:
   
    /**
    Constructor that sets root to NULL
    **/
    BST(){
        root = NULL;
    }
    /**
    Calls searchREC
    **/
    Node* search(int x){
        return searchREC(root, x);
    }
    /**
    Calls insertREC
    **/
    void insert(int x){
        root = insertREC(root, x);
    }
    /**
    Calls postOrderRec
    **/
    void print(){
        postOrderRec(root);
        std::cout << std::endl;
    }

    /**
    Calls lengthREC
    @return the length of the BST instance
    **/
    int length(){
        return lengthREC(root);
    }
    /**
    Calls heightREC
    @return height of the BST instance
    **/
    int height(){
        heightnum = 0;
        heightREC(root, 0);
        return heightnum;
    }
    /**
    calls removeREC
    **/
    void remove(int x){root = removeREC(root, x);}

};

int main()
{
    BST test;
    test.insert(4);
    test.insert(5);
    test.insert(6);
    test.insert(2);
    test.insert(1);
    test.insert(2);
    test.insert(8);
    test.insert(7);
    test.parent(1);
    return 0;
}
