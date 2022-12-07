#include "Utils.hpp"

std::vector<std::string> Utilities::splitString(const std::string &line, const std::string &delimiter)
{
    std::vector<std::string> tokens{};
    size_t nextTokenStart{0};

    while (nextTokenStart < line.size())
    {
        size_t delimiterStart{line.find(delimiter, nextTokenStart)};
        if (delimiterStart == std::string::npos)
            delimiterStart = line.size();
        std::string token{line.substr(nextTokenStart, delimiterStart - nextTokenStart)};
        tokens.push_back(token);
        nextTokenStart = delimiterStart + delimiter.size();
    }
    return tokens;
}
