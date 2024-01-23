#include "worker.h"
#include "test.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ������� ��� ����� ������ � ����������
void inputWorkers(WORKER workers[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "\n������� ���������� � ��������� #" << i + 1 << endl;
        cin >> workers[i];
    }
}

// ������� ��� ������ ������� ���������� � ������������ ������
void outputWorkersWithExperience(const WORKER workers[], int arraySize, int thresholdYear) {
    bool found = false;

    for (int i = 0; i < arraySize; ++i) {
        if (2023 - workers[i].getStartYear() > thresholdYear) {
            cout << "������� ��������� � ������ ����� " << thresholdYear << " ���: "
                << workers[i].getFullName() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "��� ���������� �� ������ ����� " << thresholdYear << " ���." << endl;
    }
}

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};


int main() {
    setlocale(LC_ALL, "Russian");


    if (test() == 1) {
        std::cout << "\n����-����� �������� �������!" << std::endl;
    }
    else {
        std::cerr << "����-����� �� ��������!" << std::endl;
    }

    const int arraySize = 3;
    WORKER workers[arraySize];

    // ���� ������ � ����������
    inputWorkers(workers, arraySize);
    {
        LogDuration input;
        // ���������� ���������� �� ��������
        sort(workers, workers + arraySize, compareWorkers);
    }
    int thresholdYear;
    cout << "\n������� ����, ���������� �������� ����� �����: ";
    cin >> thresholdYear;
    {
        LogDuration input;
        // ����� ������� ���������� � ������������ ������
        outputWorkersWithExperience(workers, arraySize, thresholdYear);

        return 0;
    }
}
