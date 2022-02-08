// Implement Stack from Scratch
// https://www.tutorialspoint.com/javaexamples/data_stack.htm

#include<bits/stdc++.h>
using namespace std;

// Approach 1
class Stack_in_array{
  private:
    int* stack;
    int max_size, top;

  public:
    Stack_in_array(int max_size)
    {
        this->stack = new int[max_size];
        this->max_size = max_size;
        this->top = -1;
    }

  private:
    void push(int data)
    {
        if(top == max_size-1)
        {
            cout << "Stack overflow";
            return;
        }
            
        stack[top++] = data;
    }

    int pop()
    {
        if(top == -1)
        {
            cout << "Stack underflow";
            return -1;
        }
        return stack[top--];
    }

    int peek()
    {
        if(top == -1)
            return -1;
        return stack[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == max_size - 1;
    }

};

class Node
{
  public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Approach 2
class Stack_in_linked_list{
  private:
    Node* top;
    
  public:
    Stack_in_linked_list()
    {
        top = NULL;
    }

  private:
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if(top == NULL)
        {
            cout << "Stack underflow";
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int result = temp->data;
        delete temp;
        return result;
    }

    int peek()
    {
        if(top == NULL)
            return -1;
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};