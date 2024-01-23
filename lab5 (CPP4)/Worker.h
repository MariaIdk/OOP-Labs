#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class WORKER {
private:
    string fullName;
    string position;
    int startYear;

public:
    WORKER();
    WORKER(const string& name, const string& pos, int year);
    const string& getFullName() const;
    const string& getPosition() const;
    int getStartYear() const;

    friend ostream& operator<<(ostream& out, const WORKER& worker);
    friend istream& operator>>(istream& in, WORKER& worker);

};

bool compareWorkers(const WORKER& worker1, const WORKER& worker2);

#endif

