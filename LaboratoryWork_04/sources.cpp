#include "sources.h"

void quickSort(Student* array, int left, int right)
{
    if (left >= right)
        return;
    int p = array[(left + right) / 2].group_number, i = left, j = right;
    while (i <= j)
    {
        while (array[i].group_number < p)
            i++;
        while (array[j].group_number > p)
            j--;
        if (i <= j)
        {
            Student tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(array, left, j);
    quickSort(array, i, right);
}

void laba_4()
{
    unsigned count_students;
    std::cout << "Введите количество студентов: ";
    std::cin >> count_students;
    Student* students = new Student[count_students];
    for (size_t i = 0; i < count_students; ++i)
    {
        unsigned count_disciplines;
        std::cout << "Введите ФИО студента: ";
        std::cin >> students[i].full_name;
        std::cout << "Введите номер группы: ";
        std::cin >> students[i].group_number;
        std::cout << "Введите количество дисциплин: ";
        std::cin >> count_disciplines;
        students[i].disciplines = std::vector<Discipline>{ count_disciplines };
        for (size_t j = 0; j < count_disciplines; ++j)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Введите название дисциплины: ";
            std::cin >> students[i].disciplines[j].title;
            std::cout << "Введите оценку: ";
            std::cin >> students[i].disciplines[j].mark;
        }
        std::cout << "#############################################" << std::endl;
    }

    quickSort(students, 0, count_students - 1);

    unsigned study_group = students[0].group_number;
    int counter = 0;
    for (size_t i = 0; i < count_students; ++i)
    {
        if (study_group != students[i].group_number)
        {
            std::cout << "Студентов в " << study_group << " группе, имеющих неудовлетворительную оценку: " << counter << std::endl;
            study_group = students[i].group_number;
            counter = 0;
        }
        for (Discipline discipline : students[i].disciplines)
        {
            if (discipline.mark <= 2)
            {
                counter++;
                break;
            }
        }
    }
    std::cout << "Студентов в " << study_group << " группе, имеющих неудовлетворительную оценку: " << counter << std::endl;
    std::cout << std::endl;
    delete[] students;
}

void laba_4_map()
{
    unsigned count_students;
    std::map<unsigned, std::vector<Student>> students;
    std::cout << "Введите количество студентов: ";
    std::cin >> count_students;
    for (size_t i = 0; i < count_students; ++i)
    {
        unsigned count_disciplines, group_number;
        std::string full_name;
        std::cout << "Введите ФИО студента: ";
        std::cin >> full_name;
        std::cout << "Введите номер группы: ";
        std::cin >> group_number;
        std::cout << "Введите количество дисциплин: ";
        std::cin >> count_disciplines;
        std::vector<Discipline> disciplines(count_disciplines);
        for (size_t j = 0; j < count_disciplines; ++j)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Введите название дисциплины: ";
            std::cin >> disciplines[j].title;
            std::cout << "Введите оценку: ";
            std::cin >> disciplines[j].mark;
        }
        if (students.count(group_number) == 0)
            students[group_number] = std::vector<Student>(0);
        students[group_number].push_back(Student{ full_name, group_number, disciplines });
        std::cout << "#############################################" << std::endl;
    }

    int counter;
    for (const std::pair<const unsigned, const std::vector<Student>>& item : students)
    {
        counter = 0;
        for (Student student : item.second)
        {
            for (Discipline discipline : student.disciplines)
            {
                if (discipline.mark <= 2)
                {
                    counter++;
                    break;
                }
            }
        }
        std::cout << "Студентов в " << item.first << " группе, имеющих неудовлетворительную оценку: " << counter << std::endl;
    }
    std::cout << std::endl;
}