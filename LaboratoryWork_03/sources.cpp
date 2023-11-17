#include "sources.h"

void laba_3_1_static()
{
    srand(time(0));
    int n, array[100], sum = 0;
    std::cout << "¬ведите размер массива Array:";
    std::cin >> n;
    std::cout << "Array: ";
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
        sum += array[i];
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl
        << "—умма элементов массива Array:" << sum << std::endl;
}

void laba_3_1_dynamic()
{
    srand(time(0));
    int n, sum = 0;
    std::cout << "¬ведите размер массива Array:";
    std::cin >> n;
    int* array = new int[n];
    std::cout << "Array: ";
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
        sum += array[i];
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl
        << "—умма элементов массива Array:" << sum << std::endl;
    delete[] array;
}

void laba_3_2_dynamic()
{
    srand(time(0));
    int n, m;
    std::cout << "¬ведите размерность матрицы matrix (n x m):";
    std::cin >> n >> m;
    int** matrix = new int* [m];
    int* vector = new int[m];
    int* result_vector = new int[n];
    std::cout << "Matrix:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 10;
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "Vector: ";
    for (size_t i = 0; i < m; i++)
    {
        vector[i] = rand() % 10;
        std::cout << vector[i] << ' ';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        result_vector[i] = 0;
        for (size_t j = 0; j < m; j++)
        {
            result_vector[i] += matrix[i][j] * vector[j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;

    std::cout << "–езультат умножени€ матрицы Matrix на вектор Vector есть вектор Result_vector: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << result_vector[i] << ' ';
    }
    std::cout << std::endl;
    delete[] result_vector;
}

void laba_3_2_vector()
{
    srand(time(0));
    int n, m;
    std::cout << "¬ведите размерность матрицы matrix (n x m):";
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::vector<int> vector(m);
    std::vector<int> result_vector(n);
    std::cout << "Matrix:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 10;
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "Vector: ";
    for (size_t i = 0; i < m; i++)
    {
        vector[i] = rand() % 10;
        std::cout << vector[i] << ' ';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        result_vector[i] = 0;
        for (size_t j = 0; j < m; j++)
        {
            result_vector[i] += matrix[i][j] * vector[j];
        }
    }

    std::cout << "–езультат умножени€ матрицы Matrix на вектор Vector есть вектор Result_vector: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << result_vector[i] << ' ';
    }
    std::cout << std::endl;
}