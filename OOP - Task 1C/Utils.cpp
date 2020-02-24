#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::ToUpperI(std::string s)
{
    for (int i=0;i<s.length();i++)
    {
        if (s[i] > 96 && s[i] < 123)
            s[i] = s[i] ^ 32;
    }
    return s;
}

std::string Utils::ToUpperR(std::string s)
{
    if (s.length() > 0)
    {
        char first = s[0];
        if (first > 96 && first < 123)
        {
            first = (first ^ 32);
        }
        return first + ToUpperR(s.substr(1));
    }
    else
        return s;
}