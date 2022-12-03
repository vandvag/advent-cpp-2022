#include "Day02.hpp"

Day02::Day02()
{
    std::ifstream file("../inputs/day02.in");
    std::string line{};
    while (std::getline(file, line))
    {
        rounds.push_back(line);
    }
}

void Day02::printSolutions()
{
    std::cout << "Part 1: " << part1() << "\n";
    std::cout << "Part 2: " << part2() << "\n";
}

int Day02::part1()
{
    int totalScore{0};
    for (const std::string &round : rounds)
    {
        std::vector<char> movesAsChar{roundStringToChars(round)};
        Move myMove{myCharToMove[movesAsChar[1]]};
        Move opponentMove{opponentCharToMove[movesAsChar[0]]};
        Result roundResult{calculateResult(myMove, opponentMove)};
        totalScore += calculateRoundScore(myMove, roundResult);
    }
    return totalScore;
}

Day02::Result Day02::calculateResult(Move myMove, Move opponentMove)
{
    if (myMove == opponentMove)
    {
        return Tie;
    }
    if (moveLosesToMove[myMove] == opponentMove)
    {
        return Loss;
    }
    else
    {
        return Win;
    }
}

int Day02::calculateRoundScore(Move myMove, Result roundResult)
{
    return myMove + roundResult;
}

int Day02::part2()
{
    int totalScore{0};
    for (const std::string &round : rounds)
    {
        std::vector<char> roundToChars{roundStringToChars(round)};
        Move opponentMove{opponentCharToMove[roundToChars[0]]};
        Result roundResult{elfCharToResult[roundToChars[1]]};
        Move myMove{getMoveFromResult(opponentMove, roundResult)};
        totalScore += calculateRoundScore(myMove, roundResult);
    }

    return totalScore;
}

std::vector<char> Day02::roundStringToChars(std::string roundString)
{

    std::stringstream roundStream{roundString};
    std::vector<char> movesAsChar{};
    char temp;
    while (roundStream >> temp)
    {
        movesAsChar.push_back(temp);
    }
    return movesAsChar;
}

Day02::Move Day02::getMoveFromResult(Move opponentMove, Result roundResult)
{
    switch (roundResult)
    {
    case Win:
        return moveLosesToMove[opponentMove];
    case Tie:
        return opponentMove;
    case Loss:
        return moveLosesToMove[moveLosesToMove[opponentMove]];
    }
}