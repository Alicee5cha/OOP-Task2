#pragma once

#include <string>
#include <iostream>
#include "date.h"
class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    
    static string getCurrentDate();

    static std::string ToUpperR(std::string s);
    static std::string ToUpperI(std::string s);
    static bool StartsWith(std::string fullText, std::string searchText);
    static int randomInt(int min, int max);
    static string ReturnPlayTime(int timeInMinutes);
};