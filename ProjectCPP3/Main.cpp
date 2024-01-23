#include "Queue.h"
#include <iostream>

int main() {
    try {
        // Использование для типа int
        Queue<int> intQueue;
        intQueue.Enqueue(10);
        intQueue.Enqueue(20);
        intQueue.Enqueue(30);

        std::cout << "Dequeued: " << intQueue.Dequeue() << std::endl;
        std::cout << "Dequeued: " << intQueue.Dequeue() << std::endl;
        std::cout << "Dequeued: " << intQueue.Dequeue() << std::endl;

        // Попытка извлечения из пустой очереди
        std::cout << "Dequeued: " << intQueue.Dequeue() << std::endl;
    }
    catch (...) {
        std::cerr << "An error occurred while dequeuing int elements.\n";
    }

    try {
        // Использование для типа double
        Queue<double> doubleQueue;
        doubleQueue.Enqueue(3.14);
        doubleQueue.Enqueue(2.71);

        std::cout << "Dequeued: " << doubleQueue.Dequeue() << std::endl;
        std::cout << "Dequeued: " << doubleQueue.Dequeue() << std::endl;

        // Попытка извлечения из пустой очереди
        std::cout << "Dequeued: " << doubleQueue.Dequeue() << std::endl;
    }
    catch (...) {
        std::cerr << "An error occurred while dequeuing double elements.\n";
    }

    try {
        // Использование для типа std::string
        Queue<std::string> stringQueue;
        stringQueue.Enqueue("Hello");
        stringQueue.Enqueue("World");

        std::cout << "Dequeued: " << stringQueue.Dequeue() << std::endl;
        std::cout << "Dequeued: " << stringQueue.Dequeue() << std::endl;

        // Попытка извлечения из пустой очереди
        std::cout << "Dequeued: " << stringQueue.Dequeue() << std::endl;
    }
    catch (...) {
        std::cerr << "An error occurred while dequeuing string elements.\n";
    }

    return 0;
}
