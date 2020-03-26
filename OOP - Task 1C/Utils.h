#pragma once

#include <string>
#include <iostream>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    
    static std::string ToUpperR(std::string s);
    static std::string ToUpperI(std::string s);
    static bool StartsWith(std::string fullText, std::string searchText);
};