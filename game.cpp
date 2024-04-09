#include "game.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;
using std::getline;

Game::Game()
{
    board = new Board();
    player = new Player();

    cout << "You can use the following commands to play the game:\n" << endl;
    cout << "load <g>\n    g - number of gameboard to load" << endl;
    cout << "init <x>,<y>,<diretion>\n    x: horizontal position of the car on the board" << endl;
    cout << "    y: vertical position of the car on the board" << endl;
    cout << "    direction: direction of the car's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit\n" << endl;

    board->pBoard();
    cout<< endl;
}

Game::~Game()
{
    delete board;
    delete player;
}


void Game::start()
{
    //TODO
    
}

bool Game::loadBoard()
{
    int bn;
    cout << "Please enter the board number to load: ";
    cin >> bn;
    this->board->load(bn);
    return true;
}

void Game::loadBoardNumber(int x)
{
    //TODO
    this->board->load(x);
}

int Game::intPlayer(int x, int y, Direction z)
{
    Position pos(x,y);
    bool playerSet = false;
    if(z == NORTH)
    {    
        (*player).initialisePlayer(&pos,NORTH);
        playerSet = true;
    }
    else if(z == EAST)
    {
        (*player).initialisePlayer(&pos,EAST);
        playerSet = true;
    }
    else if(z == SOUTH)
    {
        (*player).initialisePlayer(&pos,SOUTH);
        playerSet = true;
    }
    else if(z == WEST)
    {
        (*player).initialisePlayer(&pos,WEST);
        playerSet = true;
    }

    if (playerSet){
        (*board).placePlayer(pos);
        (*board).display(player);
        
    }
    return playerSet;
    
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{
    //TODO
}

void Game::initPlayerLoop(string& command){
    //first load ensures that the board has been loaded at least once
    bool firstLoad = false;
    cout << "You can use the following commands to play the game:" << endl;
    cout << " load <g>" << endl;
    if (firstLoad){
        cout << " init <x>,<y>,<direction>" << endl;
    }
    cout << " quit" << endl;
    cout << "Enter your choice: ";
    string startPos;
    Helper::readInput(command);
    cout << endl;
    vector<string> startPosVec;                    
    ///*
    Helper::splitString(command, startPosVec, " ");
    //cout << "splitString worked" << endl;
    bool valid1 = true;
    bool valid2 = false;
    while (valid1){
        //cout<< "command was: " <<command<<endl;
        if (startPosVec.size() == 1){
            //cout<< "size 1 command was: " <<command<<endl;
            if (startPosVec[0] == "quit"){
                valid1 = false;
                command = "quit";
                valid2 = true;
            }
        }
        
        else if (startPosVec.size() == 2){
            //cout<< "size 2 command was: " <<command<<endl;
            if (startPosVec[0] == "load"){
                if (Helper::isNumber(startPosVec[1])){
                    //ensuring input is valid
                    if (stoi(startPosVec[1]) == 1 || stoi(startPosVec[1]) == 2){

                        loadBoardNumber(stoi(startPosVec[1]));
                        valid2 = true;
                        firstLoad = true;
                      
                    }
                }
            }
            if (firstLoad){
                
                if (startPosVec[0] == "init"){

                    Helper::splitString(startPosVec[1], startPosVec, ",");
                    if (startPosVec.size() == 3){
                        if (Helper::isNumber(startPosVec[0]) && Helper::isNumber(startPosVec[1])){

                            int x = stoi(startPosVec[0]);
                            int y = stoi(startPosVec[1]);
                            string direction = startPosVec[2];
                            ///*
                            //ensuring direction is valid
                            if (direction == "north" || direction == "east" || direction == "south" || direction == "west"){
                                //ensuring it is a valid position
                                if (board->placePlayer(Position(x,y)) == true){
                                    bool playerSet = false;
                                    
                                    if (direction == "north"){
                                        intPlayer(x,y,NORTH);
                                        playerSet = true;
                                    }
                                    if (direction == "east"){
                                        intPlayer(x,y,EAST);
                                        playerSet = true;
                                        
                                    }
                                    if (direction == "south"){
                                        intPlayer(x,y,SOUTH);
                                        playerSet = true;
                                    }
                                    if (direction == "west"){
                                        intPlayer(x,y,WEST);
                                        playerSet = true;
                                    }
                                    if (playerSet){
                                        valid1 = false;
                                        valid2 = true;
                                    }
                                }
                            }
                                
                        }
                    }
                }
            }

        }
        
        if (valid1 == true){

            if (valid2 == false){
                Helper::printInvalidInput();
                this->board->pBoard();
            }
            
            cout << endl;
            cout << "You can use the following commands to play the game:" << endl;
            cout << " load <g>" << endl;

            if (firstLoad){
                cout << " init <x>,<y>,<direction>" << endl;
            }

            cout << " quit" << endl;
            cout << "Enter your choice: ";
            Helper::readInput(command);
            cout << endl;
            Helper::splitString(command, startPosVec, " ");
            valid2 = false;
        }
    }
}