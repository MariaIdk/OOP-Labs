#include <iostream>
#include "Tests.h"
#include "Factory.h"

int main() {
    setlocale(LC_ALL, "Russian");

    if (testT1() && testT2()) {
        std::cout << "����-����� �������� �������!" << std::endl;
    }
    else {
        std::cerr << "����-����� �� ��������!" << std::endl;
    }

    BaseClass* obj = nullptr;
    int choice;

    do {
        std::cout << "\n1. ������� � ��������� �������� ��� T1" << std::endl;
        std::cout << "2. ������� � ��������� �������� ��� T2" << std::endl;
        std::cout << "0. ����� \n" << std::endl;

        std::cout << "������� �������: \n";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string id, value;
            std::cout << "������� ID ��� T1: ";
            std::cin >> id;
            std::cout << "������� �������� ��� T1: ";
            std::cin >> value;
            obj = Factory::CreateT1(id, value);
            break;
        }
        case 2: {
            std::string id;
            int value;
            std::cout << "������� ID ��� T2: ";
            std::cin >> id;
            while (true) {
                std::cout << "������� �������� ��� T2: ";
                if (std::cin >> value) {
                    break;
                }
                else {
                    std::cerr << "������ �����! ������� ������������� ��������." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            obj = Factory::CreateT2(id, value);
            break;
        }
        case 0:
            std::cout << "����� �� ���������." << std::endl;
            break;
        default:
            std::cout << "����������� �������." << std::endl;
        }

        if (obj != nullptr) {
            obj->ShowId();
            obj->ShowValue();
            obj->ShowBin();
            obj->ShowOct();
            obj->ShowHex();
            Factory::DeleteObject(obj);
            obj = nullptr;
        }

    } while (choice != 0);

    return 0;
}
