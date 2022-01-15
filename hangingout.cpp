#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

int wrong = 6;
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
            //cout << tp << "\n";
            j += 1;
        }
        //cout << "Nice";
        myfile.close();
    }  

    for(int z = 1; z < word.length(); z++){
        //cout << lastLine
        lastLine.append("_ ");
        
        //cout << "\n";
        //cout << z;
        //cout << "\n";
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
    cout << "     " + leg1 + leg2 + " | \n";
    cout << "       _|_\n";
    cout << "          \n";
    cout << lastLine + "\n";
    cout << word + "\n";
    if(wrong == 6){
        cout << "GAME OVER\n";
        exit;
    }
    return 0;
}


int main(){
    cout << "Take your guess!";
    cin >> guess;
    chooseWord();
    gameboard();
    return 0;
}