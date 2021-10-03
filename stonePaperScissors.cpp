#include <iostream>

using namespace std;

// Constant variables

const char STONE = 'S';
const char PAPER = 'P';
const char SCISSORS = 'X';


char getComputerOptions()
{
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if (num == 1){
        return 'S';
    }
    if (num == 2){
        return 'P';
    }
    if (num == 3){
        return 'X';
    }
    
    return 0;
}

char getUserOptions()
{
    char c;
    cout << "\n\n\t\t\t\tStone, Paper and Scissors Game!" << endl;
    cout << "\n\t\t\t\tChoose one of the following options" << endl;
    cout << "\n\t\t-------------------------------------------------------------" << endl;
    cout << "'S' -> for Stone " << endl  << "'P' -> for Paper" << endl << "'X' -> for scissors " << endl;
    cin >> c;

    while (c != 'S' && c != 'P' && c != 'X')
    {
        cout << "Please enter one of the following options only: " << endl; 
        cout << "(S) for stone " << endl << "(P) for paper" << endl<< "(X) for scissors " << endl;
        cin >> c;
    }

    return c;
}

void showSelectedOption(char option)
{
    if (option == 'S'){
        cout << "Stone" << endl;
    }
    if (option == 'P'){
        cout << "Paper" << endl;
    }
    if (option == 'X'){
        cout << "Scissors" << endl;
    }
}

void chooseWinner(char uChoice, char cChoice)
{
    if (uChoice == STONE && cChoice == PAPER)
    {
        cout << "Computer Wins! Paper wraps stone." << endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS)
    {
        cout << "Computer Wins! Scissors cut Paper." << endl;
    }
    else if (uChoice == SCISSORS && cChoice == STONE)
    {
        cout << "Computer Wins! stone smashes Scissors." << endl;
    }
    else if (uChoice == STONE && cChoice == SCISSORS)
    {
        cout << "You Win! Paper wraps stone." << endl;
    }
    else if (uChoice == PAPER && cChoice == STONE)
    {
        cout << "You Win! Paper wraps stone." << endl;
    }
    else if (uChoice == SCISSORS && cChoice == PAPER)
    {
        cout << "You Win! Scissors cut Paper." << endl;
    }
    else
    {
        cout << "Tie. Play again win the Game." << endl;
    }
}

int main()
{
    //User's choice
    char yourChoice;
    //Compter's choice
    char computerChoice;

    yourChoice = getUserOptions();
    cout << "Your choice is: " << endl;
    showSelectedOption(yourChoice);

    cout << "Computer's choice is: " << endl;
    computerChoice = getComputerOptions();
    showSelectedOption(computerChoice);

    chooseWinner(yourChoice, computerChoice);

    return 0;
}
