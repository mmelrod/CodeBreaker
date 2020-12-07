#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Tell game story
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room... \n";
    std::cout << "You need to enter the correct codes to continue... \n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Tell players the sum and product of the three numbers
    std::cout << "+ There are three numbers in the code \n";
    std::cout << "+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply together into: " << CodeProduct << "\n";

    //Store player guess
    int PlayerGuessA, PlayerGuessB, PlayerGuessC;
    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

    int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    //Check player guess
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou got it!";
        return true;
    }
    else
    {
        std::cout << "\nYou got the code wrong, try again!";
        return false;
    }
}

int main()
{    
    srand(time(NULL)); //create new random seed based on current real world time
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //loop game until 5 levels are beaten
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears errors
        std::cin.ignore(); //Discards buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "You beat the game!";
    return 0;
}