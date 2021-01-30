//This is a c++ CLI game.
#include <iostream>
#include <ctime>
//preprocessor directive

void printIntroduction(int Difficulty)
{
    std::cout << "You are a super duper robber breaking into a level " << Difficulty;
    std::cout << " secure vault trying to obtain the skull diamond..\nEnter the correct Code to continue..." << "\n";
    //expression statements
}

bool playGame(int Difficulty) 
//Void functions will not return any values.
{

    printIntroduction(Difficulty);
    const int CodeA = rand() % (Difficulty + Difficulty);
    int CodeB = rand() % (Difficulty + Difficulty);
    int CodeC = rand() % (Difficulty + Difficulty);
    //declaration statements

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;

    std::cout << "There are 3 numbers in the Code" << "\n";
    std::cout << "The Codes add up to " << CodeSum << "\n";
    std::cout << "The Codes multiply to give " << CodeProduct << "\n";
    
    std::cout << "Enter the secret Code: ";
    
    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

  
    //check if player Guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "Correct!\n";
        return true;
    } else {
        std::cout << "The answer is incorrect, try again!" << "\n";
        return false;
    }
}


int main() //main function
{
    srand(time(NULL)); //seeding rand number based on time of day.
    int LevelDifficulty = 1;
    int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = playGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete) {
            ++LevelDifficulty;
            //increase level difficulty
        } 
    }
    
    return 0;
    //return statement
}

