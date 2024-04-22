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

    cout << "\nYou can use the following commands to play the game:\n" << endl;
    cout << "load <g>\n    g - number of gameboard to load" << endl;
    cout << "init <x>,<y>,<diretion>\n    x: horizontal position of the car on the board" << endl;
    cout << "    y: vertical position of the car on the board" << endl;
    cout << "    direction: direction of the car's movement (north, east, south, west)" << endl;
    cout << "generate <d>,<p>" << endl;
    cout << "    d: the dimension of the game board to be generated" << endl;
    cout << "    p: the probability of the blocks on board to be generated randomly" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit\n" << endl;

    Helper::waitForEnter();
    cout<< endl;

    board->pBoard();
    cout<< endl;
}

Game::~Game()
{
    delete board;
    delete player;
}


void Game::start(string& command)
{
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
    Helper::splitString(command, startPosVec, " ");
    bool valid1 = true;
    bool valid2 = false;
    while (valid1){

        if (startPosVec.size() == 1){

            if (startPosVec[0] == "quit"){
                valid1 = false;
                command = "quit";
                valid2 = true;
            }
        }
        
        else if (startPosVec.size() == 2){

            if (startPosVec[0] == "load"){
                if (Helper::isNumber(startPosVec[1])){

                    if (stoi(startPosVec[1]) == 1 || stoi(startPosVec[1]) == 2){

                        loadBoardNumber(stoi(startPosVec[1]));
                        valid2 = true;
                        firstLoad = true;
                      
                    }
                }
            }
            if (firstLoad){
                if (startPosVec[0] == "generate"){
                    Helper::splitString(startPosVec[1], startPosVec, ",");

                    if (startPosVec.size() == 2){
                        
                        if (Helper::isNumber(startPosVec[0])){
                            int x = stoi(startPosVec[0]);
                            
                            if (x <= 20 && x >= 10){
                                string temp = startPosVec[1];
                                Helper::splitString(startPosVec[1], startPosVec, ".");

                                if(startPosVec.size() == 2){
                                    if (startPosVec[0] == "0" && Helper::isNumber(startPosVec[0]) && Helper::isNumber(startPosVec[1])){
                                        double y = stod(temp);
                                        //cout << "y was: " << y << endl;
                                        board->resizeBoard(x,y);
                                        valid2 = true;
                                    }
                                }
                            }

                        }
                    }
                }

                if (startPosVec[0] == "init"){

                    Helper::splitString(startPosVec[1], startPosVec, ",");
                    if (startPosVec.size() == 3){
                        if (Helper::isNumber(startPosVec[0]) && Helper::isNumber(startPosVec[1])){

                            int x = stoi(startPosVec[0]);
                            int y = stoi(startPosVec[1]);
                            string direction = startPosVec[2];

                            if (direction == "north" || direction == "east" || direction == "south" || direction == "west"){

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
                cout << "Enter your choice: ";
                Helper::readInput(command);
                cout << endl;
                Helper::splitString(command, startPosVec, " ");
            }
            else {
                cout << endl;
                cout << "You can use the following commands to play the game:" << endl;
                cout << " load <g>" << endl;
                if (firstLoad){
                    cout << " init <x>,<y>,<direction>" << endl;
                    cout << " generate <d>,<p>" << endl;
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
    return false;
}

void Game::play()
{
    string gamer;
    cout << "\nYou can use the following commands to play the game: " << endl;
    cout << " forward (or f)" << endl;
    cout << " turn_left (or l)" << endl;
    cout << " turn_right (or r)" << endl;
    cout << " quit" << endl;
    cout << "Enter your choice: ";
    Helper::readInput(gamer);

    while (gamer != "quit"){

        if (gamer == "forward" || gamer == "turn_left" || gamer == "turn_right" || gamer == "r" || gamer == "l" || gamer == "f"){
            if (gamer == "turn_left" || gamer == "l"){                
                (*player).turnDirection(TURN_LEFT);
            }
            else if (gamer == "turn_right" || gamer == "r"){                
                (*player).turnDirection(TURN_RIGHT);
            }
            else if (gamer == "forward" || gamer == "f"){
                (*board).movePlayerForward(player);
            }
            cout << endl;
            (*board).display(player);
            
            cout << "\nYou can use the following commands to play the game: " << endl;
            cout << " forward (or f)" << endl;
            cout << " turn_left (or l)" << endl;
            cout << " turn_right (or r)" << endl;
            cout << " quit" << endl;
            cout << "Enter your choice: ";
            Helper::readInput(gamer);
            
        }
        else{
            cout << endl;
            Helper::printInvalidInput();
            cout << "Enter your choice: ";
            Helper::readInput(gamer);
        }
    }
}

int Game::getPlayerMoves(){
    return player->moves;
}