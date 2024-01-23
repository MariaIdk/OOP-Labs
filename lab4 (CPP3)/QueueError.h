#ifndef _QUEUE_ERROR_H_
#define _QUEUE_ERROR_H_

#include <iostream>

class QueueError {
public:
    QueueError() {}
    virtual void ErrMsg() const { std::cerr << "Error with Queue object.\n"; }
    void Continue() const {
        std::cerr << "Program is being continued.\n";
    }
};

class QueueEmptyErr : public QueueError {
public:
    void ErrMsg() const {
        std::cerr << "Error: Queue is empty.\n";
        Continue();
    }
};

#endif /* _QUEUE_ERROR_H_ */
