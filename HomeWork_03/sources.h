#pragma once
#include <fstream>
#include <iostream>
#include <string>

void printBinaryFile(const std::string& sourceFileName);
void compressFile(const std::string& sourceFileName, const std::string& compressedFileName);
void decompressFile(const std::string& compressedFileName, const std::string& decompressedFileName);
void convertBytes(const std::string& sourceFileName, const std::string& convertedFileName);
void archiver(const std::string& mode, const std::string& sourceFileName, bool printingBytes = false);