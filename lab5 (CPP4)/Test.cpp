#include "test.h"
#include "worker.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int test() {
    WORKER worker("������ �.�.", "�������", 2010);
    // �������� ������ �� �����
    cout << "���� 1: ����� �� �����\n";
    cout << worker << endl;

    // �������� ����� � ����������
    WORKER workerInput;
    cout << "���� 2: ���� � ����������\n";
    istringstream input("������� �.�.\n��������\n2015\n");
    input >> workerInput;
    cout << "\n������� �.�.\n��������\n2015\n";

    assert(workerInput.getFullName() == "������� �.�.");
    assert(workerInput.getPosition() == "��������");
    assert(workerInput.getStartYear() == 2015);

    return 1;
}
