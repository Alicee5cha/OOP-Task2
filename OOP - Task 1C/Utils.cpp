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

bool Utils::StartsWith(std::string fullText, std::string searchText)
{
    if (ToUpperR(fullText).substr(0, searchText.length())._Equal(ToUpperR(searchText)))
        return true;
    return false;
}

string Utils::getCurrentDate()
{
    string date;
    Date* d = new Date();
    return d->DateToString();
}
//Return a number between min and max, inclusive.
int Utils::randomInt(int min, int max) {
    return (min + rand() % (max + 1 - min));
}
//Returns time formatted
string Utils::ReturnPlayTime(int timeInMinutes)
{
    string os;

    if (timeInMinutes < 60)                 //Minutes
        os = timeInMinutes + " minutes.";
    else if (timeInMinutes < 300)           //Hours.minutes
    {
        string t = to_string( ((float)timeInMinutes / 60.0f));
        t = t.substr(0, t.find('.') + 2);
        os = t + " hours.";
    }
    else                                    //Just Hours
        os = to_string(timeInMinutes / 60) + " hours."; 

    return os;
}