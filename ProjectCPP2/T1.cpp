#include "T1.h"

// ���������� ������������ ������ T1
T1::T1(const std::string& id, const std::string& value) : BaseClass(id), value(value) {}

// ���������� ������� ������ T1
void T1::ShowBin() const {
    std::cout << "�������� ������: �� �����������" << std::endl;
}

void T1::ShowOct() const {
    std::cout << "������������ ������: �� �����������" << std::endl;
}

void T1::ShowHex() const {
    std::cout << "����������������� ������: �� �����������" << std::endl;
}

void T1::ShowValue() const {
    std::cout << "��������: " << value << std::endl;
}
