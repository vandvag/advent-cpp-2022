#ifndef DAY02_HPP
#define DAY02_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

class Day02
{
private:
    std::vector<std::string> rounds;
    int part1();
    int part2();
    std::vector<char> roundStringToChars(std::string roundString);
    enum Move
    {
        Rock = 1,
        Paper = 2,
        Scisors = 3,
    };
    enum Result
    {
        Win = 6,
        Tie = 3,
        Loss = 0,
    };
    std::unordered_map<char, Move> opponentCharToMove{
        {'A', Rock},
        {'B', Paper},
        {'C', Scisors},
    };
    std::unordered_map<char, Move> myCharToMove{
        {'X', Rock},
        {'Y', Paper},
        {'Z', Scisors},
    };
    std::unordered_map<char, Result> elfCharToResult{
        {'X', Loss},
        {'Y', Tie},
        {'Z', Win},
    };
    std::unordered_map<Move, Move> moveLosesToMove{
        {Rock, Paper},
        {Paper, Scisors},
        {Scisors, Rock},
    };
    Result calculateResult(Move myMove, Move opponentMove);
    int calculateRoundScore(Move myMove, Result roundResult);
    Move getMoveFromResult(Move opponentMove, Result roundResult);

public:
    Day02();
    void printSolutions();
};

#endif