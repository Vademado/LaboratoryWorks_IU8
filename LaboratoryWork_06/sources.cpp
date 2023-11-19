#include "sources.h"

void printStudent(const Student& student)
{
    std::cout << "Full name: " << student.full_name << std::endl;
    std::cout << "Study group: " << student.study_group << std::endl;
    std::cout << "Credit card number: " << student.credit_card_number << std::endl;
    std::cout << "Assessment for exams: ";
    for (unsigned short int mark : student.grades)
    {
        std::cout << mark << " ";
    }
    std::cout << "#############################################" << std::endl;
}

void fileManager(const std::string mode, const std::string representation, const std::string fileName)
{
    if (mode == "-r")
    {
        std::ifstream readFile;
        if (representation == "bin")
        {
            readFile.open(fileName, std::ios::binary);
        }
        else
        {
            readFile.open(fileName);
        }

        if (!readFile)
        {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }

        //std::vector<Student> students;
        Student student;
        while (!readFile.eof())
        {
            if (representation == "bin")
            {
                readFile.read((char*)&student, sizeof(Student));
            }
            else
            {
                std::string study_group, credit_card_number, mark1, mark2, mark3, mark4;
                readFile >> student.full_name;
                readFile >> study_group >> credit_card_number >> mark1 >> mark2 >> mark3 >> mark3;
                student.study_group = (unsigned short int)std::stoi(study_group);
                student.credit_card_number = (unsigned int)std::stoi(credit_card_number);
                student.grades = std::vector<unsigned short int>{ (unsigned short int)std::stoi(mark1), (unsigned short int)std::stoi(mark2), (unsigned short int)std::stoi(mark3), (unsigned short int)std::stoi(mark4) };
            }
            //students.push_back(student);
            printStudent(student);
        }

        readFile.close();

        //for (Student student : students)
        //{
           // printStudent(student);
        //}
    }
    else if (mode == "-w")
    {
        std::ofstream writeFile;
        if (representation == "bin")
        {
            writeFile.open(fileName, std::ios::binary | std::ios::app);
        }
        else
        {
            writeFile.open(fileName, std::ios::app);
        }

        if (!writeFile)
        {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }

        unsigned int n;
        std::cout << "Enter count of students: ";
        std::cin >> n;
        for (size_t i = 0; i < n; ++i)
        {
            std::string full_name;
            std::cout << "Enter the student's name: ";
            std::cin >> full_name;

            unsigned short study_group;
            std::cout << "Enter the study group: ";
            std::cin >> study_group;

            unsigned int credit_card_number;
            std::cout << "Enter credit card number: ";
            std::cin >> credit_card_number;

            unsigned short int mark1, mark2, mark3, mark4;
            std::cout << "Enter 4 assessments for exams: ";
            std::cin >> mark1 >> mark2 >> mark3 >> mark4;
            std::vector<unsigned short int> grades{ mark1, mark2, mark3, mark4 };

            if (representation == "bin")
            {
                Student student = { full_name, study_group, credit_card_number, grades };
                writeFile.write((char*)&student, sizeof(Student));
            }
            else
            {
                writeFile << full_name << " " << study_group << " " << credit_card_number << " " << mark1 << " " << mark2 << " " << mark3 << " " << mark4 << std::endl;
            }

            std::cout << "#############################################" << std::endl;
        }

        writeFile.close();
    }
    else
    {
        std::ofstream clearFile;
        if (representation == "bin")
        {
            clearFile.open(fileName, std::ios::binary | std::ios::trunc);
        }
        else
        {
            clearFile.open(fileName, std::ios::trunc);
        }
        clearFile.close();
    }
}