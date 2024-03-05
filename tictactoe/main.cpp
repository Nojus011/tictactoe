#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char lenta[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int e,s;
char turn = 'X';
bool lygiosios = false;

//Function to show the current status of the gaming board

void display_board(){

    //Rander Game Board LAYOUT

    cout<<"\tŽAIDĖJAS - 1 [X]\t ŽAIDĖJAS - 2 [O]\n\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<lenta[0][0]<<"  | "<<lenta[0][1]<<"  |  "<<lenta[0][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<lenta[1][0]<<"  | "<<lenta[1][1]<<"  |  "<<lenta[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<lenta[2][0]<<"  | "<<lenta[2][1]<<"  |  "<<lenta[2][2]<<" \n";
    cout<<"\t     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tŽAIDĖJO - 1 [X] eile : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tŽAIDĖJO - 2 [O] eile : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: e=0; s=0; break;
        case 2: e=0; s=1; break;
        case 3: e=0; s=2; break;
        case 4: e=1; s=0; break;
        case 5: e=1; s=1; break;
        case 6: e=1; s=2; break;
        case 7: e=2; s=0; break;
        case 8: e=2; s=1; break;
        case 9: e=2; s=2; break;
        default:
            cout<<"Rinkis NORMALIAI";
    }

    if(turn == 'X' && lenta[e][s] != 'X' && lenta[e][s] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        lenta[e][s] = 'X';
        turn = 'O';
    }else if(turn == 'O' && lenta[e][s] != 'X' && lenta[e][s] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        lenta[e][s] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"\033[1;31m\n\tLangelis jau užpildytas!\n\n\033[0m";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(lenta[i][0] == lenta[i][1] && lenta[i][0] == lenta[i][2] || lenta[0][i] == lenta[1][i] && lenta[0][i] == lenta[2][i])
    return false;

    //checking the win for both diagonal

    if(lenta[0][0] == lenta[1][1] && lenta[0][0] == lenta[2][2] || lenta[0][2] == lenta[1][1] && lenta[0][2] == lenta[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(lenta[i][j] != 'X' && lenta[i][j] != 'O')
    return true;

    //Checking the if game already draw
    lygiosios = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\n\n\tT I C K    T A C    T O E  \n\n\n";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && lygiosios == false){
        cout<<"\tLaimėjo Žaidėjas 2 'O'!";
    }
    else if(turn == 'O' && lygiosios == false){
        cout<<"\tLaimėjo Žaidėjas 1 'X'!";
    }
    else
    cout<<"LYGIOSIOS!";
} 