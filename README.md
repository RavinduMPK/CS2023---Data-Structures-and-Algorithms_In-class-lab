# CS2023---Data-Structures-and-Algorithms_In-class-lab_week-6
This is the c++ code for week 6 inclass lab, Stack using linked list

// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        }

        int popped_element = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "popped" << popped_element;
        cout << endl;
        cout << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void Display() {
        cout << "Current Stack: ";
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        cout << endl;
    }
};

int main() {

    auto start = high_resolution_clock::now();

    Stack s;
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
    s.Display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.Display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    float durationFloat = static_cast<float>(duration.count()) / 1000000000.0f;
    cout << endl;
    cout << endl;
    cout << "time taken for the execution is " << durationFloat << " seconds" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
