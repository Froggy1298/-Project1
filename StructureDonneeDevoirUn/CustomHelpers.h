#pragma once
#include <string>

class CustomHelpers {
public:
	/// <summary>
	/// This function is used to put a whole string to lower
	/// My source used for this what this website:
	/// https://www.geeksforgeeks.org/tolower-function-in-cpp/
	/// The name of the function is ToDowner and not ToLower because it is an inside between my friend and I
	/// </summary>
	/// <param name="toMakeDowner">the string I want to put in lower case</param>
	/// <returns>the string in lower case</returns>
	static std::string toDowner(std::string toMakeDowner);
};