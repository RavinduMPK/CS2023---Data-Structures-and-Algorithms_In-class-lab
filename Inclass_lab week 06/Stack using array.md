
// This is the c++ code for week 6 inclass lab, Stack using array

#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

int top = -1;
int stack[] = { 0,0,0,0,0,0,0,0,0,0 };
int stack_size = 10;

void push(int data) {

    top++;

    if (top >= stack_size) {
        cout << "Stack overflow";
    }

    else {
        stack[top] = data;
    }
}

void pop() {

    if (top < 0) {
        cout << "Stack Underflow";
    }

    else {
        cout << "poped: " << stack[top];
        cout << endl;
        cout << endl;
        top--;
    }
}

void isEmpty() {
    if (top < 0) {
        cout << "True";
    }

    else {
        cout << "False";
    }
}

void isFull() {
    if (top >= 10) {
        cout << "True";
    }

    else {
        cout << "False";
    }
}

void StackTop() {
    cout << "Stack top is " << top;
}

void Display() {
    cout << "Current Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    auto start = high_resolution_clock::now();

    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    Display();
    pop();
    pop();
    pop();
    pop();
    pop();
    Display();
    push(4);
    push(30);
    push(3);
    push(1);
    Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    float durationFloat = static_cast<float>(duration.count()) / 1000000000.0f;
    cout << endl;
    cout << endl;
    cout << "time taken for the execution is " << durationFloat << " seconds" << endl;
}

