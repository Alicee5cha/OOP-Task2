#include "Guest.h"
#include "Utils.h"
#include <string.h>
Guest::Guest(vector<LibraryItem*>* AdminLibrary):User((string&)"",(string&)"",Utils::getCurrentDate()->getDate(),0)
{
	library = *AdminLibrary;
}

