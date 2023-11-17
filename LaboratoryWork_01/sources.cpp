#include "sources.h"

void laba_1_1()
{
    float carburetor, ignition_system, pistons;
    float economy = 0;
    std::cout << "Введите % экономии топлива нового карбюратора:";
    std::cin >> carburetor;
    economy += (1 - economy) * (carburetor / 100);
    std::cout << "Введите % экономии топлива новой системы зажигания:";
    std::cin >> ignition_system;
    economy += (1 - economy) * (ignition_system / 100);
    std::cout << "Введите % экономии топлива новых поршневых колец:";
    std::cin >> pistons;
    economy += (1 - economy) * (pistons / 100);
    std::cout << "Итоговая экономия:" << economy * 100 << "%" << std::endl;
}

void laba_1_2()
{
    float a, b, c, r, s;
    std::cout << "Введите стороны кирпича (a, b, c):";
    std::cin >> a >> b >> c;
    std::cout << "Введите стороны окна (r, s):";
    std::cin >> r >> s;
    if (((a <= r) && (b <= s)) || ((a <= s) & (b <= r)) ||
        ((a <= r) && (c <= s)) || ((a <= s) && (c <= r)) ||
        ((c <= r) && (b <= s)) || ((c <= s) && (b <= r)))
    {
        std::cout << "Пройдёт" << std::endl;
    }
    else
    {
        std::cout << "Не пройдёт" << std::endl;
    }
}
