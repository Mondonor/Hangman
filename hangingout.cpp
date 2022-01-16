#include <iostream>
#include <string>
#include <fstream>
//#include <stdlib.h>

using namespace std;

int wrong = 0;
int r;
int j;
string head = " ";
string body = " ";
string arm1 = " ";
string arm2 = " ";
string leg1 = " ";
string leg2 = " ";
string word;
string lastLine = "";
string guess;
bool status = true;
int correctGuesses = 0;
bool guesstemp;

int chooseWord(){
    srand(time(NULL));
    r = rand() % 1000 + 1;

    ifstream myfile;
    myfile.open("hanglib.txt", ios::in);
    string line;
    j = 0;
    if(myfile.is_open()){
        string tp;
        while(getline(myfile,tp)){
            if(j == r){
                word = tp;
                break;
            }
            j += 1;
        }
        myfile.close();
    }  

    for(int z = 1; z < word.length(); z++){
        lastLine.append("_ ");
    }

    return 0;
}

int initialize(){
    head = " ";
    body = " ";
    arm1 = " ";
    arm2 = " ";
    leg1 = " ";
    leg2 = " ";
    return 0;
}

int checkIfRight(){
    for(int z = 0; z < lastLine.length(); z++){
        if(lastLine[z] == '_'){
            return false;
        }
    }
    return true;
}

int gameboard()
{
    if(wrong == 1){
        head = "☺";
    } else if(wrong == 2){
        head = "☺";
        body = "|";
    }else if(wrong == 3){
        head = "☺";
        body = "|";
        arm1 = "-";
    }else if(wrong == 4){
        head = "☺";
        body = "|";
        arm1 = "-";
        arm2 = "-";
    }else if(wrong == 5){
        head = "☺";
        body = "|";
        arm1 = "-";
        arm2 = "-";
        leg1 = "/";
    }else if(wrong == 6){
        head = "☺";
        body = "|";
        arm1 = "-";
        arm2 = "-";
        leg1 = "/";
        leg2 = "\\";
    }
    cout << "     ___  \n";
    cout << "     |  | \n";
    cout << "     " + head + "  | \n";
    cout << "    " + arm1 + body + arm2 + " | \n";
    cout << "    " + leg1 + " " + leg2 + " | \n";
    cout << "       _|_\n";
    cout << "          \n";
    cout << lastLine + "\n";

    if(wrong == 6){
        cout << "GAME OVER\n";
        cout << "The word was: ";
        cout << word;
        cout << "\n";
        status = false;
    } 
    if(checkIfRight()){
        cout << "YOU WIN!\n";
        status = false;
    };
    return 0;
}


int main(){
    chooseWord();
    gameboard();
    while(status == true){
        cout << "\nTake Your Guess: ";
        cin >> guess;
        for(int z = 0; z < word.length(); z++){
            if(word[z] == guess[0]){
                lastLine[2*z] = word[z];
                guesstemp = true;
            }
        }
        if(guesstemp == true){
            correctGuesses += 1;
            guesstemp = false;
        } else {
            wrong += 1;
        }
        guesstemp = false;
        gameboard();
    }
    //cout << "Reached end";
    return 0;
}