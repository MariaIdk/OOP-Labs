#include "Tests.h"
#include "Factory.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

bool testT1() {

    BaseClass* obj = Factory::CreateT1("1", "oleg");

    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    assert(output.str() == "ID: 1\n��������: oleg\n�������� ������: �� �����������\n������������ ������: �� �����������\n����������������� ������: �� �����������\n");

    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
    return true;
}

bool testT2() {
    BaseClass* obj = Factory::CreateT2("2", 42);
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    assert(output.str() == "ID: 2\n��������(� ���������� �������): 42\n�������� ������: 00000000000000000000000000101010\n������������ ������: 52\n����������������� ������: 2a\n"); //��� ������������ ����� ������� ������ ����� 

    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
    return true;
}
