// Implement Queue using array
// https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1/

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    // Your Code
    if(rear < 100004)
    arr[rear++] = x;    
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    // Your Code
    
    if(front == 0 && rear == 0)
        return -1;
    int val = arr[front];
    front++;
    if(front == rear) {
        
        front = 0;
        rear = 0;
    }
    
    return val;
}
