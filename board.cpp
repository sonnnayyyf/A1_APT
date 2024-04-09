#include "board.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    boardDimension = new int(11);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));
    //cout << "This is boardGame ref in class::board init: "<< board << endl;
    //cout << this->board << endl;
    for (int i = 0; i<*boardDimension; i++) {
        for (int j = 0; j<*boardDimension; j++) {
            
            //boardGame[i][j] = emp;
            if (i == 0 && j == 0){
                (*board)[i][j] = BLOCKED;
            }
            else if (i == 0) {
                (*board)[i][j] = BLOCKED;
            }
            else if (i!= 0 && j == 0) {
                (*board)[i][j] = BLOCKED;
            }
            else {
                (*board)[i][j] = EMPTY;
            }
            //cout << (*board)[i][j] << " ";
        }
        //cout << endl;
    }
}

Board::~Board()
{
    // TODO
}

void Board::load(int boardId)
{
    // deleting previous board and boardDimension
    delete board;
    delete boardDimension;

    // creating new board and boardDimension 
    boardDimension = new int(11);
    board = new vector<vector<Cell>>(*boardDimension, vector<Cell>(*boardDimension, EMPTY));
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    
    //ensuring the number rows/columns cant be accessed by car
    for (int i = 0; i<*boardDimension; i++){
        for (int j = 0; j<1; j++){
            (*board)[i][j] = BLOCKED;
        }
    }
    for (int i = 0; i <1; i++){
        for (int j = 0; j<*boardDimension; j++){
            (*board)[i][j] = BLOCKED;
        }
    }

    //assigning roadblocks based on boardId
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
            if (boardId == 1) {
                if (BOARD_1[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";

                    (*board)[i][j] = BLOCKED;
                }
                else {
                boardGameStr[i][j] = " |";
                }
                
            }
            else if (boardId == 2) {
                if (BOARD_2[i-1][j-1] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                    (*board)[i][j] = BLOCKED;
                }
                else {
                boardGameStr[i][j] = " |";
                }
            
            }
            else {
                cout << "Invalid board ID" << endl;
                //exit(1);
            }
         
        }

    }
    //printing a board with no player
    pBoard();

}

bool Board::placePlayer(Position position)
{
    // TODO
    return false; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

void Board::display(Player* player)
{
    // TODO
}

void Board::pBoard(){
    //works the same as display but does not display the player
    string boardGameStr[*boardDimension][*boardDimension] = { " " };
    
    for (int i =1; i<*boardDimension; i++) {
        for (int j = 1; j<*boardDimension; j++) {
                if ((*board)[i][j] == BLOCKED) {
                    boardGameStr[i][j] = "*|";
                }
                else if ((*board)[i][j] != PLAYER) {
                    boardGameStr[i][j] = " |";
                }
         
        }

    }

    for (int s=0; s<*boardDimension; s++) {
        for (int t=0; t<*boardDimension; t++) {
            if (s == 0 && t == 0){
                boardGameStr[s][t] = "| |";
            }
            else if (s == 0) {
                if (t>10){
                    boardGameStr[s][t] = std::to_string(t-11)+"|";
                }
                else{
                boardGameStr[s][t] = std::to_string(t-1)+"|";
                }
            }
            else if (s != 0 && t == 0) {
                if (s>10){
                    boardGameStr[s][t] = "|"+ std::to_string(s-11)+"|";
                    }
                else{
                    boardGameStr[s][t] = "|"+ std::to_string(s-1)+"|";
                    }
            }
            
            cout << boardGameStr[s][t];
        }
        cout << endl;
    }
}
