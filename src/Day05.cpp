#include "Day05.hpp"

Day05::Day05()
{
    std::ifstream file{"../inputs/day05.in"};
    std::regex commandsPattern("move ([\\d]+) from ([\\d]+) to ([\\d]+)");
    if (!file.is_open())
    {
        std::cout << "File could not be opened!\n";
        std::exit(1);
    }

    std::string currentLine{};
    std::vector<std::string> boxStacksAsStrings{};
    bool readingCommands{false};

    while (std::getline(file, currentLine))
    {
        // That's where we split from the crane to the commands
        if (currentLine == "")
        {
            readingCommands = true;
            continue;
        }

        if (readingCommands)
        {
            std::smatch sm{};
            std::vector<int> command;
            std::regex_search(currentLine, sm, commandsPattern);
            for (int i = 1; i < sm.size(); i++)
            {
                command.push_back(std::stoi(sm[i]));
            }
            commands.push_back(command);
        }
        else
        {
            boxStacksAsStrings.push_back(currentLine);
        }
    }

    getStacksFromStrings(boxStacksAsStrings);
}

void Day05::getStacksFromStrings(std::vector<std::string> &boxStacksAsStrings)
{
    int numOfStacks{0};
    for (auto it = boxStacksAsStrings.rbegin(); it != boxStacksAsStrings.rend(); it++)
    {
        // Beginning of the string, define the number of stacks
        if (it == boxStacksAsStrings.rbegin())
        {
            for (int i = 0; i < it->size(); i++)
            {
                if (std::isdigit(it->at(i)))
                {
                    int num = int(it->at(i) - '0');
                    numOfStacks = num;
                }
            }
            for (int i = 0; i < numOfStacks; i++)
            {
                stacks.push_back(std::stack<char>{});
            }
        }
        else
        {
            for (int i = 0; i < it->size(); i++)
            {
                if ((i - 1) % 4 == 0 && int(it->at(i) - 'A') >= 0 && int(it->at(i) - 'A' <= 26))
                    stacks.at((i - 1) / 4).push(it->at(i));
            }
        }
    }
}

void Day05::part1(std::vector<std::stack<char>> stacks)
{
    for (const std::vector<int> &command : commands)
    {
        std::queue<char> tempQueue{};
        for (int i = 0; i < command[0]; i++)
        {
            tempQueue.push(stacks[command[1] - 1].top());
            stacks[command[1] - 1].pop();
        }
        while (!tempQueue.empty())
        {
            stacks[command[2] - 1].push(tempQueue.front());
            tempQueue.pop();
        }
    }

    for (auto it = stacks.begin(); it != stacks.end(); it++)
    {
        std::cout << it->top();
    }
    std::cout << "\n";
}

void Day05::part2(std::vector<std::stack<char>> stacks)
{
    for (const std::vector<int> &command : commands)
    {
        std::stack<char> tempStack{};
        for (int i = 0; i < command[0]; i++)
        {
            tempStack.push(stacks[command[1] - 1].top());
            stacks[command[1] - 1].pop();
        }
        while (!tempStack.empty())
        {
            stacks[command[2] - 1].push(tempStack.top());
            tempStack.pop();
        }
    }

    for (auto it = stacks.begin(); it != stacks.end(); it++)
    {
        std::cout << it->top();
    }
    std::cout << "\n";
}

void Day05::printSolutions()
{
    std::cout << "Part 1: ";
    part1(stacks);
    std::cout << "Part 2: ";
    part2(stacks);
}
