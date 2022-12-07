#include "Day06.hpp"

Day06::Day06()
{
    std::ifstream file("../inputs/day06.in");

    std::string line{};
    while (std::getline(file, line))
    {
        signal = line;
    }
}

bool Day06::is_unique(const std::deque<char> &buffer) const
{
    std::unordered_set<char> bufferSet{buffer.begin(), buffer.end()};
    return buffer.size() == bufferSet.size();
}

int Day06::part1(const int startOfMessageMarker) const
{
    std::deque<char> buffer{};
    for (int i = 0; i < signal.size(); i++)
    {
        if (i < startOfMessageMarker)
        {
            buffer.push_back(signal[i]);
            continue;
        }
        if (is_unique(buffer))
        {
            return i;
        }
        buffer.pop_front();
        buffer.push_back(signal[i]);
    }
    return -1;
}

void Day06::printSolutions()
{
    std::cout << "Part 1: " << part1(4) << "\n";
    std::cout << "Part 2: " << part1(14) << "\n";
}
