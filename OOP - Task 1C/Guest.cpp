#include "Guest.h"
#include "Utils.h"
#include <string.h>
Guest::Guest(vector<LibraryItem*>* AdminLibrary):User("GUEST","",Utils::getCurrentDate(),0)
{
	if (!AdminLibrary->empty())
	{
		for (int i = 0; i < AdminLibrary->size(); i++)
		{
			if ((*AdminLibrary)[i]->isShared())
				GetLibrary()->push_back((new LibraryItem(new Date(),(*AdminLibrary)[i]->getGame(),0)));

		}
	}
}

const bool Guest::isGuest() const
{
	
	return true;
}
