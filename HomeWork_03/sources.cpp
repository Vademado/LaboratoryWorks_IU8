#include "sources.h"

void printBinaryFile(const std::string& sourceFileName)
{
    std::ifstream sourceFile(sourceFileName, std::ios::binary);

    if (!sourceFile)
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::cout << "Binary representation of the file " << sourceFileName << std::endl;

    char currentByte;
    while (sourceFile.get(currentByte))
    {
        std::cout << std::hex << static_cast<int>(static_cast<unsigned char>(currentByte)) << '\t';
    }
    std::cout << std::endl;

    sourceFile.close();
}

void compressFile(const std::string& sourceFileName, const std::string& compressedFileName)
{
    std::ifstream sourceFile(sourceFileName, std::ios::binary);
    std::ofstream compressedFile(compressedFileName, std::ios::binary);

    if (!sourceFile || !compressedFile)
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    char currentByte;
    char consecutiveByte;
    unsigned char consecutiveCount;
    while (sourceFile.get(currentByte))
    {
        if (currentByte == consecutiveByte)
        {
            consecutiveCount++;
        }
        else
        {
            if (consecutiveCount > 1)
            {
                // переполнение с количеством, когда подр€д больше 255!!!!!!!!!!!!!!!!!!
                unsigned char countByte = consecutiveCount + 0x80;
                compressedFile.write((char*)&countByte, sizeof(unsigned char));
                compressedFile.write(&consecutiveByte, sizeof(char));
            }
            if (consecutiveCount == 1)
            {
                compressedFile.write(&consecutiveByte, sizeof(consecutiveByte));
            }
            consecutiveByte = currentByte;
            consecutiveCount = 1;
        }
    }

    if (consecutiveCount > 1)
    {
        unsigned char countByte = consecutiveCount + 0x80;
        compressedFile.write((char*)&countByte, sizeof(countByte));
        compressedFile.write(&consecutiveByte, sizeof(consecutiveByte));
    }
    if (consecutiveCount == 1)
    {
        compressedFile.write(&consecutiveByte, sizeof(consecutiveByte));
    }

    sourceFile.close();
    compressedFile.close();
}

void decompressFile(const std::string& compressedFileName, const std::string& decompressedFileName)
{
    std::ifstream compressedFile(compressedFileName, std::ios::binary);
    std::ofstream decompressedFile(decompressedFileName, std::ios::binary);

    if (!compressedFile || !decompressedFile)
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    char currentByte;
    while (compressedFile.get(currentByte))
    {
        if ((unsigned char)currentByte >= 0x80)
        {
            char count = (currentByte & 0x7F);
            char repeatedByte;
            if (compressedFile.get(repeatedByte))
            {
                for (size_t i = 0; i < count; ++i)
                {
                    decompressedFile.write(&repeatedByte, sizeof(repeatedByte));
                }
            }
        }
        else
        {
            decompressedFile.write(&currentByte, sizeof(currentByte));
        }
    }

    compressedFile.close();
    decompressedFile.close();
}

void convertBytes(const std::string& sourceFileName, const std::string& convertedFileName)
{
    std::ifstream sourceFile(sourceFileName, std::ios::binary);
    std::ofstream convertedFile(convertedFileName, std::ios::binary);

    if (!sourceFile || !convertedFile)
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    char currentByte;
    while (sourceFile.get(currentByte))
    {
        currentByte = currentByte & 0x7F;
        convertedFile.write(&currentByte, sizeof(currentByte));
    }

    sourceFile.close();
    convertedFile.close();
}

void archiver(const std::string& mode, const std::string& sourceFileName, bool printingBytes)
{
    if (mode == "-c")
    {
        std::string convertedFileName, compressedFileName;
        if (printingBytes)
        {
            printBinaryFile(sourceFileName);
        }
        std::cout << "¬ведите название преобразованного файла дл€ архивации: ";
        std::cin >> convertedFileName;
        convertBytes(sourceFileName, convertedFileName);
        if (printingBytes)
        {
            printBinaryFile(convertedFileName);
        }
        std::cout << std::endl << "¬ведите название дл€ архивированного файла: ";
        std::cin >> compressedFileName;
        compressFile(convertedFileName, compressedFileName);
        if (printingBytes)
        {
            printBinaryFile(compressedFileName);
        }
        std::cout << std::endl
            << "Successfully created " << compressedFileName << std::endl;
    }
    else
    {
        std::string decompressedFileName;
        if (printingBytes)
        {
            printBinaryFile(sourceFileName);
        }
        std::cout << std::endl << "¬ведите название дл€ разархивированного файла: ";
        std::cin >> decompressedFileName;
        decompressFile(sourceFileName, decompressedFileName);
        if (printingBytes)
        {
            printBinaryFile(decompressedFileName);
        }
        std::cout << std::endl << "Successfully created " << decompressedFileName << std::endl;
    }
}