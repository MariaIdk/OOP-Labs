#include "T2.h"
#include <bitset>
// ���������� ������������ ������ T2
T2::T2(const std::string& id, int value) : BaseClass(id), value(value) {}

// ���������� ������� ������ T2

void T2::ShowBin() const {
    std::cout << "�������� ������: " << std::bitset<32>(value) << std::endl;
}

void T2::ShowOct() const {
    std::cout << "������������ ������: " << std::oct << value << std::endl;
}

void T2::ShowHex() const {
    std::cout << "����������������� ������: " << std::hex << value << std::endl;
}
void T2::ShowValue() const {
    std::cout << "��������(� ���������� �������): " << std::dec << value << std::endl;
}
