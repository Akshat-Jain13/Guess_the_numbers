#include <iostream>
#include <ctime>
using namespace std;

void Printintroduction(int Difficulty)
{
    cout << "\nThe game starts for level "<< Difficulty;
    cout << "\nFind 3 numbers...\n";
}

bool Playgame(int Difficulty)
{
    Printintroduction(Difficulty);

    const int CodeA=rand() % Difficulty+Difficulty;
    const int CodeB=rand() % Difficulty+Difficulty;
    const int CodeC=rand() % Difficulty+Difficulty;
    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProduct=CodeA*CodeB*CodeC;
    cout <<"The sum of the numbers: " << CodeSum << endl;
    cout << "The product of the numbers: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;
    cout << "You have entered: " << GuessA  << GuessB  << GuessC;

    int GuessSum, GuessProduct;
    GuessSum=GuessA+GuessB+GuessC;
    GuessProduct=GuessA*GuessB*GuessC;

    if (GuessSum==CodeSum && GuessProduct==CodeProduct) 
    {
        cout << "\nYou win!\n";
        return true;
    }    
    else
    {
        cout << "\nYou lose!\n";
        return false;
    }    
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    int LevelDifficulty=1;
    const int MaxLevel=3;
    while(LevelDifficulty <= MaxLevel)
    {
        bool blevelcompeleted=Playgame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (blevelcompeleted){
            ++LevelDifficulty;
        }
    }
    cout << "Game completed!!!\n";    
    return 0;
}