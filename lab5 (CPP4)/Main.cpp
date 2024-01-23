#include "worker.h"
#include "test.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для ввода данных о работниках
void inputWorkers(WORKER workers[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "\nВведите информацию о работнике #" << i + 1 << endl;
        cin >> workers[i];
    }
}

// Функция для вывода фамилий работников с определенным стажем
void outputWorkersWithExperience(const WORKER workers[], int arraySize, int thresholdYear) {
    bool found = false;

    for (int i = 0; i < arraySize; ++i) {
        if (2023 - workers[i].getStartYear() > thresholdYear) {
            cout << "Фамилия работника с стажем более " << thresholdYear << " лет: "
                << workers[i].getFullName() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет работников со стажем более " << thresholdYear << " лет." << endl;
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
        std::cout << "\nЮнит-тесты пройдены успешно!" << std::endl;
    }
    else {
        std::cerr << "Юнит-тесты не пройдены!" << std::endl;
    }

    const int arraySize = 3;
    WORKER workers[arraySize];

    // Ввод данных о работниках
    inputWorkers(workers, arraySize);
    {
        LogDuration input;
        // Сортировка работников по алфавиту
        sort(workers, workers + arraySize, compareWorkers);
    }
    int thresholdYear;
    cout << "\nВведите стаж, превышение которого нужно найти: ";
    cin >> thresholdYear;
    {
        LogDuration input;
        // Вывод фамилий работников с определенным стажем
        outputWorkersWithExperience(workers, arraySize, thresholdYear);

        return 0;
    }
}
