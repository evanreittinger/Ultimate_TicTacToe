#include <iostream>

using namespace std;


  //tue : 1
//false : 2
bool plr = true;

int plays = 9;
int position;

char plr1 = 'x';
char plr2 = 'o';

bool player(){
    if(plr)
        plr = false;
    else
        plr = true;
    
    return plr;
}

            //plr = plyr 1 , !plr = plr2
char positionPlacer(bool plr, int playerPosInput, int boardPos){
    if(plr){
        if(playerPosInput == boardPos){
            return ' ';
        }else{
            return plr1;
        }
    }else if (!plr){
        if(playerPosInput == boardPos){
            return ' ';
        }else{
            return plr2;
        }
    }
}


void ticTacToeBoard(bool plr, int play){
    cout << "       | " << "   |    " << endl;
    cout << "   ["<<positionPlacer(plr, play, 1) << "]  | ["<<positionPlacer(plr, play, 2) << "] | ["<<positionPlacer(plr, play, 3) << "]   " << endl;
    cout << "       | " << "   |    " << endl;

    cout <<"  ----------------" << endl;
    cout <<"   ["<<positionPlacer(plr, play, 4) << "]    ["<<positionPlacer(plr, play, 5) << "]   ["<<positionPlacer(plr, play, 6) << "]  " << endl;
    cout <<"  ----------------" << endl;

    cout << "       | " <<  "   |    " << endl;
    cout << "   ["<<positionPlacer(plr, play, 7) << "]  | ["<<positionPlacer(plr, play, 8) << "] | ["<<positionPlacer(plr, play, 9) << "]    " << endl;
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



