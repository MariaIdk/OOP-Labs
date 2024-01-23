#include "worker.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

WORKER::WORKER() : fullName(""), position(""), startYear(0) {}

WORKER::WORKER(const string& name, const string& pos, int year)
    : fullName(name), position(pos), startYear(year) {}

const string& WORKER::getFullName() const {
    return fullName;
}

const string& WORKER::getPosition() const {
    return position;
}

bool compareWorkers(const WORKER& worker1, const WORKER& worker2) {
    return worker1.getFullName() < worker2.getFullName();
}

int WORKER::getStartYear() const {
    return startYear;
}

ostream& operator<<(ostream& out, const WORKER& worker) {
    out << "Фамилия и инициалы: " << worker.fullName << endl;
    out << "Должность: " << worker.position << endl;
    out << "Год поступления на работу: " << worker.startYear << endl;
    return cout;
}

istream& operator>>(istream& in, WORKER& worker) {
    cout << "Введите фамилию и инициалы работника: ";
    getline(in, worker.fullName);

    cout << "Введите название занимаемой должности: ";
    getline(in, worker.position);

    cout << "Введите год поступления на работу: ";
    in >> worker.startYear;

    // Очистка входного буфера
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    return in;
}
