#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


struct Round
{
    int reds;
    int greens;
    int blues;

    Round(int r, int g, int b) : reds(r), greens(g), blues(b) {}
};

struct Game
{
    int ID;
    std::vector<Round> rounds;

    Game(int id, std::vector<Round> r) : ID(id), rounds(r) {}
};

Round parseRound(std::string round)
{
    // Format: ' 4 blue, 4 red, 16 green'
    std::stringstream ss(round);
    std::string pair;
    int reds = 0;
    int greens = 0;
    int blues = 0;
    while (std::getline(ss, pair, ',')) // Get ' <count> <color>' pair
    {
        std::stringstream ss2(pair);
        std::string token;
        std::getline(ss2, token, ' '); // Skip leading space
        std::getline(ss2, token, ' '); // Get count
        int count = std::stoi(token);

        std::getline(ss2, token, ' '); // Get color
        if (token == "red")
            reds = count;
        else if (token == "green")
            greens = count;
        else if (token == "blue")
            blues = count;
    }
    return Round(reds, greens, blues);
}

int main(int argc, char** argv)
{
    std::ifstream file("input.txt", std::ios::in);
    std::string line;
    std::string token;
    std::stringstream ss;
    std::vector<Game> games;
    int lineCount = 0;
    while (std::getline(file, line))
    {
        ss.str(line);
        std::getline(ss, token, ':'); // Skip game ID

        // Get all rounds
        std::vector<Round> rounds;
        while (std::getline(ss, token, ';'))
        {
            Round r = parseRound(token);
            rounds.push_back(r);
        }

        // Add game to list
        Game game = Game(++lineCount, rounds);
        games.push_back(game);

        ss.clear();
    }
    file.close();

    long sum = 0;
    for (Game game : games)
    {
        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;
        for (Round round : game.rounds)
        {
            maxRed = maxRed > round.reds ? maxRed : round.reds;
            maxGreen = maxGreen > round.greens ? maxGreen : round.greens;
            maxBlue = maxBlue > round.blues ? maxBlue : round.blues;
        }
        sum += maxRed*maxGreen*maxBlue;
    }
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}