#ifndef PLAYER_H
#define PLAYER_H

#include "helper.h"

/**
 * Some predefined strings that should print out arrows on the terminal...
 */
#define DIRECTION_ARROW_OUTPUT_NORTH "\xe2\x86\x91"
#define DIRECTION_ARROW_OUTPUT_EAST "\xe2\x86\x92"
#define DIRECTION_ARROW_OUTPUT_SOUTH "\xe2\x86\x93"
#define DIRECTION_ARROW_OUTPUT_WEST "\xe2\x86\x90"

enum Direction
{
    NORTH,
    EAST,
	SOUTH,
	WEST
};

enum TurnDirection
{
    TURN_LEFT,
    TURN_RIGHT
};

class Position
{
public:

	int x;
	int y;

	Position();
	Position(int x, int y);
};

class Player
{

public:

	Position position; // x,y coordinates
	Direction direction;
	unsigned moves;

	Player();
	
	/**
	 * Initialise the player - set the position, direction to the provided values
	 * and set moves to 0.
	 */
	void initialisePlayer(Position* position, Direction direction);

	/**
	 * Turn the player's direction according to the direction of the player and the
	 * turn direction.
	 *
	 * Turn right has the following sequence:
	 * North -> East
	 * East -> South
	 * South -> West
	 * West -> North
	 *
	 * Turn left has the following sequence:
	 * North -> West
	 * West -> South
	 * South -> East
	 * East -> North
	 */
	void turnDirection(TurnDirection turnDirection);

	/**
	 * Gets the new position as if the player moved forward from the player's
	 * current position and direction.
	 *
	 * Note the new position can be outside the bounds of the board and could be on
	 * a blocked cell. Also note that you should not modify the current position of
	 * the player.
	 */
	Position getNextForwardPosition();

	/**
	 * Set the player's position to the provided position. Also increment the
	 * moves count.
	 */
	void updatePosition(Position position);

	/**
	 * Prints the direction arrow to the console - based upon the direction set
	 * print one of the "DIRECTION_ARROW_OUTPUT_..." defines above.
	 *
	 * For example to print the north arrow:
	 *     printf(DIRECTION_ARROW_OUTPUT_NORTH);
	 */
	void displayDirection();
};

#endif
