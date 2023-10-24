#include <iostream>

const int MAX_SIZE = 100; 

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = value;
            std::cout << "Enqueued " << value << std::endl;
        }
    }

        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        } else {
            int removedValue = arr[front];
            if (front == rear) {
                front = rear = -1; 
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            std::cout << "Dequeued " << removedValue << std::endl;
        }
    }
    int getFront() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            return -1; 
        }
        return arr[front];
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.getFront() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Front element: " << queue.getFront() << std::endl;

    queue.enqueue(4);
    queue.enqueue(5);

    return 0;
}
