#include "game.h"
#include "helper.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;
using std::getline;

Game::Game()
{
    // TODO
}

Game::~Game()
{
    board = new Board();
    player = new Player();

    cout << "You can use the following commands to play the game:\n" << endl;
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
    // board->pBoard();
    cout<< endl;
}


void Game::start()
{
    //TODO
    cout << "I am cool" << endl;
}

bool Game::loadBoard()
{
    //TODO
    return false; // feel free to revise this line, depending on your implementation.
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