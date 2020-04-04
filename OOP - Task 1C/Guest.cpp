#include "Guest.h"
#include "Utils.h"
#include <string.h>
Guest::Guest(vector<LibraryItem*>* AdminLibrary):User("GUEST","",Utils::getCurrentDate(),0)
{
	if (AdminLibrary != nullptr)
	for (LibraryItem* l : *AdminLibrary)
		GetLibrary()->push_back(l);
}

const bool Guest::isGuest() const
{
	
	return true;
}
