#include "myStuct.h"
#include "CustomHelpers.h"

bool myStuct::Professeur::nameEquals(std::string name, bool caseInsensitive)
{
	if (caseInsensitive) {
		return this->nom == name;
	}

	return CustomHelpers::toDowner(this->nom) == CustomHelpers::toDowner(name);
}
