#include "CustomHelpers.h"



std::string CustomHelpers::toDowner(std::string toMakeDowner)
{
	for (auto& x : toMakeDowner) {
		x = tolower(x);
	}
	return toMakeDowner;
}
