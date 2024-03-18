#ifndef BOARD_H
#define BOARD_H

#include "helper.h"
#include "player.h"

#define DEFAULT_BOARD_DIMENSION 10

// strings for displaying the board.
#define EMPTY_OUTPUT " "
#define BLOCKED_OUTPUT "*"
#define LINE_OUTPUT "|"


enum Cell
{
	EMPTY,
	BLOCKED,
	PLAYER
};

enum PlayerMove
{
    PLAYER_MOVED,
    CELL_BLOCKED,
    OUTSIDE_BOUNDS
};

class Board
{

    // Two default board configurations
    const static std::vector<std::vector<Cell>> BOARD_1;
    const static std::vector<std::vector<Cell>> BOARD_2;

private:
    std::vector<std::vector<Cell>>* board;

public:

    /**
     * Initilize and destory a 10*10 board
     */
    Board();
    ~Board();
    /**
     * Load the board to either BOARD_1 or BOARD_2 according to user input.
     */
    void load(int boardId);

    /**
     * Try to place the PLAYER cell at the provided position.
     *
     * Note that if the position is outside the bounds of the board or if the cell
     * at the provided position is BLOCKED then you should return FALSE.
     *
     * Return TRUE when the cell at the position is successfully set to PLAYER.
     */
    bool placePlayer(Position position);

    /**
     * Try to move the player forward - note the player has a current direction and
     * position.
     *
     * You should call "getNextForwardPosition(...)" to get the position as if the
     * player did move.
     *
     * If this new position is outside the bounds of the board return
     * OUTSIDE_BOUNDS. If the new position is on-top of a BLOCKED cell then
     * return CELL_BLOCKED.
     *
     * Note that if either of these error cases occur then the board cells and
     * player position are not modified.
     *
     * Lastly if the new position is EMPTY then remove PLAYER from the current
     * player's position on the board (set cell to EMPTY) and set the new position
     * to PLAYER. And call "updatePosition(...)" to update the player's position
     * then return PLAYER_MOVED.
     */
    PlayerMove movePlayerForward(Player* player);

    /**
     * Display the board according to the specification. Take note when encountering
     * the PLAYER cell and that you should call "displayDirection(...)" function to
     * display the arrow. Here is an example output (without the player arrow):

    
    | |0|1|2|3|4|5|6|7|8|9| 
    |0| | | | | | | | | | | 
    |1| | | | | | | | | | | 
    |2|*|*|*| | |*| | | | | 
    |3| | |*| | | |*|*| | | 
    |4| | |*| | | | | | | | 
    |5| | | | | | |*| | | | 
    |6| | | | | | |*| | | | 
    |7| | |*| | | |*| | | | 
    |8| | |*| | | | | | | | 
    |9| | |*| | | | | | | | 


    */
    void display(Player* player);
};



#endif
