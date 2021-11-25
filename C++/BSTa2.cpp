#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include"mystack.h"
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

/**
Author: Jonathan Thompson
SN: 20238895
Date: October 19th, 2021
**/
/**
Implementation of Binary Tree and the specified experiment
**/
class BST{
private:

    /**
    Attributes:
    @param root - the root node of the binary tree instance
    @param heightnnum -
    **/

    int heightnum = 0;
    Stack countStack;
    std::queue<Node*> Q;
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
    int ans = -1;
    int avgHeightREC(Node* node, int counter, int x){
        if(node != NULL){
            if(node->data == x){
                ans = counter;
            }
            counter++;
            avgHeightREC(node -> left, counter, x);
            avgHeightREC(node -> right, counter, x);
        }
        return ans;
    }
    void breadthFirstSearch(Node* node){
        std::queue<Node*> Q;
        Q.push(node);
        Node* curr = node;
        while(!Q.empty()){
            curr = Q.front();
            if(curr->left != NULL){ Q.push(curr->left); }
            if(curr->right != NULL){ Q.push(curr->right); }
            std::cout << Q.front() -> data << " ";
            Q.pop();
        }
    }
    /**
    fuck
    **/
    Node* findParent(Node* node, int key){
        std::stack<Node*> nodeStack;
        nodeStack.push(node);
        Node* current = node;
        while(true){
            current = nodeStack.top();
            if(current -> data == key){
                nodeStack.pop();
                std::cout << "Parent: " << nodeStack.top()->data << std::endl;
                return nodeStack.top();
            }
            if(key > current->data && current->right != NULL){
                nodeStack.push(current->right);
            }
            else if(key <= current->data && current->left != NULL){
                nodeStack.push(current->left);
            }
            else{ return NULL; }
        }
    }


public:
    Node* root = NULL;
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
/**
    int avgHeight(){
        int length = 0;
        int sum = 0;
        avgHeightREC(root, 0);
        while(!countStack.isEmpty()){
            sum += countStack.pop();
            length++;
        }
        return sum / length;
    }
**/
    int maxHeightofValue(int x){

        return avgHeightREC(root, 1, x);
    }
    int BFS(){
       breadthFirstSearch(root);
    }

    void parent(int key){
        root = findParent(root, key);
    }
};


/**
Implementation of the specified experiment
**/
class Experiment{
private:
    /**
    Attributes:
    @param highest
    @param lowest
    @param percentage
    **/
    int highest;
    int lowest;
    float percentage;
    /**
    Returns a random number between 0 and n - 1
    **/
    int randInt(int n){
        return rand() % n;
    }
    /**
    Creates a BST instance of length n and calculates the height
    @param n
    @param t
    @return height of the binary tree
    **/
    int createTree(int n, BST t){
        int s = n*1.5;
        int random;
        for(int i = 0; i < s; i++){
            t.insert(randInt(s));
        }
        while(t.length() > n){
            t.remove(randInt(s));
        }
        if(t.height() > highest){
            highest = t.height();
        }
        if(t.height() < lowest || lowest == 0){
            lowest = t.height();
        }
        if(t.height() > 2*log2(n)){
            percentage++;
        }
        return t.height();
    }

public:
    /**
    Implementation of the experiment
    @param n
    @return avg height
    **/

    float experiment(int n){
        BST t = BST();
        float height = 0;
        highest = 0;
        lowest = 0;
        for(int i = 0; i < 500; i++){
            height += createTree(n, t);
        }
        std::cout << "Highest: " << highest << " Lowest: " << lowest << " Average: " << height/500 << " Trees Over 2logn: " << (percentage/500)*100 << std::endl;
        return height/500;
    }
    /**
    Runs the experiment 10 times. Only works for n = 1000 and 2000. Anything higher would take too long
    @param n
    @returns the total avg between the 10 runs
    **/
    float groupExperiment(int n){
        float sum = 0;
        for(int i = 0; i < 10; i++){
            percentage = 0;
            sum += experiment(n);
        }
        return sum / 10;
    }
};
bool isRootMedian(BST t){
        std::stack<Node*> callStack;
        std::stack<Node*> outputStack;
        int counter = 0;
        Node* curr = t.root;
        while(!callStack.empty() || curr != nullptr){
            if(curr!=nullptr){
                counter++;
                callStack.push(curr);
                curr = curr -> right;
            }
            else{
                curr = callStack.top();
                outputStack.push(curr);
                callStack.pop();
                curr = curr -> left;
            }
        }
        if(counter % 2 != 0){
            for(int i = 1; !outputStack.empty(); i++){
                if(i == (counter/2 + 1)){
                    return t.root -> data == outputStack.top()->data;
                }
                outputStack.pop();
            }
        }
        else{
            for(int i = 1; !outputStack.empty(); i++){
                float sum = 0;
                if(i == counter/2){
                    sum += outputStack.top()->data;
                    outputStack.pop();
                    sum += outputStack.top()->data;
                    return sum / 2 == t.root -> data;
                }
                outputStack.pop();
            }
        }
    }
int main()
{
    /**
    test code
    ex. test.experiment(1000) will run the experiment for n = 1000
    ex2. test.groupExperiment(1000) will run the experiment for n = 1000, 10 times in a row
    **/
    Experiment test;
    //std::cout << test.avgHeight();
    BST test1;
    test1.insert(4);
    test1.insert(5);
    test1.insert(6);
    test1.insert(2);
    test1.insert(1);
    test1.insert(2);
    test1.insert(8);
    test1.insert(7);
    test1.parent(1);

    //test.experiment(4000);
    //test.experiment(8000);
    //test.experiment(16000);
    //test.groupExperiment(1000);
    return 0;
}
#if 0
    void postOrderIT(Node *node){
        Stack callStack;
        Node* current = node;
        callStack.push(current->data);
        if(current == NULL){ return; }
        while(true){
            if(current -> left != NULL){
                current = current -> left;
                callStack.push(current->data);
            }
            else{
                current = current -> right;
                if(current == NULL){ break; }
                callStack.push(current->data);
            }
        }
        current = node;
        while(true){
            if(current -> right != NULL){
                current = current -> right;
                callStack.push(current->data);
            }
            else{
                current = current -> left;
                if(current == NULL){ break; }
                callStack.push(current->data);
            }
        }
        while(callStack.isEmpty() != true){
            std::cout << callStack.pop() << std::endl;
        }
    }

    int countArr(int arr[]){
        int sum = 0;
        for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]) + 1); i++){
            sum += arr[i];
        }
        return sum/;
    }
    #endif

