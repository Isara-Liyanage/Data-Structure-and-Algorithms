#include <iostream>
#include <chrono>

using namespace std;

class Stack {
private:
    int top;
    int* arr;
    int size;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    
    bool isEmpty() { 
        return (top == -1 ? true : false); 
    }

    bool isFull() { 
        return (top == size - 1 ? true : false); 
        }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << "\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << "\n";
            return -1;
        }
        int temp = arr[top];
        top--;
        return temp;
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" <<"\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        // Prints elements from bottom to top of stack
        cout << "Stack elements(Last element represents the top): ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    auto t_start = chrono::high_resolution_clock::now();  
    Stack s(10); // create stack object with size 10
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
