#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue recursively
void reverseQueue(queue<int>& q) {
    if (q.empty()) {
        return;
    }

    // Step 1: Dequeue the front element
    int front = q.front();
    q.pop();

    // Step 2: Recursively call reverseQueue for the rest of the queue
    reverseQueue(q);

    // Step 3: Enqueue the front element back to the queue
    q.push(front);
}

// Helper function to print the queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    // Example 1
    queue<int> q1;
    q1.push(5);
    q1.push(24);
    q1.push(9);
    q1.push(6);
    q1.push(8);
    q1.push(4);
    q1.push(1);
    q1.push(8);
    q1.push(3);
    q1.push(6);

    cout << "Original Queue: ";
    printQueue(q1);

    reverseQueue(q1);

    cout << "Reversed Queue: ";
    printQueue(q1);

    // Example 2
    queue<int> q2;
    q2.push(8);
    q2.push(7);
    q2.push(2);
    q2.push(5);
    q2.push(1);

    cout << "Original Queue: ";
    printQueue(q2);

    reverseQueue(q2);

    cout << "Reversed Queue: ";
    printQueue(q2);

    return 0;
}
