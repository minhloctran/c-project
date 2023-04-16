/*

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

//functions
double betTheHouse(double &cash, double bet, int num, int houseNum, string name);
int houseBet();
bool playAgain(bool &continuePlay);
int validation(int);

int main(){

    double credits, wager;
    int guess;
    bool playMore = true;
    string name;


    cout << "Hello! Welcome to the C Plus Plus Casino where prizes are more than just parameters.\n\n";
    cout << "What is your name?\n";

    getline(cin, name);

    cout << "\n\nHow many credits would you like to deposit into you account today, " << name << "?\n";

    cin >> credits;
    // Validation step
    validation(credits); 
    

    cout << "\n\nThank your for depositing $" << credits << " in credits.\nEnjoy your betting experience!\n\n";
    

    for(int i = 0; (credits > 0) && (playMore == true); ++i){

        cout << "How many credits would you like to bet?\n";
        cin >> wager;
        // Validation step
        validation(wager); 
        // If wager is more than credits
        if(wager > credits) {
            cout << "You have insufficient credits for that bet.\n";
            // Sends the program back to the beginning of the for loop
            continue;
        }

        cout <<"\n\nWhat number would you like to place your bet on?\n";
        cin >> guess;
        int houseGuess = houseBet();

        credits = betTheHouse(credits, wager, guess, houseGuess, name);

        if(credits > 0){
            playMore = playAgain(playMore);
        }
        else if(credits <= 0){
            break;
        }
    }

    return 0;
}

double betTheHouse(double &cash, double bet, int num, int houseNum, string title){

    if(houseNum == num){
        cash = (cash - bet) + (bet * 10);
        cout << "\nCongratulations! You've beaten the house.Your bet was on '" << num;
        cout << "' and we rolled '" << houseNum << "'.\nYou've won $" << (bet * 10);
        cout << "\nAnd your new balance is $" << cash << endl;
    }
    else if(houseNum != num){
        cash = (cash - bet);
        cout << "\nWe're sorry. You bet your money on '" << num;
        cout << "' and we rolled '" << houseNum << "'.\nYou've lost this bet...\n";

        if(cash <= 0){
            cout << "\nWe're sorry to inform you that you've run out of money...\n";
            cout << "We hope you've enjoyed your time with us, " << title << ".\n";
        }
        else {
            cout << "\nYour new balance is $" <<  cash << endl;
        }
    }
    else {
        cash = cash;
        cout << "\nIt seems like we wont take this bet. Feel free to bet again!\n";
    }

    return cash;
}

int houseBet(){

    int houseValue;
    srand(time(0));
    houseValue = rand()%10;

    return houseValue;
}

bool playAgain(bool &continuePlay){

    char continueChar;

    while(continuePlay == true) {
        cout << "Would you like to place another bet? (y/n)\n";
        cin >> continueChar;

        if (continueChar == 'y') {
            continuePlay = true;
            return continuePlay;
        }
        if (continueChar == 'n') {
            continuePlay = false;
        }
        if (continueChar != 'y' && continueChar != 'n') {
            cout << "Incorrect character.\n";
            continue;
        }

    }
  return true; //FIX ME Please
}

//Validation function
int validation(int input) 
{

  
  while (1)
  {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "You have entered it wrong.Please re-enter: ";
      cin >> input;
    }
    if (!cin.fail())
      break;
  }
  return input;
}




