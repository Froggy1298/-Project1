#include "FileHelper.h"
#include <fstream>
#include "myStuct.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

FileHelper::FileHelper()
{
	//TODO
}

FileHelper::~FileHelper()
{
}

bool FileHelper::CreateEmptyFile(std::string fileName)
{
	std::ofstream outputFile(fileName);
	if (outputFile.is_open()) {
		std::cout << "File created successfully." << std::endl;
		outputFile.close();
		return true;
	}
	else {
		std::cout << "Error creating the file." << std::endl;
		return false;
	}
}

std::vector<std::string> FileHelper::ReadFile(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);
	if (!inputFile.is_open()) {
		std::cout << "Failed to open the file!" << std::endl;
		return std::vector<std::string>();
	}


	std::vector<std::string> contenu;
	std::string tempLineString;

	while (std::getline(inputFile, tempLineString)) {
		contenu.push_back(tempLineString);
	}

	return contenu;
}

bool FileHelper::DeleteFile(std::string fileName)
{
	const char* convertFileName = fileName.c_str();
	if (std::remove(convertFileName) == 0) {
		std::cout << "File '" << fileName << "' deleted successfully." << std::endl;
		return true;
	}
	else {
		std::cout << "Error deleting file '" << fileName << "'" << std::endl;
		return false;
	}
}

bool FileHelper::Writefile(std::string fileName, bool keepWhatExist, std::vector<std::string> lignes)
{
	std::ofstream outputFile(fileName);

	if (keepWhatExist)
		std::ofstream outputFile(fileName, std::ios::app);
	else
		std::ofstream outputFile(fileName);

	if (!outputFile.is_open()) {
		std::cout << "THE FILE IS NOT OPEN\n";
		return false;
	}

	for (int cpt = 0; cpt < lignes.size(); cpt++)
	{
		outputFile << lignes[cpt] << "\n";
	}

	outputFile.close();

	return !outputFile.is_open();
}
