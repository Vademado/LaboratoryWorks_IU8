#include "sources.h"

void laba_1_1()
{
    float carburetor, ignition_system, pistons;
    float economy = 0;
    std::cout << "������� % �������� ������� ������ �����������:";
    std::cin >> carburetor;
    economy += (1 - economy) * (carburetor / 100);
    std::cout << "������� % �������� ������� ����� ������� ���������:";
    std::cin >> ignition_system;
    economy += (1 - economy) * (ignition_system / 100);
    std::cout << "������� % �������� ������� ����� ��������� �����:";
    std::cin >> pistons;
    economy += (1 - economy) * (pistons / 100);
    std::cout << "�������� ��������:" << economy * 100 << "%" << std::endl;
}

void laba_1_2()
{
    float a, b, c, r, s;
    std::cout << "������� ������� ������� (a, b, c):";
    std::cin >> a >> b >> c;
    std::cout << "������� ������� ���� (r, s):";
    std::cin >> r >> s;
    if (((a <= r) && (b <= s)) || ((a <= s) & (b <= r)) ||
        ((a <= r) && (c <= s)) || ((a <= s) && (c <= r)) ||
        ((c <= r) && (b <= s)) || ((c <= s) && (b <= r)))
    {
        std::cout << "������" << std::endl;
    }
    else
    {
        std::cout << "�� ������" << std::endl;
    }
}
