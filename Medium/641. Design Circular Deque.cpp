/**  
https://leetcode.com/problems/design-circular-deque/
Using Circular Array to solve the problem.
Note: "next of front" & "previous of rear" must be NULL. XD  
**/

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int *arr;
    int front, rear, maxN;
    
    MyCircularDeque(int k) {
        arr = new int [k];
        front = rear = -1;
        maxN = k-1;
    }
    
    void Set(int val){
        front = rear = val;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;

        if (front == -1)
            Set(0);
        else if (front == 0)
            front = maxN;
        else
            front -= 1;
        arr[front] = value;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;

        if (rear == -1)
            Set(0);
        else if (rear == maxN)
            rear = 0;
        else
            rear += 1;
        arr[rear] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false; 

        arr[front] = -1;
        if (front == rear)
            Set(-1);
        else if (front == maxN)
            front = 0;
        else
            front += 1;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false; 

        arr[rear] = -1;
        if (front == rear)
            Set(-1);
        else if (rear == 0)
            rear = maxN;
        else
            rear -= 1;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (rear == -1 && front == -1)
            return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if ((rear+1 == front) || (front==0 && rear==maxN))
            return true;
        return false;
    }

};

/**
Runtime: 24 ms, faster than 88.69% of C++ online submissions for Design Circular Deque.
Memory Usage: 16.7 MB, less than 95.54% of C++ online submissions for Design Circular Deque.
 */
