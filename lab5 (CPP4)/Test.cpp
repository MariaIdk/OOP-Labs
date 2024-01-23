#include "test.h"
#include "worker.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int test() {
    WORKER worker("Иванов И.И.", "Инженер", 2010);
    // Проверка вывода на экран
    cout << "Тест 1: Вывод на экран\n";
    cout << worker << endl;

    // Проверка ввода с клавиатуры
    WORKER workerInput;
    cout << "Тест 2: Ввод с клавиатуры\n";
    istringstream input("Сидоров С.С.\nМенеджер\n2015\n");
    input >> workerInput;
    cout << "\nСидоров С.С.\nМенеджер\n2015\n";

    assert(workerInput.getFullName() == "Сидоров С.С.");
    assert(workerInput.getPosition() == "Менеджер");
    assert(workerInput.getStartYear() == 2015);

    return 1;
}
