#include "sources.h"


int main(int argc, char* argv[]) 
{
    setlocale(LC_ALL, "ru");

    int n = std::stoi(argv[1]);
    print_answer(n, fibonacci(n));
    std::cout << std::endl;
    print_answer(n, fibonacci_recursive(n));
    return 0;
}