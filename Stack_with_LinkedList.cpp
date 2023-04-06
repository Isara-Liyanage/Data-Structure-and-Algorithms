#include <iostream>
#include <chrono>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { 
        top = NULL; 
    }

    bool isEmpty() { 
        return (top == NULL ? true : false); 
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << "\n";
            return -1;
        }

        int x = top->data;
        Node* temp = top;
        top = top->next;
        return x;
    }
    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << "\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" <<"\n";
            return;
        }
        cout << "Stack elements(First element represents the top): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    auto t_start = chrono::high_resolution_clock::now();   
    Stack s; // create stack object
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();

    cout << "Poped values: ";
    for(int i=0;i<5;i++){
        cout << s.pop()<<" ";
    }
    cout <<"\n";

    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    s.display();

    auto t_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_end - t_start).count();
    cout <<"-----------------------------"<<"\n";
    cout << "Time taken : " << duration <<"\n";
    return 0;
}

