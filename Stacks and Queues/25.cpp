// Implement Circular Queue
// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
    
    int* a;
    int size, front, rear;
    
  public:
    MyCircularQueue(int k) {
        size = k;
        a = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        
        if(isFull())
            return false;
        
        if(isEmpty())
            front++;
        
        rear = (rear + 1) % size;
        a[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        return a[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        return a[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};
