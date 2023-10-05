#pragma once
#include <vector>
#include <string>

static class FileHelper
{
public:
	FileHelper();
	~FileHelper();

	bool CreateEmptyFile(std::string fileName);

	std::vector<std::string> ReadFile(std::string fileName);

	bool DeleteFile(std::string fileName);

	bool Writefile(std::string fileName, bool keepWhatExist, std::vector<std::string> lignes);
};

