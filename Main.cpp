#include <iostream>

using namespace std;


  //tue : 1
//false : 2
bool plr = true;

//true means value has been stored
bool rightVal[9] = {false, false, false, false, false, false, false, false, false};
char posVal[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int plays = 9;
int position;

char plr1 = 'x';
char plr2 = 'o';

char playerVal = ' ';

bool player(){
    if(plr){
        playerVal = plr1;
        plr = false;
    }else{
        playerVal = plr2;
        plr = true;
    }
    return plr;
}


            //plr = plyr 1 , !plr = plr2
char positionPlacer(bool plr, int playerPosInput, int boardPos){
    if(plr){
        if(playerPosInput == boardPos){
            return plr1;
        }else{
            return ' ';
        }
    }else if (!plr){
        if(playerPosInput == boardPos){
            return plr2;
        }else{
            return ' ';
        }
    }
}

char maintainValue(bool plr, int playerPosInput, int boardPos){
    char val;

    if((!rightVal[playerPosInput]) && playerPosInput == boardPos){
        rightVal[playerPosInput] = true;
        posVal[playerPosInput] = playerVal;
        val = positionPlacer(plr, playerPosInput, boardPos);
    }
    if((rightVal[playerPosInput]) && playerPosInput == boardPos){
        val = posVal[playerPosInput];
    }

    return val;
}


void ticTacToeBoard(bool plr, int play){
    cout << "       | " << "   |    " << endl;
    cout << "   ["<<maintainValue(plr, play, 1) << "]  | ["<<maintainValue(plr, play, 2) << "] | ["<<maintainValue(plr, play, 3) << "]   " << endl;
    cout << "       | " << "   |    " << endl;

    cout <<"  ----------------" << endl;
    cout <<"   ["<<maintainValue(plr, play, 4) << "]    ["<<maintainValue(plr, play, 5) << "]   ["<<maintainValue(plr, play, 6) << "]  " << endl;
    cout <<"  ----------------" << endl;

    cout << "       | " <<  "   |    " << endl;
    cout << "   ["<<maintainValue(plr, play, 7) << "]  | ["<<maintainValue(plr, play, 8) << "] | ["<<maintainValue(plr, play, 9) << "]    " << endl;
    cout << "       | " <<  "   |    " << endl;

}

//run 9 times; stop once all playable positions are filled
void gameLoop(){

    for(int i = 0; i < plays; i++){

        cout << "what is your move? \n";
        cin >> position;

        ticTacToeBoard(player(), position);
    }
}


int main(){

    gameLoop();

    return 0;
}



