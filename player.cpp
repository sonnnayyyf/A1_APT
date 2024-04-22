#include "player.h"

Position::Position()
{
    //TODO
}


Position::Position(int x, int y)
{
    this->x = x+1;
    this->y = y+1;
}

Player::Player()
{
    this->position = Position();
    this->moves = 0;
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    this->position = *position;
    this->direction = direction;
    this->moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    if (turnDirection == TURN_LEFT){
        
        if (this->direction == NORTH){
            this->direction = WEST;
        }
        else if (this->direction == WEST){
            this->direction = SOUTH;
        }
        else if (this->direction == SOUTH){
            this->direction = EAST;
        }
        else if (this->direction == EAST){
            this->direction = NORTH;
        }
    }
    else{
        //cout<< "turn right" << endl;
        if (this->direction == NORTH){
            this->direction = EAST;
        }
        else if (this->direction == EAST){
            this->direction = SOUTH;
        }
        else if (this->direction == SOUTH){
            this->direction = WEST;
        }
        else if (this->direction == WEST){
            this->direction = NORTH;
        }
    }
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    this->position = position;
    this->moves++;
}

void Player::displayDirection()
{
    //TODO
}
