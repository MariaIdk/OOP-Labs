#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "QueueError.h"
#include "List.h"

template <typename T, typename B = List<T>>
class Queue {
private:
    B container;

public:
    void Enqueue(const T& data) {
        container.Push(data);
    }

    T Dequeue() {
        try {
            return container.Pop();
        }
        catch (const QueueEmptyErr& e) {
            e.ErrMsg();
            throw; // Пробросим исключение дальше
        }
    }
};

#endif /* _QUEUE_H_ */
