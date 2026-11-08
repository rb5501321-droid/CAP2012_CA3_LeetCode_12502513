   // LeetCode 622 - Design Circular Queue
class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = 0;
        count = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        int rear = (front + count) % capacity;
        data[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(front + count - 1) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
