#ifndef PLAYER_H
#define PLAYER_H

#import "mage.h"

class Player: public mg::Sprite {
  public:
    Player() : mg::Sprite(100.0, 100.0) {};

    virtual void update(GLdouble dt);
    virtual void draw(GLdouble dt) const;
};

#endif