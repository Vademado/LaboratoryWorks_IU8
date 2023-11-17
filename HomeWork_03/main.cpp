#include "sources.h"

int main(int argc, char* argv[]) // argv[1] = -c compressFile /-d decompressFile, argv[2] = sourceFileName
{
    setlocale(LC_ALL, "ru");

    std::string mode = argv[1], sourceFileName = argv[2];

    archiver(mode, sourceFileName);

    return 0;
}