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
    out << "������� � ��������: " << worker.fullName << endl;
    out << "���������: " << worker.position << endl;
    out << "��� ����������� �� ������: " << worker.startYear << endl;
    return cout;
}

istream& operator>>(istream& in, WORKER& worker) {
    cout << "������� ������� � �������� ���������: ";
    getline(in, worker.fullName);

    cout << "������� �������� ���������� ���������: ";
    getline(in, worker.position);

    cout << "������� ��� ����������� �� ������: ";
    in >> worker.startYear;

    // ������� �������� ������
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    return in;
}
